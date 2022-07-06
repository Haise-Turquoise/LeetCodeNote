#include <cmath>
class Solution {
public: // consider ++++---
    int myAtoi(string s) {
        vector <int> v;
        bool sign = true, hasSign = false, lead0 = false, chunk = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i]==' ') {
                if (lead0) {
                    return 0;
                } else if (chunk) {
                    break;
                } else {
                    continue;
                }
            }
            cout << "chunk: " << chunk << endl;
            if (s[i]=='-') {
                cout << '-' << endl;
                if (chunk) break;
                if (lead0||hasSign)  return 0;        
                sign = false; hasSign = true; continue;
            } else if ( s[i]=='+' || ( s[i]>='0' && s[i]<='9' )) {
                if (s[i]=='+') {
                    cout << '+' << endl;
                    if (chunk) break;
                    if (lead0) return 0;
                    if (hasSign) return 0;
                    hasSign = true;
                    continue;
                }
                if ( s[i]>='0' && s[i]<='9' ) {
                    cout << "0-9" << endl;
                    chunk = true;
                    if (s[i]=='0'&&v.empty()) {
                        lead0 = true;
                        continue;
                    }
                    int digit = s[i] + 1 - '1';
                    v.push_back(digit);
                } 
                
            } else {
                break;
            }
        }
        if (v.size() > 10) return (sign)? INT_MAX : INT_MIN;
        if ((v.size() == 10) && (v[0]>2)) return (sign)? INT_MAX : INT_MIN;
        int cnt = 0;
        for (int i = v.size()-1; i>=0; i--) {
            if ( ( (!sign) && (cnt == 147483648) ) && v[0]==2  ) return INT_MIN;
            if (  cnt > INT_MAX - v[i]*pow(10, v.size()-1-i ) ) return (sign)? INT_MAX : INT_MIN;
            cnt += v[i]*pow(10, v.size()-1-i );
            cout << "cnt: " << cnt << endl;
        }
        return (sign)? cnt : -cnt;
    }
};
