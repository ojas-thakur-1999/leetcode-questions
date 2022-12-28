#include<string>
#include<sstream>
using namespace std;

class Solution {
    public:
    string multiply(string num1, string num2) {
        stringstream obj;
        int len1 = num1.size();
        int num1_int[len1];
        for (int i=0; i<len1; i++) {
            string str = "";
            str.push_back(num1[i]);
            num1_int[i] = stoi(str);
        }
        int len2 = num2.size();
        int num2_int[len2];
        for (int i=0; i<len2; i++) {
            string str = "";
            str.push_back(num2[i]);
            num2_int[i] = stoi(str);
        }

        int buffer[len1+len2];
        for (int j=0; j<len1+len2; j++) {
            buffer[j] = 0;
        }
        for (int i=0; i<len2; i++) {
            // store single multiplication result here
            int product[len1+len2];
            for (int j=0; j<len1+len2; j++) {
                product[j] = 0;
            }
            
            // append zeros at the end of productś
            for (int j=0; j<i; j++) {
                product[len1+len2-1-j] = 0;
            }

            // multiply one digit at a time
            int carry = 0;
            for (int j=0; j<len1; j++) {
                int sum = carry + num1_int[len1-1-j]*num2_int[len2-1-i];
                carry = sum / 10;
                product[len1+len2-1-i-j] = sum % 10;
            }
            product[len1+len2-1-i-len1] = carry;

            // add product to buffer
            carry = 0;
            for (int j=0; j<len1+len2; j++) {
                int sum = carry + buffer[len1+len2-1-j] + product[len1+len2-1-j];
                carry = sum / 10;
                buffer[len1+len2-1-j] = sum % 10;
            }

            int a=6;
        }

        int start_idx = len1+len2-1;
        for (int i=0; i<len1+len2; i++) {
            if (buffer[i] != 0) {
                start_idx = i;
                break;
            }
        }
        string str;
        for (int i=start_idx; i<len1+len2; i++) {
            str += to_string(buffer[i]);
        }

        return str;
    }
};

int main() {
    Solution sol;
    string s1 = "987";
    string s2 = "12";
    string ans = sol.multiply(s1, s2);
    printf("length - %d\n", ans.size());
    printf("product - %s\n", ans.c_str());
}