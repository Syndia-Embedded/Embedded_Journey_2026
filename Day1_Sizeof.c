#include <stdio.h>
#include <limits.h>
#include <float.h>
int main (void)
{

printf("Integer Types\n");
printf("char: size=%zu, range=%d to %d\n",sizeof(char),CHAR_MIN,CHAR_MAX);
printf("short: size=%zu, range=%d to %d\n",sizeof(short),SHRT_MIN,SHRT_MAX);
printf("unsigned short: size=%zu, range=%d to %d\n",sizeof(unsigned short),0u,USHRT_MAX);
printf("unsigned char: size=%zu, range=%u to %u\n",sizeof(unsigned char),0u,UCHAR_MAX);
printf("INT: size=%zu, range=%d to %d\n",sizeof(int),INT_MIN,INT_MAX);

printf("Long: size=%zu, range=%ld to %ld\n",sizeof(long),LONG_MIN,LONG_MAX);
printf("Unsigned long: size=%zu, range=%lu to %lu\n",sizeof(unsigned long),0ul,ULONG_MAX);

printf("long long: size=%zu, range=%lld to %lld\n",sizeof(long long),LLONG_MIN,LLONG_MAX);
printf("unsigned long long: size=%zu, range=%llu to %llu\n",sizeof(unsigned long long),0ull,LLONG_MAX);


printf("Floating Types\n");
printf("float: size=%zu, range=%e to %e\n",sizeof(float),FLT_MIN,FLT_MAX);
printf("double: size=%zu, range=%e to %e\n",sizeof(double),DBL_MIN,DBL_MAX);
printf("long double: size=%zu, range=%Le to %Le\n",sizeof(long double),LDBL_MIN,LDBL_MAX);

printf("pointer size\n");
printf("pointer: size=%zu\n\n",sizeof(void*));
}
