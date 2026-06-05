class Solution {
public:
    int climbStairs(int n) {
        //init old data array
        int arr[n+1] = {0};
        //main loop
        int i =0;
        while(i<=n){

            if(i == 1) arr[i] = 1;
            else if(i == 2) arr[i] = 2;
            else arr[i] = arr[i-1]+arr[i-2];

            i++;
        }

        return arr[n];
    }
};
