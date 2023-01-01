#include<string>
#include<vector>
using namespace std;

void printMatrix(vector<vector<int>> &matrix) {
    for (int i=0; i<matrix.size(); i++) {
        printf("[ ");
        for (int j=0; j<matrix[i].size(); j++) {
            printf("%d, ", matrix[i][j]);
        }
        printf("]\n");
    }
}

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
        for (int substr_size=s.size(); substr_size>0; substr_size--) {
            // buffer for sliding window will have last character as '\0'
            int buffer_size = substr_size + 1;
            char buffer[buffer_size];
            buffer[buffer_size-1] = '\0';
            // populate sliding window for first time
            for (int j=0; j<buffer_size-1; j++) {
                buffer[j] = s[j];
            }
            string to_check = buffer;
            // give offset to isPalindrome() function to correctly populate memo_array
            if (isPalindrome(to_check, memo_array, 0, substr_size-1, 0)) {
                return to_check;
            }
            // shift the window to right one by one
            for (int j=substr_size; j<s.size(); j++) {
                // shift buffer elements left and introduce new element from right
                for (int i=0; i<buffer_size-2; i++) {
                    buffer[i] = buffer[i+1];
                }
                buffer[buffer_size-2] = s[j];
                to_check = buffer;
                // give offset to isPalindrome() function to correctly populate memo_array
                if (isPalindrome(to_check, memo_array, 0, substr_size-1, j-substr_size+1)) {
                    return to_check;
                }
            }
        }
        return to_string(s[0]);
    }

    int isPalindrome(string &str, vector<vector<int>> &memo_array, int start, int end, int offset) {
        if (memo_array[offset+start][offset+end] == -1) {
            if (start >= end) {
                memo_array[offset+start][offset+end] = 1;
            } else if (str[start] != str[end]) {
                memo_array[offset+start][offset+end] = 0;
            } else {
                memo_array[offset+start][offset+end] = isPalindrome(str, memo_array, start+1, end-1, offset);
            }
        }
        return memo_array[offset+start][offset+end];
    }

};

int main() {
    Solution sol;
    // string str = "gphyvqruxjmwhonjjrgumxjhfyupajxbjgthzdvrdqmdouuukeaxhjumkmmhdglqrrohydrmbvtuwstgkobyzjjtdtjroqpyusfsbjlusekghtfbdctvgmqzeybnwzlhdnhwzptgkzmujfldoiejmvxnorvbiubfflygrkedyirienybosqzrkbpcfidvkkafftgzwrcitqizelhfsruwmtrgaocjcyxdkovtdennrkmxwpdsxpxuarhgusizmwakrmhdwcgvfljhzcskclgrvvbrkesojyhofwqiwhiupujmkcvlywjtmbncurxxmpdskupyvvweuhbsnanzfioirecfxvmgcpwrpmbhmkdtckhvbxnsbcifhqwjjczfokovpqyjmbywtpaqcfjowxnmtirdsfeujyogbzjnjcmqyzciwjqxxgrxblvqbutqittroqadqlsdzihngpfpjovbkpeveidjpfjktavvwurqrgqdomiibfgqxwybcyovysydxyyymmiuwovnevzsjisdwgkcbsookbarezbhnwyqthcvzyodbcwjptvigcphawzxouixhbpezzirbhvomqhxkfdbokblqmrhhioyqubpyqhjrnwhjxsrodtblqxkhezubprqftrqcyrzwywqrgockioqdmzuqjkpmsyohtlcnesbgzqhkalwixfcgyeqdzhnnlzawrdgskurcxfbekbspupbduxqxjeczpmdvssikbivjhinaopbabrmvscthvoqqbkgekcgyrelxkwoawpbrcbszelnxlyikbulgmlwyffurimlfxurjsbzgddxbgqpcdsuutfiivjbyqzhprdqhahpgenjkbiukurvdwapuewrbehczrtswubthodv";
    string str = "abbcac";
    string ans = sol.longestPalindrome(str);
    printf("input -> \"%s\"\n", str.c_str());
    printf("longestPalindrome -> \"%s\"\n", ans.c_str());
}