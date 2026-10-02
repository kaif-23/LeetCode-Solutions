class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> wordListSet(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int level = 1;
       
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string curr = q.front();
                q.pop();
                if (curr == endWord)
                    return level;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    for (int i = 0; i < curr.length(); i++) {
                        string niga = curr;
                        niga[i] = ch;
                        if (visited.find(niga) == visited.end() &&
                            wordListSet.find(niga) != wordListSet.end()) {
                            visited.insert(niga);
                            q.push(niga);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};