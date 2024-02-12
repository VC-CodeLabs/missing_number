/// 240206 CodeLabs.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Missing Number
Find The Missing Number

Problem Statement:

You are given an array containing n - 1 integers. These integers will range from 1 to n; if ordered, they will be sequential (try to solve the challenge without sorting the numbers). No duplicates are in the list, and one integer from the range is missing. Your task is to make a solution that finds the missing integer within the provided constraints.

Examples: Input: [3, 7, 1, 2, 8, 4, 5] Output: 6 Explanation: The array should contain integers from 1 to 8, but 6 is missing.

Input: [11, 2, 10, 4, 5, 6, 7, 8, 1, 9] Output: 3 Explanation: The array should contain integers from 1 to 11, but 3 is missing.

Input: [4, 3, 1, 5] Output: 2 Explanation: The array should contain integers from 1 to 5. In this sequence, the number 2 is missing.

Constraints: The array has n - 1 integers, where n is the upper limit of the range of integers. n <= 10,000 All elements in the array are distinct. The array elements are in no particular order. You should aim for an efficient solution. The solution should not rely on sorting the array. Do not use built-in functions that directly solve the problem (e.g., in Python, avoid using sum(arr) directly).

📤 Submission Guidelines You can either email me your submission or Fork the Repository.
To submit using the GitHub repository, you must fork the challenge repository and create a Pull Request with your solution. Code Your Solution: In your chosen high-performance language. Remember, efficiency is key! Naming Convention: Name your solution file using the following convention: <your_name>_solution.* (replace <your_name> with your actual name and * with the appropriate file extension for your language). All merge requests will remain open and un-merged until Monday morning.

🏆 Winner Selection Criteria Correctness: Solutions must pass all provided test cases, proving their ability to effectively handle a wide range of input scenarios. Performance: Among the correct solutions, the crown will go to the one with the fastest execution time. Prepare to push the limits of efficiency! Code Elegance (Tiebreaker): In the event of a tie in execution time, the solution with fewer lines of code will be deemed superior, reflecting not only raw speed but also the elegance and readability of the code.

🕒 Submission Deadline: All email solutions or merge requests must be submitted by Sunday 23:59:45.
*/

#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int nums[1] = {}; 

    // Variables
    int n = (sizeof(nums) / sizeof(int)) + 1;
    int checkNum;
    int numAbove, numBelow;
    int highLimit = n, lowLimit = 1;
    int answer = 0;
    int i, exact;

    // Check for null case
    if (n == 1) answer = 1;

    // Go through array
    while (answer == 0)
    {
        // Set checkNum to half of the acceptable range
        if ((highLimit - lowLimit) % 2 == 0)
            checkNum = (highLimit - lowLimit) / 2;  // divides evenly
        else
            checkNum = ((highLimit - lowLimit) / 2) + 1;  // round

        if (checkNum == 0)
        {
            // Found the number
            answer = highLimit;
            break;  // break out immediately
        }
        else if (checkNum > highLimit)
            checkNum = highLimit;
        else if (checkNum < lowLimit)
            checkNum = lowLimit;

        numAbove = 0;
        numBelow = 0;
        exact = 0;

        // Go through array and deterimne how many numbers are above and below the check
        for (i = 0; i < (n-1); i++)
        {
            if (nums[i] > checkNum && nums[i] <= highLimit)
                numAbove++;
            else if (nums[i] < checkNum && nums[i] >= lowLimit)
                numBelow++;
            else if (nums[i] == checkNum)
                exact = checkNum;
        }

        if (exact == 0)
        {
            // The check number happened to be the missing number
            answer = checkNum;
            break;  // break out immediately
        }
        else if (numBelow == (checkNum - lowLimit - 1))
        {
            // Missing number is below the check
            // Low limit stays the same
            highLimit = checkNum - 1;
        }
        else if (numAbove == (highLimit - checkNum - 1))
        {
            // Missing number is above the check
            // High limit stays the same
            lowLimit = checkNum + 1;
        }
        else
        {
            // Error
            printf("\nError\n");
            return(0);
        }
    }

    // Output result
    printf("\nAnswer = %d.\n", answer);
    return(0);
}