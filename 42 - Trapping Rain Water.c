/*  https://leetcode.com/problems/trapping-rain-water/ 
    Given n non-negative integers representing an elevation map where the width of each bar is 1, 
    compute how much water it is able to trap after raining.
    
    Example:

    Input: [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
*/

/*    
  4ms (beats 100%) re-entrant solution that iterates through each trough.
    Not as elegant (in my opinion) as some other solutions, 
    however returned quicker than most.
*/ 

int trap(int* height, int heightSize) {  
    int gnd, i, j, h, water, maxH;
    
    water = 0;
    /* Ignore 0 heights - basically leading zeros */
    for (j=0; j<heightSize; j++) {
        h = height[j];
        if (h) break;
    }
    
    maxH = 0;
    gnd = 0;
    for (i=j+1; i<heightSize; i++) {
        if (height[i] >= h) {
            water+=((i-j-1)*h - gnd);
            water+=trap(&height[i], heightSize-i);
            break;
        } else {
            gnd+=height[i];
            if (height[i] > maxH) maxH=height[i];
            if (gnd && ((i+1)==heightSize)) {
                height[j] = maxH;
                water+=trap(&height[j], heightSize-(j));
            }
        }
    }
    return water;
}