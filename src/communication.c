#include "communication.h"
#include "util_comm.h"
#include<string.h>
#include <stdio.h>


/* Task 1 - The Beginning */

void send_byte_message(void)
{
    /* TODO
     * Send the encoding of the characters: R, I, C, K
     */
    int codR, codI, codC, codK;

    codR = 'R'-'A'+1;
    codI = 'I'-'A'+1;
    codC = 'C'-'A'+1;
    codK = 'K'-'A'+1;
    
    send_squanch(codR);
    send_squanch(codI);
    send_squanch(codC);
    send_squanch(codK);
}


void recv_byte_message(void)
{
    /* TODO
     * Receive 5 encoded characters, decode them and print
     * them to the standard output (as characters)
     *
     * ATTENTION!: Use fprintf(stdout, ...)
     */
    int i, v[5];
     for(i = 0; i <= 4 ; i++)
     {
        v[i]= recv_squanch();
        v[i] = v[i] + 64;
     }
     for(i = 0; i <= 4; i++)
        fprintf(stdout, "%c", v[i]);
}


void comm_byte(void)
{
    /* TODO
     * Receive 10 encoded characters and send each character (the character is
     * still encoded) 2 times
     */
    int i, v[10], j;

    for (i=0 ;i <= 9; i++)
        v[i] = recv_squanch();

     for (i = 0; i <= 9; i++)
        for(j = 1; j <= 2; j++) 
            send_squanch(v[i]);
}


/* Task 2 - Waiting for the Message */

void send_message(void)
{
    /* TODO
     * Send the message: HELLOTHERE
     * - send the encoded length
     * - send each character encoded
     */
    int lungcuv;
    lungcuv = strlen("HELLOTHERE");
    
    send_squanch(lungcuv << 2);
    
    int i,v[]={'H','E','L','L','O','T','H','E','R','E'};

    for(i = 0; i <= 9 ; i++)
        send_squanch(v[i] -'A' + 1);  
}


void recv_message(void)
{
    /* TODO
     * Receive a message:
     * - the first value is the encoded length
     * - length x encoded characters
     * - print each decoded character
     * 
     * ATTENTION!: Use fprintf(stdout, ...)
     */
    int x, v[26], i;
    unsigned int mask;

    x =  recv_squanch() ;

    for(i = 7; i >= 6 ; i--)
    {
        mask = 1 << i;
        x = x & (~mask);
    }
    x = x >> 2;

    for(i = 0 ; i< x ; i++)
    { 
           v[i] = recv_squanch();
           v[i] = v[i] + 64;
    }
    
    fprintf(stdout, "%d", x);
    for( i = 0; i < x ; i++)
        fprintf(stdout, "%c", v[i]);
    
}


void comm_message(void)
{
    /* TODO
     * Receive a message from Rick and do one of the following depending on the
     * last character from the message:
     * - 'P' - send back PICKLERICK
     * - anything else - send back VINDICATORS
     * You need to send the messages as you did at the previous tasks:
     * - encode the length and send it
     * - encode each character and send them
     */
    int x, v[26], i, lungP, lungV;
    unsigned int mask;

    x =  recv_squanch();

    for(i = 7; i >= 6 ; i--)
    {
        mask = 1<<i;
        x = x & (~mask);
    }
    x = x >> 2;
    for(i = 0; i < x; i++)
    { 
        v[i] = recv_squanch();
        v[i] = v[i] + 64;
    }
    
    
    if( v[x - 1] == 'P')
    {
        lungP = strlen("PICKLERICK");
        send_squanch(lungP<<2);
        send_squanch('P'-'A'+1);
        send_squanch('I'-'A'+1);
        send_squanch('C'-'A'+1);
        send_squanch('K'-'A'+1);
        send_squanch('L'-'A'+1);
        send_squanch('E'-'A'+1);
        send_squanch('R'-'A'+1);
        send_squanch('I'-'A'+1);
        send_squanch('C'-'A'+1);
        send_squanch('K'-'A'+1);

    }
    else
    {
        lungV = strlen("VINDICATORS");
        send_squanch(lungV<<2);
        send_squanch('V'-'A'+1);
        send_squanch('I'-'A'+1);
        send_squanch('N'-'A'+1);
        send_squanch('D'-'A'+1);
        send_squanch('I'-'A'+1);
        send_squanch('C'-'A'+1);
        send_squanch('A'-'A'+1);
        send_squanch('T'-'A'+1);
        send_squanch('O'-'A'+1);
        send_squanch('R'-'A'+1);
        send_squanch('S'-'A'+1);
    }
    
}

/* Task 3 - In the Zone */

void send_squanch2(uint8_t c1, uint8_t c2)
{
    /* TODO
     * Steps:
     * - "merge" the character encoded in c1 and the character encoded in c2
     * - use send_squanch to send the newly formed byte
     */
    int i, mask, nr = 0, j = 0;
    for(i = 0; i < 4; i++)
    {
        mask = 1 << i;
        if(c2 & mask)
            nr = nr + (1 << j);
        j++;

        if(c1 & mask)
            nr = nr + (1 << j);
        j++;
        
    }
    send_squanch(nr);
}


uint8_t decode_squanch2(uint8_t c)
{
    /*
     * Decode the given byte:
     * - split the two characters as in the image from ocw.cs.pub.ro
     */

    uint8_t res = 0;

    /* TODO */
    int i, j = 0, mask;
    for (i = 0; i < 7; i = i + 2)
    {   
        mask = 1 << i;
        if(c & mask)
            res = res + (1 << j);
        j++;

    }
    for (i = 1; i < 8 ; i = i + 2)
    {
        mask = 1 << i;
        if(c & mask)
            res = res + (1 << j);
        j++;

    }
    
    return res;
}
