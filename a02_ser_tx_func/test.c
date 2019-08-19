int main(void)
{
	/* unsigned int value = 0x110000; */
	/* unsigned int reg; */
	/* asm volatile ("mov %[value], %[reg]" */
	/* 	      :: [value]"m"(value), [reg]"a"(reg)); */

	asm volatile ("mov $0, %%rax" ::: "%rax");

	return 0;
}
