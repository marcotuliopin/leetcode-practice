#include <vector>
#include <unordered_map>
using namespace std;

/*
 *BRUTE FORCE METHOD
 *TIME COMPLEXITY: O(n^2) solution(vector<int>& n
 *SPACE COMPLEXITY: O(1)
 *THOUGHT PROCESS: iterate through the array and, for each element, search in the array
 *for the number that complement it in relation to the target.
 */
vector<int> solution(vector<int>& nums, int target) {
    
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] == target - nums[i])
                return {i, j};
        }
    }
    return {0, 0};
}

/*
 *HASHTABLE METHOD
 *TIME COMPLEXITY: O(n)
 *SPACE COMPLEXITY: O(n)
 *THOUGHT PROCESS: create a hashtable where the keys are the numbers of the array
 *and the values are their indexes. Traverse the array and, for each element, search
 *for its complement in the hashtable (O(1)). If its not found, add the element to 
 *the table.
 */
vector<int> solution2(vector<int>& nums, int target) {

    unordered_map<int, int> map;
    
    for (int i = 0; i < nums.size(); i++)
    {
        if (map.find(target - nums[i]) != map.end())
            return {map[target - nums[i]], i};
        // Add the element only after the map.find() to avoid finding i.
        map[nums[i]] = i;
    }
    return {0, 0};
}
