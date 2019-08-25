struct pixelformat {
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char _reserved;
};

struct framebuffer {
	struct pixelformat *base;
	unsigned long long size;
	unsigned int hr;
	unsigned int vr;
};

/*
(qemu) x/20i 0x110000
0x0000000000110000:  push   %rbp
0x0000000000110001:  mov    %rsp,%rbp
0x0000000000110004:  mov    %rdi,-0x8(%rbp)
0x0000000000110008:  mov    %rsi,-0x10(%rbp)
0x000000000011000c:  mov    %rdx,-0x18(%rbp)
0x0000000000110010:  mov    -0x10(%rbp),%rax
0x0000000000110014:  mov    (%rax),%rax
0x0000000000110017:  movl   $0xffffff,(%rax)
0x000000000011001d:  jmp    0x11001d
0x000000000011001f:  nop
0x0000000000110020:  adc    $0x0,%al
0x0000000000110022:  add    %al,(%rax)
0x0000000000110024:  add    %al,(%rax)
0x0000000000110026:  add    %al,(%rax)
0x0000000000110028:  add    %edi,0x52(%rdx)
0x000000000011002b:  add    %al,(%rcx)
0x000000000011002d:  js     0x11003f
0x000000000011002f:  add    %ebx,(%rbx)
0x0000000000110031:  or     $0x7,%al
0x0000000000110033:  or     %dl,0x1c000001(%rax)
(qemu) x/wx 0xc0000000
00000000c0000000: 0x00ffffff
(qemu)
*/

/*
   0:   55                      push   %rbp
   1:   48 89 e5                mov    %rsp,%rbp
   4:   48 89 7d f8             mov    %rdi,-0x8(%rbp)
   8:   48 89 75 f0             mov    %rsi,-0x10(%rbp)
   c:   48 89 55 e8             mov    %rdx,-0x18(%rbp)
  10:   48 8b 45 f0             mov    -0x10(%rbp),%rax
  14:   48 8b 00                mov    (%rax),%rax
  17:   c7 00 ff ff ff 00       movl   $0xffffff,(%rax)
  1d:   eb fe                   jmp    0x1d
*/

void start_kernel(void *_t __attribute__ ((unused)), struct framebuffer *fb,
		  void *_fs_start __attribute__ ((unused)))
{
	/* struct pixelformat *px = fb->base; */

	/* px->b = 0x00; */
	/* px->g = 0xff; */
	/* px->r = 0x00; */
	/* px->_reserved = 0x00; */

	*(unsigned int *)(fb->base) = 0x00ffffff;

	while (1);
}
