#include <vector>
using namespace std;

/*
 *ALL CODED SOLUTION
 *TIME COMPLEXITY: O(log n)
 *SPACE COMPLEXITY: O(1)
 *THOUGHT PROCESS: Tried to implement a binary search top to bottom.
 */

int solution(vector<int>& nums, int target) {

    int left = 0, 
        right = nums.size() - 1;

    while (left <= right) 
    {
        int middle = left + (right - left) / 2;
        if (nums[middle] >= target)
            right = middle - 1;
        else
            left = middle + 1;
    }

    return left;
}

/*
 *USING THE std::lower_bound FUNCTION
 *TIME COMPLEXITY: O(log n)
 *SPACE COMPLEXITY: O(1)
 */
int solution2(vector<int>& nums, int target) {

    /*
     *This function returns an iterator pointing to the first element that is not less
     *than the target. To transform this iterator into the index of the element, its
     *necessary to subtract the iterator .begin() from it.
     */
    return (lower_bound(nums.begin(), nums.end(), target) - nums.begin());
}
