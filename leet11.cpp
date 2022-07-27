// faster way
#include<algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        // find max for each l
        unordered_map<int,int> lmax;
        
        // calculate maxA
        int maxA = 0;
        int l = 0,  r = height.size()-1;
        while (l!=r) {
            maxA = max( maxA, (r-l)*min(height[l],height[r])  );
            if (height[l]>height[r]) {
                r--;
            } else {
                l++;
            }            
        }
        return maxA;
    }
};

#include<algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        // find max for each l
        unordered_map<int,int> lmax;
        int maxbar = height[ height.size()-1 ];
        for (int i = 1; i < height.size(); i++) {
            int lpos = height.size()-i-1;
            maxbar = max(maxbar, height[lpos]  ) ;
            lmax.insert(make_pair(lpos, maxbar));
        }
        
        // calculate maxA
        int maxA = 0;
        for (int l = 0; l < height.size()-1; l++) {
            int width = height.size()-1-l;
            int maxPos = width*lmax[l];
            if (maxPos <= maxA) return maxA;
            for (int r = l + 1; r < height.size(); r++) {
                maxA = max(maxA, (r-l) * min(height[l],height[r]) );
            }
        }
        return maxA;
    }
};
