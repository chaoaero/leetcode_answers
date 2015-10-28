#include<string>
#include<iostream>
using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            if(numRows <= 1)
                return s;
            if( s.size() == 0)
                return s;
            string result;
            int total_len = s.size();
            bool flag = true;
            int step = 2 * (numRows - 1);
            for(int i = 0; i< numRows ; i++) {
                for(int j=i; j<total_len; j += step) {
                    //result += s[j];
                     result.append(1, s[j]);
                    if(i!=0 && i != numRows -1 && j + step - i * 2 < total_len) {
                         result.append(1, s[j + step - i * 2]);
                        //result += s[j + step - i * 2];
                    }
                }
            }
            return result;
        }

};

int main() {
    
    string s;
    int n;
    Solution sol;
    cin>>s;
    cout<<"=============\n";
    cout<<sol.convert(s, 3);
    return 0;
    


}
