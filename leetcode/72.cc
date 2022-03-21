class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        int tmp, lu;
        for (int i = 0; i <= len2; i++)   dp[i] = i;

        for (int i = 1; i <= len1; i++){
            dp[0] = i;
            lu = i - 1;
            for (int j = 1; j <= len2; j++) {
                tmp = dp[j];
                if (word1[i - 1] == word2[j - 1]) dp[j] = lu;
                else {
                    dp[j] = min(dp[j], min(dp[j - 1], lu)) + 1;
                }
                lu = tmp;
            }
        }
        return dp[len2];
    }
private:
    int dp[501];
};
