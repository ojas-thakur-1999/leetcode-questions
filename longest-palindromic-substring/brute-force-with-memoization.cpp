#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
    string longestPalindrome(string s) {
        if (s.size() == 0) {
            return "";
        }
        vector<vector<int>> memo_array;
        for (int i=0; i<s.size(); i++) {
            vector<int> temp;
            for (int j=0; j<s.size(); j++) {
                temp.push_back(-1);
            }
            memo_array.push_back(temp);
        }
        for (int size=s.size(); size>0; size--) {
            char buffer[size+1];
            buffer[size] = '\0';
            for (int j=0; j<size; j++) {
                buffer[j] = s[j];
            }
            string to_check = buffer;
            if (isPalindrome(to_check, memo_array, 0, size-1)) {
                return to_check;
            }
            for (int j=size; j<s.size(); j++) {
                for (int i=0; i<size-1; i++) {
                    buffer[i] = buffer[i+1];
                }
                buffer[size-1] = s[j];
                to_check = buffer;
                if (isPalindrome(to_check, memo_array, 0, size-1)) {
                    return to_check;
                }
            }
        }
        return to_string(s[0]);
    }

    int isPalindrome(string &str, vector<vector<int>> &memo_array, int start, int end) {
        if (memo_array[start][end] == -1) {
            if (start >= end) {
                memo_array[start][end] = 1;
            } else if (str[start] != str[end]) {
                memo_array[start][end] = 0;
            } else {
                memo_array[start][end] = isPalindrome(str, memo_array, start+1, end-1);
            }
        }
        return memo_array[start][end];
    }
};

int main() {
    Solution sol;
    string str = "gphyvqruxjmwhonjjrgumxjhfyupajxbjgthzdvrdqmdouuukeaxhjumkmmhdglqrrohydrmbvtuwstgkobyzjjtdtjroqpyusfsbjlusekghtfbdctvgmqzeybnwzlhdnhwzptgkzmujfldoiejmvxnorvbiubfflygrkedyirienybosqzrkbpcfidvkkafftgzwrcitqizelhfsruwmtrgaocjcyxdkovtdennrkmxwpdsxpxuarhgusizmwakrmhdwcgvfljhzcskclgrvvbrkesojyhofwqiwhiupujmkcvlywjtmbncurxxmpdskupyvvweuhbsnanzfioirecfxvmgcpwrpmbhmkdtckhvbxnsbcifhqwjjczfokovpqyjmbywtpaqcfjowxnmtirdsfeujyogbzjnjcmqyzciwjqxxgrxblvqbutqittroqadqlsdzihngpfpjovbkpeveidjpfjktavvwurqrgqdomiibfgqxwybcyovysydxyyymmiuwovnevzsjisdwgkcbsookbarezbhnwyqthcvzyodbcwjptvigcphawzxouixhbpezzirbhvomqhxkfdbokblqmrhhioyqubpyqhjrnwhjxsrodtblqxkhezubprqftrqcyrzwywqrgockioqdmzuqjkpmsyohtlcnesbgzqhkalwixfcgyeqdzhnnlzawrdgskurcxfbekbspupbduxqxjeczpmdvssikbivjhinaopbabrmvscthvoqqbkgekcgyrelxkwoawpbrcbszelnxlyikbulgmlwyffurimlfxurjsbzgddxbgqpcdsuutfiivjbyqzhprdqhahpgenjkbiukurvdwapuewrbehczrtswubthodv";
    string ans = sol.longestPalindrome(str);
    printf("input -> \"%s\"\n", str.c_str());
    printf("longestPalindrome -> \"%s\"\n", ans.c_str());
}