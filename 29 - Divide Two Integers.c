/* Essentially just performed long division in binary, without use of longs. 
  Beats 100% of other solutions - somehow...
  Reduced number of main loop interations by first counting bit 
  length of inputs and only looping for what is necessary */ 

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