int func(int a, int b, int c, int d)
{
	volatile int z = a + b + c + d;
	return z;
}

int func2(int a, int b, int c, int d, int e, int f, int g, int h)
{
	volatile int z = a + b + c + d + e + f + g + h;
	return z;
}

int func3(int a)
{
	volatile int z = a;
	return z;
}

int main(void)
{
	volatile int a, b, c, d;
	volatile int e, f, g, h;
	volatile int z;

	a = 1;
	b = 2;
	c = 3;
	d = 4;
	e = 5;
	f = 6;
	g = 7;
	h = 8;
	/* z = func(a, b, c, d); */
	z = func2(a, b, c, d, e, f, g, h);
	/* z = func3(a); */

	return 0;
}
