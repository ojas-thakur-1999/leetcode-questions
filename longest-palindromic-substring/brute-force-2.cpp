#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }

        int max_len = 0;
        string longest_palindrome;
        for (int i=0; i<s.size(); i++) {
            int l, r;

            // check for odd length palindrome
            l = i;
            r = i;
            while (l >= 0 && r <= s.size()-1 && s[l] == s[r]) {
                int curr_len = r-l+1;
                if (curr_len > max_len) {
                    max_len = curr_len;
                    string temp;
                    for (int j=l; j<= r; j++) {
                        temp += s[j];
                    }
                    longest_palindrome = temp;
                }
                l--;
                r++;
            }

            // check for even length palindrome
            l = i;
            r = i+1;
            while (l >= 0 && r <= s.size()-1 && s[l] == s[r]) {
                int curr_len = r-l+1;
                if (curr_len > max_len) {
                    max_len = curr_len;
                    string temp;
                    for (int j=l; j<= r; j++) {
                        temp += s[j];
                    }
                    longest_palindrome = temp;
                }
                l--;
                r++;
            }
        }

        return longest_palindrome;
    }
};

int main() {
    Solution sol;
    string str = "gphyvqruxjmwhonjjrgumxjhfyupajxbjgthzdvrdqmdouuukeaxhjumkmmhdglqrrohydrmbvtuwstgkobyzjjtdtjroqpyusfsbjlusekghtfbdctvgmqzeybnwzlhdnhwzptgkzmujfldoiejmvxnorvbiubfflygrkedyirienybosqzrkbpcfidvkkafftgzwrcitqizelhfsruwmtrgaocjcyxdkovtdennrkmxwpdsxpxuarhgusizmwakrmhdwcgvfljhzcskclgrvvbrkesojyhofwqiwhiupujmkcvlywjtmbncurxxmpdskupyvvweuhbsnanzfioirecfxvmgcpwrpmbhmkdtckhvbxnsbcifhqwjjczfokovpqyjmbywtpaqcfjowxnmtirdsfeujyogbzjnjcmqyzciwjqxxgrxblvqbutqittroqadqlsdzihngpfpjovbkpeveidjpfjktavvwurqrgqdomiibfgqxwybcyovysydxyyymmiuwovnevzsjisdwgkcbsookbarezbhnwyqthcvzyodbcwjptvigcphawzxouixhbpezzirbhvomqhxkfdbokblqmrhhioyqubpyqhjrnwhjxsrodtblqxkhezubprqftrqcyrzwywqrgockioqdmzuqjkpmsyohtlcnesbgzqhkalwixfcgyeqdzhnnlzawrdgskurcxfbekbspupbduxqxjeczpmdvssikbivjhinaopbabrmvscthvoqqbkgekcgyrelxkwoawpbrcbszelnxlyikbulgmlwyffurimlfxurjsbzgddxbgqpcdsuutfiivjbyqzhprdqhahpgenjkbiukurvdwapuewrbehczrtswubthodv";
    string ans = sol.longestPalindrome(str);
    printf("input -> \"%s\"\n", str.c_str());
    printf("longestPalindrome -> \"%s\"\n", ans.c_str());
}