#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }

        int max_len = 0;
        int start_idx = 0;
        for (int i=0; i<s.size(); i++) {
            int l, r;

            // check for odd length palindrome
            l = i;
            r = i;
            while (l >= 0 && r <= s.size()-1 && s[l] == s[r]) {
                if (r-l+1 > max_len) {
                    max_len = r-l+1;
                    start_idx = l;
                }
                l--;
                r++;
            }

            // check for even length palindrome
            l = i;
            r = i+1;
            while (l >= 0 && r <= s.size()-1 && s[l] == s[r]) {
                if (r-l+1 > max_len) {
                    max_len = r-l+1;
                    start_idx = l;
                }
                l--;
                r++;
            }
        }

        string longest_palindrome;
        for (int i=0; i<max_len; i++) {
            longest_palindrome += s[start_idx+i];
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