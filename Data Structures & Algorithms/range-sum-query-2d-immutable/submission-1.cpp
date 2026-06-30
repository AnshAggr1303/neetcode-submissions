class NumMatrix {
public:
    vector<vector<int>> prefix;

    NumMatrix(vector<vector<int>>& matrix) {
        prefix = matrix;

        for(int i=0;i<prefix.size();i++){
            for(int j=1;j<prefix[0].size();j++){
                prefix[i][j] += prefix[i][j-1];
            }
        }

        for(int j=0;j<prefix[0].size();j++){
            for(int i=1;i<prefix.size();i++){
                prefix[i][j] += prefix[i-1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int left = 0, top = 0, overlap = 0;

        if(col1-1 >= 0)
            left = prefix[row2][col1-1];

        if(row1-1 >= 0)
            top = prefix[row1-1][col2];

        if(row1-1 >= 0 && col1-1 >= 0)
            overlap = prefix[row1-1][col1-1];

        return prefix[row2][col2] - left - top + overlap;
    }
};