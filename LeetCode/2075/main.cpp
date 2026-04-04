class Solution {
public:

    string rstrip(const string& s) {
        int i = s.size() - 1;

        while (i >= 0 && isspace(static_cast<unsigned char>(s[i]))) {
            i--;
        }

        return s.substr(0, i + 1);
    }

    string decodeCiphertext(string enc, int nRows) {
        int n = enc.length();
        if (nRows == 1) return enc;

        int nCols = n / nRows;
        string ans;
        ans.reserve(n);

        // Instead of building matrix, we'll use row-major indexing :
        // mat[r][c] -> enc[r * nCols + c]

        for (int start = 0; start < nCols; ++start) {
            int r = 0, c = start;

            while (r < nRows && c < nCols) {
                ans += enc[r * nCols + c];
                r++;
                c++;
            }
        }

        return rstrip(ans);
    }
};

class Solution {
public:

    string rstrip(const string& s) {
        int i = s.size() - 1;

        while (i >= 0 && isspace(static_cast<unsigned char>(s[i]))) {
            i--;
        }

        return s.substr(0, i + 1);
    }

    string decodeCiphertext(string enc, int nRows) {
        int n = enc.length(), nCols = n / nRows, ptr = 0;
        vector<vector<char>> mat(nRows, vector<char>(nCols, '0'));
        string ans;
        for(int i = 0; i < nRows; ++i) {
            for(int j = 0; j < nCols; ++j) {
                mat[i][j] = enc[ptr];
                ptr++;
            }
        }

        for(int start = 0; start < nCols; ++start) {
            int i = 0, j = start;
            while(i < nRows && j < nCols) {
                ans += mat[i][j];
                i++;
                j++;
            }
        }

        return rstrip(ans);
    }
};