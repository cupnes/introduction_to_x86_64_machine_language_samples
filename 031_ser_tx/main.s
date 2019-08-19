/*
	mov	$0x03fa, %dx
	mov	$0x07, %al
	out	%al, (%dx)
*/

/*
   0:   66 ba f8 03             mov    $0x3f8,%dx
   4:   b0 41                   mov    $0x41,%al
   6:   ee                      out    %al,(%dx)
   7:   eb f7                   jmp    0x0
*/
loop:
	mov	$0x03f8, %dx
	mov	$0x41, %al
	out	%al, (%dx)
	jmp	loop
