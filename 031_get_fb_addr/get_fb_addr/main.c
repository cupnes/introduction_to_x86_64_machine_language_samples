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
0x0000000000110004:  mov    %rdi,-0x18(%rbp)
0x0000000000110008:  mov    %rsi,-0x20(%rbp)
0x000000000011000c:  mov    %rdx,-0x28(%rbp)
0x0000000000110010:  mov    -0x20(%rbp),%rax
0x0000000000110014:  mov    (%rax),%rax
0x0000000000110017:  mov    %rax,-0x8(%rbp)
0x000000000011001b:  jmp    0x11001b
...
(qemu) info registers
RAX=00000000c0000000 RBX=00000000bef67f98 RCX=0000000000000000 RDX=0000000000000000
RSI=0000000000407180 RDI=00000000bfe9b018 RBP=000000000020fff8 RSP=000000000020fff8
R8 =00000000bff0e9dc R9 =0000000000000078 R10=00000000bfe6e080 R11=00000000e7dc4657
R12=00000000bef69540 R13=00000000bef69548 R14=00000000bff24b60 R15=00000000bef6a018
RIP=000000000011001b RFL=00000002 [-------] CPL=0 II=0 A20=1 SMM=0 HLT=0
*/

/*
kernel.bin.code:     ファイル形式 binary


セクション .data の逆アセンブル:

0000000000000000 <.data>:
   0:   55                      push   %rbp
   1:   48 89 e5                mov    %rsp,%rbp
   4:   48 89 7d e8             mov    %rdi,-0x18(%rbp)
   8:   48 89 75 e0             mov    %rsi,-0x20(%rbp)
   c:   48 89 55 d8             mov    %rdx,-0x28(%rbp)
  10:   48 8b 45 e0             mov    -0x20(%rbp),%rax
  14:   48 8b 00                mov    (%rax),%rax
  17:   48 89 45 f8             mov    %rax,-0x8(%rbp)
  1b:   eb fe                   jmp    0x1b
*/

void start_kernel(void *_t __attribute__ ((unused)), struct framebuffer *fb,
		  void *_fs_start __attribute__ ((unused)))
{
	volatile unsigned long long fb_base = (unsigned long long)fb->base;

	while (1);
}
