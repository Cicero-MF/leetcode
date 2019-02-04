/* 
38. Count and Say - https://leetcode.com/problems/count-and-say/

The count-and-say sequence is the sequence of integers with the first five terms as following:
  1.     1
  2.     11
  3.     21
  4.     1211
  5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:
  Input: 1
  Output: "1"

Example 2:
  Input: 4
  Output: "1211"
*/

/*  
  Pretty simple recursive C solution.  Not much else to it really.
  
*/    

static char *baseCases[] = {
    0,
    "1",
    "11",
    "21",
    "1211",
    "111221"
};

static char res[5000];

char* countAndSay(int n) {    
    char *s, *local;    
    int k, len;
    
    if (n <= 5) return baseCases[n];
       
    s = countAndSay(n-1);
    len = strlen(s);
    
    local = (char *)malloc(sizeof(char) * len + 1);    
    strcpy(local, s);
    local[len] = 0;
    
    k = 0;
    for (int j = 0; j < len; j++) {
        int sum;
        sum = 1;
        while(local[j] == local[j+1]) {
            sum++;
            j++;
        }
        res[k++] = sum + '0';
        res[k++] = local[j];
    }    
    res[k] = 0;
    
    free(local); 
    
    return res;
}
