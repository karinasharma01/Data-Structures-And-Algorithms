//Sliding Window Method 
//Time Complexity : O(n)
//Space Complexity : O(1)

#include <iostream>
#include <vector>
using namespace std;
int minSwaps(vector<int>& nums)
{
    int n = nums.size();
    //count the total number of ones in the given array 
    //this would be the size of the sliding window
    int countOnes = 0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==1)
        countOnes++;
    }
    int maxOnes = 0,curr_ones = 0;
    /*
    maxOnes is the maximum number of 1 in all the subarrays of size countOnes encountered so far
    curr_ones is the count of 1s in the current window
    the minimum swaps would be equal to the difference between the total number of 1s in the array and the maximum number of ones encountered in a window of size countOnes
    */
    int start = 0;//start index of the sliding window
    int end = 0;//end index of the sliding window
    while(end < n)
    {
        curr_ones+=nums[end];
        if(end-start+1==countOnes)
        {
            maxOnes = max(maxOnes,curr_ones);
            if(nums[start++]==1)
            {
                curr_ones--;
            }
        }
        end++;
    }
    return countOnes-maxOnes;
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++)
	{
	    cin>>nums[i];
	}
	int res = minSwaps(nums);
	cout << "Min Swaps to Group all ones together : "<< res<<endl;
	return 0;
}
