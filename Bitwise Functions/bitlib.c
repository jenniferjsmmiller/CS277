#include <stdio.h>

/*
 * bitwise_nor  - implement ~(x|y) using only ~ and &.
 *  Example biwise_nor(6, 5) = 0xFFFFFFF8
 *  Max. # of operators: 8
 */
int bitwise_nor(int x, int y) {

  return (~x) & (~y);

}

/*
 * bitwise_xor - implement x xor y using only ~ and &.
 * Example bitwise_xor(4,5) = 0x1
 * Max # of operators: 14
 */
int bitwise_xor(int x, int y) {

  int and = x & y;
  int nor = ~x & ~y;
  int result = ~and & ~nor;
  return result;

}

/*
 * eval_not_equal - implement x!=y.
 *  using only !, ~, &, |, ^, +, << and >>
 *   returns 0 if x == y, otherwise 1
 * Examples: eval_not_equal(2,2) = 0, eval_not_equal(3,4) = 1
 * Max # of operators: 6
 */
int eval_not_equal(int x, int y) {

  return !(x & (~y + 1));

}

/*
 * get_byte - extract byte n from word x.
 *  using only !, ~, &, |, ^, +, << and >>
 * assume ordering as 0=least significant byte,
 * 3 = most significant byte.
 * Example: get_byte(0x12345678, 1) = 0x56
 * Max # of operators: 6
*/
int get_byte(int x, int n) {

  n = n << 3;
  x = x >> n;
  return (0xFF & x);

}

/*
* copy_lsbit - set all bits of result value to the least significant bit of x
*  using only !, ~, &, |, ^, +, << and >>
*  Examples: copy_lsbit(5) = 0xFFFFFFFF, copy_lsbit(8) = 0x0
*  Max # of operators: 5
*/
int copy_lsbit(int x) {

  return ((x << 31) >> 31);

}

/*
 * bit_count - returns the # of bits in x that are 1.
 *  using only !, ~, &, |, ^, +, << and >>
 * examples: bit_count(2) = 1, bit_count(10) = 2, bit_count(7) = 3
 * Max # of operators: 40
 */
int bit_count(int x) {

  //two masks, the first one covering two least sig bits, and the second covering the rest
  int mask = 0x11 | 0x11 << 8;
  int mask2 = mask | mask << 16;
  int finalmask = 0x3F;
  int result = x & mask2;

  //sum of ones in first byte (the original amount for sum is included in this)
  result += (x >> 1) & mask2;
  result += (x >> 2) & mask2;
  result += (x >> 3) & mask2;
  result += (x >> 4) & mask2;

  //adjust current result and mask for bits to come for next byte
  result += result >> 16;
  mask = 0xF | (0xF << 8);

  //apply new mask to sum
  result = (result & mask);
  //add new ones calculated to existing result
  result += ((result >> 4) & mask);
  //shift by one byte and apply final mask for appropriate representation
  result += (result >> 8) & finalmask;

  return result;

}

int main (void) {

  int x = 241;
  x = x << 5;

  printf("%d\n", x);

}
