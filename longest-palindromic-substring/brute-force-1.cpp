#include<string>
using namespace std;

class Solution {
    public:
    string longestPalindrome(string s) {
        if (s.size() == 0) {
            return "";
        }
        for (int size=s.size(); size>0; size--) {
            char buffer[size+1];
            buffer[size] = '\0';
            for (int j=0; j<size; j++) {
                buffer[j] = s[j];
            }
            string to_check = buffer;
            if (isPalindrome(to_check, 0, size-1)) {
                return to_check;
            }
            for (int j=size; j<s.size(); j++) {
                for (int i=0; i<size-1; i++) {
                    buffer[i] = buffer[i+1];
                }
                buffer[size-1] = s[j];
                to_check = buffer;
                if (isPalindrome(to_check, 0, size-1)) {
                    return to_check;
                }
            }
        }
        return to_string(s[0]);
    }

    bool isPalindrome(string &str, int start, int end) {
        if (start >= end) {
            return true;
        }
        if (str[start] != str[end]) {
            return false;
        }
        return isPalindrome(str, start+1, end-1);
    }
};

int main() {
    Solution sol;
    string str = "gphyvqruxjmwhonjjrgumxjhfyupajxbjgthzdvrdqmdouuukeaxhjumkmmhdglqrrohydrmbvtuwstgkobyzjjtdtjroqpyusfsbjlusekghtfbdctvgmqzeybnwzlhdnhwzptgkzmujfldoiejmvxnorvbiubfflygrkedyirienybosqzrkbpcfidvkkafftgzwrcitqizelhfsruwmtrgaocjcyxdkovtdennrkmxwpdsxpxuarhgusizmwakrmhdwcgvfljhzcskclgrvvbrkesojyhofwqiwhiupujmkcvlywjtmbncurxxmpdskupyvvweuhbsnanzfioirecfxvmgcpwrpmbhmkdtckhvbxnsbcifhqwjjczfokovpqyjmbywtpaqcfjowxnmtirdsfeujyogbzjnjcmqyzciwjqxxgrxblvqbutqittroqadqlsdzihngpfpjovbkpeveidjpfjktavvwurqrgqdomiibfgqxwybcyovysydxyyymmiuwovnevzsjisdwgkcbsookbarezbhnwyqthcvzyodbcwjptvigcphawzxouixhbpezzirbhvomqhxkfdbokblqmrhhioyqubpyqhjrnwhjxsrodtblqxkhezubprqftrqcyrzwywqrgockioqdmzuqjkpmsyohtlcnesbgzqhkalwixfcgyeqdzhnnlzawrdgskurcxfbekbspupbduxqxjeczpmdvssikbivjhinaopbabrmvscthvoqqbkgekcgyrelxkwoawpbrcbszelnxlyikbulgmlwyffurimlfxurjsbzgddxbgqpcdsuutfiivjbyqzhprdqhahpgenjkbiukurvdwapuewrbehczrtswubthodv";
    string ans = sol.longestPalindrome(str);
    printf("input -> \"%s\"\n", str.c_str());
    printf("longestPalindrome -> \"%s\"\n", ans.c_str());
}