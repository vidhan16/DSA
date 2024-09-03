class Solution {
public:
    int getDistance(char word1,char word2){
        if(word1 =='\0' || word2 == '\0')
        {
            return 0;
        }
        unordered_map<char,pair<int,int>>m;
        int count = 0;
        for(int i = 0 ; i < 5 ; i++)
        {
            for(int j = 0 ; j < 6 ; j++){
                m['A'+count] = {i,j};
                if(count == 25)
                {
                    break;
                }
                count++;
            }
        }

        return abs(m[word1].first - m[word2].first) + abs(m[word2].second - m[word1].second);
    }
    int backTrackMin(string word,int idx,char f1,char f2)
    {
        if(idx == word.size())
        {
            return 0;
        }

        int choice1 = getDistance(word[idx],f1) + backTrackMin(word,idx+1,word[idx],f2);
        int choice2 = getDistance(word[idx],f2) + backTrackMin(word,idx+1,f1,word[idx]);

        if(choice1 > choice2){
            return choice2;
        }
        return choice1;
    }
    int minimumDistance(string word) {
        return backTrackMin(word,0,'\0','\0');
    }
};