#define SCHRAND_MAX ((1U << 31) - 1)
#define SCHRAND_MULT 214013
#define SCHRAND_CONST 2531011

//Pseudo-random number generator made from a linear congruential generator.
//Based on code and constants found at:
//https://rosettacode.org/wiki/Linear_congruential_generator

int rseed = 707606505;

int rand(void)
{
  return rseed = (rseed * SCHRAND_MULT + SCHRAND_CONST) % SCHRAND_MAX;
}
