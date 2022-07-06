using namespace std;
#include <iostream>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int llen = strs.size();
        string mins = strs[0];
        for (size_t i = 0; i < llen; i++) {
            if (strs[i].length() < mins.length()) {
                mins = strs[i];
            }
        }
        int rec = -1;
        bool stop = false;
        for (size_t i = 0; i < mins.length(); i++) {
            for (size_t j = 0; j < strs.size(); j++) {
                //cout << "i: " << i << " ;j: " << j << endl;
                if (strs[j][i] != mins[i]) {
                    stop = true;
                    break;
                }
            }
            if (stop) break;
            rec++;
        }
        if (rec == -1) return "";
        string ret = "";
        //cout << "rec: " << rec << endl;
        for (size_t i = 0; i <= rec; i++) {
            ret.push_back(mins[i]);
        }
        return ret;
    }  
};
