class Solution {
public:
    int climbStairs(int n) {
        int one = 1;
        int two = 1;
        for(int i = 0; i < n-1; i++)
        {
            int temp = one;
            one = one + two;
            two = temp;
        }
        return one;
        // int numTwos = n/2;
        // int result = 0; // this will correspond to all the 2's
        // if(n%2 == 1)
        // {
        //     result += numTwos+1; // because I kinda know that nC1 is n
        //     int totalNums = numTwos+ 2;
        //     for(int i = 1, j = 3; i <= numTwos; i++, j += 2, totalNums++)
        //     {
        //         result += combinations(totalNums,j);
        //         cout << result << endl;
        //     }
        // }
        // else
        // {
        //     result = 1; // this will correspond to all the 2's
        //     for(int i = 1, j = 2; i <= numTwos; i++, j += 2)
        //     {
        //         result += combinations(numTwos+i,j);
        //     }
        // }
        // return result;
    }

// private:
//     int combinations(int top, int bottom)
//     {
//         int difference = top - bottom;
//         if(bottom == 0 || difference == 0)
//         {
//             return 1;
//         }
//         return (factorial(top)/(factorial(bottom)*factorial(difference)));
//     }

//     int factorial(int n)
//     {
//         int result = 1;
//         for(int i = 1; i <= n; i++)
//         {
//             result = result * i;
//         }
//         return result;
//     }
};
