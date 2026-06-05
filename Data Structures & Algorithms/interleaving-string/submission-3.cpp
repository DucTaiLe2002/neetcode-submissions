class Solution {
public:
    // Dùng mảng 2D để lưu kết quả đã tính (Memoization)
    int memo[101][101];

    bool search(const string &s1, const string &s2, const string &s3, int i1, int i2) {
        int i3 = i1 + i2;
        
        // Base case: Đã duyệt hết chuỗi s3
        if (i3 == s3.length()) return true;
        
        // Nếu đã tính toán vị trí này rồi thì trả về luôn
        if (memo[i1][i2] != -1) return memo[i1][i2];

        bool match1 = false, match2 = false;

        // Thử hướng s1
        if (i1 < s1.length() && s1[i1] == s3[i3]) {
            match1 = search(s1, s2, s3, i1 + 1, i2);
        }

        // Thử hướng s2 (Backtracking ở đây: không dùng 'else if')
        if (i2 < s2.length() && s2[i2] == s3[i3]) {
            match2 = search(s1, s2, s3, i1, i2 + 1);
        }

        return memo[i1][i2] = (match1 || match2);
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        
        // Init memo table với -1
        for(int i = 0; i <= s1.length(); i++)
            for(int j = 0; j <= s2.length(); j++)
                memo[i][j] = -1;

        return search(s1, s2, s3, 0, 0);
    }
};