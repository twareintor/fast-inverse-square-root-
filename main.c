//Permanent link: https://rextester.com/IMHHZS8361
//Fast Inverse Square Root �" A Quake III Algorithm
//gcc

#include <stdio.h>

float Q_rsqrt(const float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number*0.5F;
    y = number;
    i = *(long*)&y;                     // evil floating point bit hack
    i = 0x5f3759df-(i>>1);              // what the fuck?
    y = *(float*)&i;
    y = y*(threehalfs-(x2*y*y));        // 1st iteration
    // y = y*(threehalfs-(x2*y*y));     // 2nd iteration, can be removed
    return y;
}

int main(void)
{
    const float f = 232.83923f;
    printf("%F\n", f*Q_rsqrt(f*f));
    return 0;

}
