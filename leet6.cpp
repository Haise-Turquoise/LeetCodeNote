#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.length()==1 || numRows == 1) return s;
        string ret = "";
        int sum = 2*numRows-2;
        for (int i = 0; i <= sum/2; i++) {
            int l = sum - 2*i;
            int r = sum - l;
            bool isl = true;
            int pos = i;
            if (l == 0) isl = false;
            while ( pos < s.length() ) {
                //cout << "pos (before): " << pos << endl;
                //cout << "l: " << l << " ; r: " << r << endl;
                ret.push_back(s[pos]);
                if ( isl ) {
                    pos+=l;
                    if (r!=0) isl = false;
                    //cout << "first cond " << endl;
                } else {
                    pos+=r;
                    if (l!=0) isl= true;
                    //cout << "second cond "<< endl;
                }
                //cout << "pos (after): " << pos << endl;
                
            }
        }
        return ret;
    }
};
/*
2*3-2=4;
0+4+4;
1+2+2;
2+3+3;

2*4-2=6 ;
0+6+0+6+0;
1+4+2+4+2+4;
2+2+4+2+4;
3+0+6+0+6;
4

*/
