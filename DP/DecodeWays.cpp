//link:https://www.codingninjas.com/codestudio/problems/decode-ways_1092345?leftPanelTab=2
int decodeWays(string strNum) {
    int mod = 1e9+7;
    int n = strNum.size();
    vector<int> count(n + 1, 0);
    count[0] = 1;
    count[1] = 1;

    for (int i = 2; i < n + 1; i++) {
        count[i] = 0;

        if (strNum[i - 1] > '0') {
            count[i] = count[i - 1] % mod;
        }

        // If number is '11-19' or '21-26'
        if (strNum[i - 2] == '1' or
            (strNum[i - 2] == '2' and
             strNum[i - 1] < '7')) {
            count[i] += count[i - 2];
        }

        count[i] = count[i] % mod;
    }

    return count[n] % mod;
}
