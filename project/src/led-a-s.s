	.arch msp430g2553
	.p2align 1,0
	.text

	.global alternate_leds
	.extern P1OUT

leds_on:
 	cmp #500, r12		;blink_count - 500
 	jnc red_on_green_off	;blink_count - 500 < 0 iff borrow (no-carry)
 	bis.b #65, &P1OUT	;bit set P1OUT |= 0100 0001 
 	pop r0			;return

red_on_green_off:
	cmp #250, r12		;blink_count - 250
	jnc green_on_red_off	;blink_count - 250 <0 iff borrow (no-carry)
	bis.b #64, &P1OUT	;bit set P1OUT |= 0100 0000 (red on)
	and.b #~1, &P1OUT	;bit clear P1OUT &= 1111 1110 (green off)
	pop r0		
	
green_on_red_off:	
	cmp #125, r12		;blink_count - 125
	jnc out			;blink_count - 125 - 0 iff borrow (no-carry)
	bis.b #1, &P1OUT	;bit set P1OUT |= 0000 0001 (green on)
	and.b #~64, &P1OUT	;bit clear P1OUT &= 1011 1111 (red off)	
	pop r0			;return

out:
	pop r0
	
