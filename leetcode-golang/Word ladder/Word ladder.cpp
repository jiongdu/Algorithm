class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        queue<string> q{{beginWord}};
        int res = 0;
        while(!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return res + 1;
                }
                for (int i = 0; i < word.size(); i++) {         //每次只改动1位
                    string newWord = word;
                    for (char ch = 'a'; ch <= 'z'; ch++) {      
                        newWord[i] = ch;
                        if (wordSet.count(newWord) && newWord != word) {
                            q.push(newWord);
                            wordSet.erase(newWord);             //放入队列之后，在wordSet中删掉newWord，防止经过多重变换后过来的
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
};