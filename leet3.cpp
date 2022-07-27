//#include <unordered_map>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()==0) return 0;
        unordered_set<char> hm;//unordered_map<char, int> hm;
        int tmp = 0;
        if (s.size() >=95 ) {
            tmp = 95;
        } else {
            tmp = s.size();
        }
        bool failwin = false;
        for (int winlen = tmp; winlen >=2; winlen--) {
             cout << winlen << endl;
            // check repeat in window, decide each leftmost of window
            for (int pos = 0; pos <= s.size()-winlen; pos++) {
                failwin = false;  // reset fail win for each window even in same size
                
                // check within window
                for (int i = pos; i <= pos+winlen-1; i++ ) {
                    if ( hm.find( s[i] ) != hm.end() ) { // found same char, check next window in same size
                        failwin = true;
                        break;
                    }
                    hm.insert(s[i]);//hm.insert( make_pair(s[i],0) );
                }
                hm.clear();
                if (failwin) {
                    continue;
                } else {
                    //for (auto x : hm) {cout << x << endl;}
                    return winlen;
                }
                
                
                
            }
            
        }
        return 1;
    }
};

// little faster method by computing the max possible window size
//#include <unordered_map>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()==0) return 0;
        unordered_set<char> hm;//unordered_map<char, int> hm;
        for (int j = 0; j < s.size(); j++) {
            hm.insert(s[j]);
        }
        int tmp = hm.size();
        hm.clear();
        bool failwin = false;
        for (int winlen = tmp; winlen >=2; winlen--) {
             cout << winlen << endl;
            // check repeat in window, decide each leftmost of window
            for (int pos = 0; pos <= s.size()-winlen; pos++) {
                failwin = false;  // reset fail win for each window even in same size
                
                // check within window
                for (int i = pos; i <= pos+winlen-1; i++ ) {
                    if ( hm.find( s[i] ) != hm.end() ) { // found same char, check next window in same size
                        failwin = true;
                        break;
                    }
                    hm.insert(s[i]);//hm.insert( make_pair(s[i],0) );
                }
                hm.clear();
                if (failwin) {
                    continue;
                } else {
                    //for (auto x : hm) {cout << x << endl;}
                    return winlen;
                }
                
                
                
            }
            
        }
        return 1;
    }
};
