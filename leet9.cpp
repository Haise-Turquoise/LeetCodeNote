#include <cmath>
#include <iostream>
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        int cur = x, cnt = 0;
        while (cur >= 10) {
            cur = cur/10;
            cnt++;
        }
        int len = cnt + 1;
        bool pali = true;
        std::cout <<"len:"<<len<<std::endl;
        cur = x;
        while (cur >=10 ) {
            int div = pow(10, len - 1);
            int l = cur/div;
            int r = cur%10;
            //std::cout <<"l: "<<l<<"; r: "<<r<<std::endl;
            if (l != r) {
                pali = false;
                break;
            }
            // update cur and len
            cur = cur - l*div - r;
            std::cout <<"cur: "<<cur<<std::endl;
            cur = cur/10;
            std::cout <<"cur: "<<cur<<std::endl;
            len = len -2;
        }
        return pali;
    }
};
