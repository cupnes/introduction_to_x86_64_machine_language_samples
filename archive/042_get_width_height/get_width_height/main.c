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
0x0000000000110014:  mov    0x10(%rax),%eax
0x0000000000110017:  mov    %eax,-0x4(%rbp)
0x000000000011001a:  mov    -0x20(%rbp),%rax
0x000000000011001e:  mov    0x14(%rax),%eax
0x0000000000110021:  mov    %eax,-0x8(%rbp)
0x0000000000110024:  jmp    0x110024
...
(qemu) info registers
RAX=0000000000000258 RBX=00000000bef67f98 RCX=0000000000000000 RDX=0000000000000000
RSI=0000000000407180 RDI=00000000bfe9b018 RBP=000000000020fff8 RSP=000000000020fff8
R8 =00000000bff0e9dc R9 =0000000000000078 R10=00000000bfe6e080 R11=00000000e7dc4657
R12=00000000bef69540 R13=00000000bef69548 R14=00000000bff24b60 R15=00000000bef6a018
RIP=0000000000110024 RFL=00000002 [-------] CPL=0 II=0 A20=1 SMM=0 HLT=0
...
(qemu) x/2wd 0x20fff0
000000000020fff0:        600        800
*/

/*
   0:   55                      push   %rbp
   1:   48 89 e5                mov    %rsp,%rbp
   4:   48 89 7d e8             mov    %rdi,-0x18(%rbp)
   8:   48 89 75 e0             mov    %rsi,-0x20(%rbp)
   c:   48 89 55 d8             mov    %rdx,-0x28(%rbp)
  10:   48 8b 45 e0             mov    -0x20(%rbp),%rax
  14:   8b 40 10                mov    0x10(%rax),%eax
  17:   89 45 fc                mov    %eax,-0x4(%rbp)
  1a:   48 8b 45 e0             mov    -0x20(%rbp),%rax
  1e:   8b 40 14                mov    0x14(%rax),%eax
  21:   89 45 f8                mov    %eax,-0x8(%rbp)
  24:   eb fe                   jmp    0x24
*/

void start_kernel(void *_t __attribute__ ((unused)), struct framebuffer *fb,
		  void *_fs_start __attribute__ ((unused)))
{
	volatile unsigned int width = (unsigned long long)fb->hr;
	volatile unsigned int height = (unsigned long long)fb->vr;

	while (1);
}
