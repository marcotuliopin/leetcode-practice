#include <vector>
using namespace std;

int solution(vector<int>& nums) {

    int current_sum = nums[0],
        max_sum = current_sum;

    for (int i = 1; i < nums.size(); i++)
    {
        current_sum = max(current_sum + nums[i], nums[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}
