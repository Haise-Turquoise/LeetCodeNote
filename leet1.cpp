#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int,int> umap;
        
        for (size_t i = 0; i < nums.size(); i++) {
            int key = target - nums[i];
            if (umap.find(key) != umap.end()) {
                
                ret.push_back(  umap.at( key )  );
                ret.push_back(i);
            } else {
                umap.insert( make_pair(nums[i],i) );
            }
        }
        return ret;
        
        
        /*brute
        vector<int> ret;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            for ( int j = i+1 ; j < nums.size() ; j++ ) {
                if (nums.at(i) + nums.at(j) == target) {
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
        */
    }
};
