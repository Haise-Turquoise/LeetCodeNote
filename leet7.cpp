class Solution {
public:
    int reverse(int x) {
        if ((x == 0) || (x<=INT_MIN) ) return 0;
        int cur = (x > 0) ? x : -x;
        int cnt = 0;
        while(true) {
            int gw = cur%10; 
            cnt += gw; 
            if (cur < 10) break;
            if (cnt > INT_MAX/10) return 0;
            cnt = cnt*10;
            cur = cur / 10;
        }
        return (x>0) ? cnt : (-cnt);
    }
};
