// https://leetcode-cn.com/problems/two-sum/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *p;
    p = (int*)malloc(2*sizeof(int));
    for(int a=0; a<numsSize; a++) {
        for(int b=0; b<numsSize; b++) {
            if(a!=b) {
                if (nums[a]+nums[b]==target) {
                    p[0]=a;
                    p[1]=b;
                    *returnSize=2;
                    return p;
                }
            }
        }
    }
    return p;
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    for(int i = 0; i < nums.size() - 1; i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if (nums[i]+nums[j]==target) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> a;
        map<int,int>::iterator it;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            it = a.find(diff);
            if (it != a.end()) {
                result.push_back(it->second);
                result.push_back(i);
                return result;
            } else {
                a[nums[i]] = i;
            }
        }
        return result;
    }
};
