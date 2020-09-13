/*Given a rows x cols screen and a sentence represented by a list of non-empty words, find how many times the given sentence can be fitted on the screen.

Note:

A word cannot be split into two lines.
The order of words in the sentence must remain unchanged.
Two consecutive words in a line must be separated by a single space.
Total words in the sentence won't exceed 100.
Length of each word is greater than 0 and won't exceed 10.
1 ≤ rows, cols ≤ 20,000.
Example 1:

Input:
rows = 2, cols = 8, sentence = ["hello", "world"]

Output: 
1

Explanation:
hello---
world---

The character '-' signifies an empty space on the screen.
Example 2:

Input:
rows = 3, cols = 6, sentence = ["a", "bcd", "e"]

Output: 
2

Explanation:
a-bcd- 
e-a---
bcd-e-

The character '-' signifies an empty space on the screen.
Example 3:

Input:
rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]

Output: 
1

Explanation:
I-had
apple
pie-I
had--

The character '-' signifies an empty space on the screen.
Last Submission
Last Saved Code */
class Solution {
public:
    class node{
        public:
        int rows,start,freq;
        node(int a,int b,int c){
            rows = a;
            start = b;
            freq = c;            
        }
    };
    node simulate(int start,vector<string> &sentences,int cols){
        int rows = 0;
        int freq = 0;
        int req = 0;
        for(string &s:sentences){
            if(start + s.length() - 1 >= cols)
                rows++, start = s.length()+1;
            else
                start += s.length()+1; 
            req += s.length() + 1;
                
        }
        if(rows==0)
            freq = (cols - start + 1)/req, start += freq*req;
        freq++;
        return node(rows,start,freq);
    }
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        for(string &s:sentence){
            if(s.length()>cols)
                return 0;
        }
        vector<node> dp(cols,node(-1,-1,-1));
        int cnt = 0;
        int c=0,r=0;
        while(r<rows){
            if(dp[c].start==-1){
                dp[c] = simulate(c,sentence,cols);
            }
            if(r+dp[c].rows<rows)
                cnt+=dp[c].freq;
            else
                break;
            r += dp[c].rows;
            c = dp[c].start;
            if(c>=cols)
                c = 0, r++;
        }
        return cnt;
        
    }
};
