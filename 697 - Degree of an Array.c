/* 
  697. https://leetcode.com/problems/degree-of-an-array/
  
  Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

  Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

  Example 1:
    Input: [1, 2, 2, 3, 1]
    Output: 2
  Explanation: 
    The input array has a degree of 2 because both elements 1 and 2 appear twice.
    Of the subarrays that have the same degree:
    [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
    The shortest length is 2. So return 2.
  Example 2:
    Input: [1,2,2,3,1,4,2]
    Output: 6
  
  Note:
    nums.length will be between 1 and 50,000.
    nums[i] will be an integer between 0 and 49,999.
*/

/*  
  Not the most elegant solution in my opinion:
   - Large map to store and lookup repeat numbers easily and quickly
   - Separate subArraySz for holding subarray lengths of highest degree elements
      to sort through afterwards.
*/    

#define MAP_SIZE (50000)
typedef struct {
    int count;
    int startIndex;
    int endIndex;
} t_arrayMap;

int findShortestSubArray(int* nums, int numsSize) {
    int i, j, degree, diff, subArrSize[MAP_SIZE]; 

    t_arrayMap sMap[MAP_SIZE] = {0};
    degree = 0;
    
    /* Loop through nums and find freq */ 
    for (i = 0; i < numsSize; i++) {
        if (sMap[ nums[i] ].count++ == 0) {
            sMap[ nums[i] ].startIndex = i;
        }
        
        /* If larger degree, restart storage */
        if (sMap[ nums[i] ].count > degree) {
            j = 0;            
            degree = sMap[ nums[i] ].count;
            sMap[ nums[i] ].endIndex = i;
            diff = (sMap[ nums[i] ].endIndex - sMap[ nums[i] ].startIndex + 1);
            subArrSize[j++] = diff;   
        }
        
        /* If same, store for comparison */
        if (sMap[ nums[i] ].count == degree) {
            sMap[ nums[i] ].endIndex = i;
            diff = (sMap[ nums[i] ].endIndex - sMap[ nums[i] ].startIndex + 1);
            subArrSize[j++] = diff;  
        }
    }
    
    /* Final loop through max degree array to find smallest subarray len */ 
    degree = MAP_SIZE;
    for (i=0; i<j; i++) {
        if (subArrSize[i] < degree) degree=subArrSize[i];
    }
    return degree;
}