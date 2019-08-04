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

void start_kernel(void *_t __attribute__ ((unused)),
		  struct framebuffer *fb __attribute__ ((unused)),
		  void *_fs_start __attribute__ ((unused)))
{
	volatile unsigned char a = 1, b = 1, z;
	z = a * b;

	while (1);
}
