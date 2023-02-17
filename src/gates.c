#include "gates.h"

#include <stdio.h>
#include <assert.h>
#include<string.h>
/* Task 1 - Bit by Bit */

uint8_t get_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);
    uint8_t res = -1;

    /* TODO
     *
     * "res" should be 1 if the bit is active, else 0
     */
   
    if (nr & ((uint64_t) 1) << i)
        res = 1;
    else
        res = 0;

    return res;
}


uint64_t flip_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint64_t res = -1;

    /* TODO
     *
     * Return the "nr" with the ith bit flipped
     */
    uint64_t mask;

    mask = (uint64_t)1 << i;

    if (get_bit(nr, i))
       res = nr & (~mask);
    else
        res = nr | mask;
    
    /*  XOR = sau exclusiv
        1^1 = 0
        1^0 = 1
        0^1 = 1
        0^0 = 0
    res = nr ^ ((unsigned long)1 << i);
   */

    return res;
}


uint64_t activate_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint64_t res = 0xFF;
    /* TODO
     *
     * Return the "nr" with the ith bit "1"
     */
    uint64_t mask;
    mask = (uint64_t)1 << i;
    res = nr | mask;

    return res;
}


uint64_t clear_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint64_t res = -1;

    /* TODO
     *
     * Return the "nr" with the ith bit "0"
     */
    uint64_t mask;

    mask = (uint64_t)1 << i;
    res= nr & (~mask);


    return res;
}


/* Task 2 - One Gate to Rule Them All */

uint8_t nand_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    return !(a & b);
}


uint8_t and_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    uint8_t res = -1;

    /* TODO - Use the nand gate to implement the and gate */

    // res = (! (!(a & b)));
    res = !nand_gate(a,b);


    return res;
}


uint8_t not_gate(uint8_t a)
{
    assert (a == 0 || a == 1);

    uint8_t res = -1;

    /* TODO - Use the nand gate to implement the not gate */

    //res = !(a & a);
    res = nand_gate(a, a);

    return res;
}


uint8_t or_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    uint8_t res = -1;

    /* TODO - Use the previously defined gates to implement the or gate */

    //res = !(!(a & a) & !(b & b));
    res = !(not_gate(a) & not_gate(b));

    return res;
}


uint8_t xor_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    uint8_t res = -1;

    /* TODO - Use the previously defined gates to implement the xor gate */

    int res1, res2;

    res1 = !(nand_gate(a, b) & a);
    res2 = !(nand_gate(a, b) & b);
    res = nand_gate(res1, res2);
    return res;
}


/* Task 3 - Just Carry the Bit */

uint8_t full_adder(uint8_t a, uint8_t b, uint8_t c)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);
    assert (c == 0 || c == 1);

    uint8_t res = 0;

    /* TODO - implement the full_adder using the previous gates
     * Since the full_adder needs to provide 2 results, you should
     * encode the sum bit and the carry bit in one byte - you can encode
     * it in whatever way you like
     */

    uint8_t suma, carry, carry1, carry2;
    suma = xor_gate(xor_gate(a, b), c);

    carry1 = and_gate(xor_gate(a, b), c);
    carry2 = and_gate(a, b);
    carry = or_gate(carry1, carry2);

    res = (suma << 1) + carry;

   
    return res;
}


uint64_t ripple_carry_adder(uint64_t a, uint64_t b)
{
    uint64_t res = 0;

    /* TODO
     * Use the full_adder to implement the ripple carry adder
     * If there is ANY overflow while adding "a" and "b" then the
     * result should be 0
     */
    
    uint8_t  i, sum_carry, carry = 0, sum, A, B;
    uint64_t mask;
    
    for(i = 0; i < 64 ;i++)              
    {
        mask = ((uint64_t)1 << i);
        A = (get_bit(a, i));
        B = (get_bit(b, i));
        sum_carry = full_adder(A, B, carry);
        carry = sum_carry & 1;
        sum = sum_carry >> 1;
        if(sum != 0)
            res = (res | mask);
    }
    if(carry != 0)
        res = 0;
    
    return res;
}
