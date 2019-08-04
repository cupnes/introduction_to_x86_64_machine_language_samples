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
(qemu) x/30i 0x110000
0x0000000000110000:  push   %rbp
0x0000000000110001:  mov    %rsp,%rbp
0x0000000000110004:  mov    %rdi,-0x18(%rbp)
0x0000000000110008:  mov    %rsi,-0x20(%rbp)
0x000000000011000c:  mov    %rdx,-0x28(%rbp)
0x0000000000110010:  mov    -0x20(%rbp),%rax
0x0000000000110014:  mov    (%rax),%rax
0x0000000000110017:  mov    %rax,-0x8(%rbp)
0x000000000011001b:  movl   $0x0,-0xc(%rbp)
0x0000000000110022:  jmp    0x11003a
0x0000000000110024:  mov    -0x8(%rbp),%rax
0x0000000000110028:  lea    0x4(%rax),%rdx
0x000000000011002c:  mov    %rdx,-0x8(%rbp)
0x0000000000110030:  movl   $0xffffff,(%rax)
0x0000000000110036:  addl   $0x1,-0xc(%rbp)
0x000000000011003a:  mov    -0x20(%rbp),%rax
0x000000000011003e:  mov    0x10(%rax),%edx
0x0000000000110041:  mov    -0x20(%rbp),%rax
0x0000000000110045:  mov    0x14(%rax),%eax
0x0000000000110048:  imul   %edx,%eax
0x000000000011004b:  cmp    -0xc(%rbp),%eax
0x000000000011004e:  ja     0x110024
0x0000000000110050:  jmp    0x110050
*/

/*
   0:   55                      push   %rbp
   1:   48 89 e5                mov    %rsp,%rbp
   4:   48 89 7d e8             mov    %rdi,-0x18(%rbp)
   8:   48 89 75 e0             mov    %rsi,-0x20(%rbp)	# -0x20(%rbp) <- fb
   c:   48 89 55 d8             mov    %rdx,-0x28(%rbp)
  10:   48 8b 45 e0             mov    -0x20(%rbp),%rax
  14:   48 8b 00                mov    (%rax),%rax
  17:   48 89 45 f8             mov    %rax,-0x8(%rbp)	# -0x8(%rbp) <- p (FB addr)
  1b:   c7 45 f4 00 00 00 00    movl   $0x0,-0xc(%rbp)	# -0xc(%rbp) <- i
  22:   eb 16                   jmp    0x3a
  24:   48 8b 45 f8             mov    -0x8(%rbp),%rax
  28:   48 8d 50 04             lea    0x4(%rax),%rdx
  2c:   48 89 55 f8             mov    %rdx,-0x8(%rbp)
  30:   c7 00 ff ff ff 00       movl   $0xffffff,(%rax)
  36:   83 45 f4 01             addl   $0x1,-0xc(%rbp)
  3a:   48 8b 45 e0             mov    -0x20(%rbp),%rax
  3e:   8b 50 10                mov    0x10(%rax),%edx	# 0x10(%rax),%edx <- width
  41:   48 8b 45 e0             mov    -0x20(%rbp),%rax
  45:   8b 40 14                mov    0x14(%rax),%eax	# 0x14(%rax),%eax <- height
  48:   0f af c2                imul   %edx,%eax	# edx * eax -> eax
  4b:   3b 45 f4                cmp    -0xc(%rbp),%eax	# ? eax - i
  4e:   77 d4                   ja     0x24		# jmp if above (CF=0 & ZF=0)
  50:   eb fe                   jmp    0x50
*/

#define COLOR	0x00ffffff
void start_kernel(void *_t __attribute__ ((unused)), struct framebuffer *fb,
		  void *_fs_start __attribute__ ((unused)))
{
	unsigned int *p = (unsigned int *)(fb->base);
	unsigned int i;
	for (i = 0; i < (fb->hr * fb->vr); i++)
		*p++ = COLOR;

	while (1);
}
