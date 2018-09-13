/*
Copyright 2018 Mizuho MORI(morimolymoly)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <linux/module.h>
#include "msr.h"

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Mizuho MORI <morimolymoly@gmail.com>");
MODULE_DESCRIPTION("MSR_IA32_LSTAR RDMSR TEST KERNEL MODULE");

static inline void exec_wrmsr(uint64_t msr, uint64_t val)
{
	asm volatile (
		"wrmsr"
		: : "c"(msr),
		"=A"(val) : "memory"
	);
}

static int mymodule_init(void)
{
	exec_wrmsr(MSR_IA32_LSTAR, 0xffffeb1111111111ULL);
	return 0;
}
static void mymodule_exit(void)
{
}

module_init(mymodule_init);
module_exit(mymodule_exit);
