/* 29. Divide Two Integers
    Given two integers dividend and divisor, divide two integers without using multiplication, 
    division and mod operator.
    Return the quotient after dividing dividend by divisor.
    The integer division should truncate toward zero.
    Note:
    - Both dividend and divisor will be 32-bit signed integers.
    - The divisor will never be 0.
    - Assume we are dealing with an environment which could only store integers within 
      the 32-bit signed integer range: [−231,  231 − 1]. 
      For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

/*    
  Essentially just performed long division in binary, without use of longs. 
  Beats 100% of other solutions - somehow...
  Reduced number of main loop interations by first counting bit 
  length of inputs and only looping for what is necessary 
*/ 

int getDigits (unsigned int val) {
    int digits;
    for (digits=0; val>0; val>>=1) {
        digits++;
    }
    return digits;
}

int divide(int dividend, int divisor) {
    int result=0, negFlag;
    int i, divid, divis, dividDig, divisDig;
    unsigned int uidividend, uidivisor;
    
    if (divisor==1) {
        return dividend;
    }
    
    if (divisor == -1 && dividend <= INT_MIN) {
        return INT_MAX;
    }
    
    negFlag = 0;
    
    if ((dividend<0 && divisor>0) || ((dividend>0 && divisor<0))) {
        negFlag = 1;
    }
    
    uidivisor=abs(divisor);
    uidividend=abs(dividend); 
    
    dividDig = getDigits(uidividend);
    divisDig = getDigits(uidivisor);    
    i = abs(dividDig-divisDig);
    divid = uidividend>>i;
    
    while (i--) {
        result <<= 1;
        if (divid >= uidivisor) {
            result |= 1;
            divid = divid - uidivisor;
            divid <<= 1;
            divid |= ((uidividend&(1<<i))>>i);
        } else {                             
            divid <<= 1;
            divid |= ((uidividend&(1<<i))>>i);
        } 
    }
    result <<= 1;
    if (divid >= uidivisor) {
        result |= 1;        
    }   
    
    if (negFlag) result=~result+1;     
    return result;
}