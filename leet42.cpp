#include <iostream>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int l = 0;
        // find leftmost bar
        while (l < height.size() ) {
            if (height.at(l)>0 ) {
                if ( l == height.size()-1 || height.at(l) > height.at(l+1) ) break;
            }
            l++;
        }
        
        // leftmost bar is at the left neighbour of the rightmost position
        if (l >= height.size()-2 ) return 0;
        
        int r = l+2, cnt = 0, maxpos = 0;
        // process reverse L issue
        while (l <= height.size() - 3) {
            if ( height[l] <= height[r] ) {  // right bar appear to store slot water or reach rightmost
                cout << "l:" << l << endl;
                cout << "r:" << r << endl;
                cout << "cnt before:" << cnt << endl;
                
                int width = r-l-1;
                for (int i = l+1; i < r; i++) cnt -= height[i]; 
                cnt += width*height[l];
                cout << "cnt after:" << cnt << endl;
                l = r;
                while (l < height.size() ) {
                    if ( l == height.size()-1 || height.at(l) > height.at(l+1) ) break;  //[8,2,8,9,0,1,7,7,9]
                    l++;
                }
                r = l + 2;
            } else { // move r
                r++;
                if (r > height.size() - 1) {  // out of limit of r
                    maxpos = l;
                    break;
                }
            }
        }
        
        if (l >= height.size() - 2) return cnt;  // 202   423  [5,5,1,7,1,1,5,2,7,6]

        cout << "from right:" << endl;
        r = height.size() -1;
        while (r >= 0 ) {
            if (height.at(r)>0 ) {
                if ( r == 0 || height.at(r-1) < height.at(r) ) break;
            }
            r--;
        }
        if (r <= maxpos+1) return cnt;
        l = r - 2;
        while (l >= maxpos) {
            if ( height.at(l) >= height.at(r) ) {  // left bar appear to store slot water or reach top bar
                cout << "l:" << l << endl;
                cout << "r:" << r << endl;
                cout << "cnt before:" << cnt << endl;
                
                int width = r-l-1;
                for (int i = l+1; i < r; i++) cnt -= height.at(i); 
                cnt += width*height.at(r);
                cout << "cnt after:" << cnt << endl;
                r = l;
                while (r >= maxpos ) {
                    if ( r == maxpos || height.at(r-1) < height.at(r) ) break;  //[8,2,8,9,0,1,7,7,9]
                    r--;
                }
                l = r - 2 ;
            } else { // move l
                l--;
            }
        }
        
        
        
        return cnt;
    }
};
