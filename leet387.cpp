class Solution {
public:
    int firstUniqChar(string s) {
        bool exist = true;
        for ( int i = 0; i < s.size(); i++ ) {
            exist = true;
            for ( int j = 0; j < s.size(); j++ ) {
                if (i!=j) {
                    if ( s.at(i) == s.at(j) ) {
                        exist = false;
                        break;
                    }
                }
            }
            if (exist) return i;
        }
        return -1;
    }
};
