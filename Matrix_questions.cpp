/**
//Diagonally Traversal//Check shape
// 1     2     3     4
// 5     6     7     8
// 9    10    11    12
// 13    14    15    16
// 17    18    19    20

// 1
// 5 2
// 9 6 3
// 13 10 7 4
// 17 14 11 8
// 18 15 12
// 19 16
// 20

#include<iostream>
#include<vector>
using namespace std;

void diagonalOrder(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    for (int k = 0; k < n; k++){
        int i = k, j = 0;
        while (i>=0 && j<m){
            cout << mat[i][j] << " ";
            i--;
            j++;
        }
        cout << endl;
    }
    for (int k = 1; k < m; k++){
        int i = n - 1, j = k;
        while(i>=0 && j<m){
            cout << mat[i][j] << " ";
            i--;
            j++;
        }
        cout << endl;
    }
}

int main()
{

    vector<vector<int>> mat = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 },
        { 17, 18, 19, 20 },
    };
    diagonalOrder(mat);

    return 0;
}
/*
// Diagonally Traversal//Check shape
//  1     2     3     4
//  5     6     7     8
//  9    10    11    12
//  13    14    15    16
//  17    18    19    20

// 1 
// 2 5        
// 3 6 9      
// 4 7 10 13  
// 8 11 14 17 
// 12 15 18   
// 16 19      
// 20

#include <iostream>
#include <vector>
using namespace std;

void antiDiagonalPattern(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();
    for (int k = 0; k < m; k++)
    {
        int i = 0, j = k;
        while (i < n && j >= 0)
        {
            cout << matrix[i][j] << " ";
            i++;
            j--;
        }
        cout << endl;
    }
    for (int k = 1; k < n; k++)
    {
        int i = k, j = m - 1;
        while (i < n && j >= 0)
        {
            cout << matrix[i][j] << " ";
            i++;
            j--;
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
    };

    antiDiagonalPattern(matrix);

    return 0;
}

/*
//UpDown Diagonally Traversal//Check shape
// 1     2     3     4
// 5     6     7     8
// 9    10    11    12
// 13    14    15    16
// 17    18    19    20

//1 2 5 9 6 3 4 7 10 13 17 14 11 8 12 15 18 19 16 20
//Worst solution
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         int m=mat.size();
         int n=mat[0].size();

         map<int, vector<int>> mp;
         vector<int> ans;

         for(int i=0; i<m; i++){
             for(int j=0; j<n; j++){
                 mp[i+j].push_back(mat[i][j]);
             }
         }

         bool flip=true;
         for(auto &it : mp){
             if(flip){
                 reverse(it.second.begin(), it.second.end());
             }
             for(auto &num : it.second){
                 ans.push_back(num);
             }
             flip = !flip;
         }

         return ans;
    }

int main()
{
    vector<vector<int>> mat =  {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 },
        { 17, 18, 19, 20 },
    };
    vector<int> result = matrixDiagonally(mat);

    for (auto it : result) {
        cout << it << " ";
    }
    return 0;
}
/**
//UpDown Diagonally Traversal//Check shape

//UpDown Diagonally Traversal//Check shape
// 1     2     3     4
// 5     6     7     8
// 9    10    11    12
// 13    14    15    16
// 17    18    19    20

//1 2 5 9 6 3 4 7 10 13 17 14 11 8 12 15 18 19 16 20
//Best solution
#include<iostream>
#include<vector>
using namespace std;

vector<int> matrixDiagonally(vector<vector<int>> mat){
	int n = mat.size();
	int m = mat[0].size();
	int row = 0;
	int col = 0;
	int idx = 0;
	vector<int> ans(n*m);
	bool up = true;

	while(row<n && col<m){
		if(up){
			while(row>0 && col<m-1){
				ans[idx++] = mat[row][col];
				row--;
				col++;
			}
			ans[idx++] = mat[row][col];
			if(col==m-1){
				row++;
			}
			else{
				col++;
			}
			up = !up;
		}
		else{
			while(row<n-1 && col>0){
				ans[idx++] = mat[row][col];
				row++;
				col--;
			}
			ans[idx++] = mat[row][col];
			if(row==n-1){
				col++;
			}
			else{
				row++;
			}
			up = !up;
		}
	}
	return ans;
}

int main()
{
	vector<vector<int>> mat =  {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 },
        { 17, 18, 19, 20 },
    };
    vector<int> result = matrixDiagonally(mat);

    for (auto it : result) {
        cout << it << " ";
    }

	return 0;
}
/**
//SetZeroes
//BrutForce Aproach
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int r = 0; r < m; r++)
                {
                    if (matrix[r][j] != 0)
                    {
                        matrix[r][j] = -999;
                    }
                }
                for (int c = 0; c < n; c++)
                {
                    if (matrix[i][c] != 0)
                    {
                        matrix[i][c] = -999;
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -999)
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int main()
{
    
    vector<vector<int>> matrix =  {
        { 1, 1, 1},
        { 1, 0, 1},
        { 1, 1, 1},
    };

    vector<vector<int>> result = setZeroes(matrix);

    for (auto vec : result) {
        for(auto it: vec){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}

/**
//SetZeroes Better Aproach
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }

        return matrix;
    }

int main()
{
    vector<vector<int>> matrix =  {
        { 1, 1, 1},
        { 1, 0, 1},
        { 1, 1, 1},
    };

    vector<vector<int>> result = setZeroes(matrix);

    for (auto vec : result) {
        for(auto it: vec){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}

/**
//SetZeroes
// Setzeroes Optimal aproach
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // vector<int> row(m, 0); -> matrix[...][0]
        // vector<int> col(n, 0); -> matrix[0][...]
        int col0 = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    //Mark the i-th row
                    matrix[i][0] = 0;
                    //Mark the j-th col
                    if (j != 0) {
                        matrix[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if(matrix[i][j]!=0){
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }

        return matrix;
    }

int main()
{
    vector<vector<int>> matrix =  {
        { 1, 1, 1},
        { 1, 0, 1},
        { 1, 1, 1},
    };
    // vector<vector<int>> matrix =  {
    //     { 0, 1, 2, 0},
    //     { 3, 4, 5, 2},
    //     { 1, 3, 1, 5},
    // };

    vector<vector<int>> result = setZeroes(matrix);

    for (auto vec : result) {
        for(auto it: vec){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}

/**
//Spiral order traversal
#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, top = 0, right = n - 1, bottom = m - 1;
        vector<int> ans;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }

int main()
{
    vector<vector<int>> matrix =  {
        { 1, 2, 3},
        { 4, 5, 6},
        { 7, 8, 9},
    };

    vector<int> result = spiralOrder(matrix);

    for (auto it : result) {
        cout << it << " ";
    }
    return 0;
}

/**
//Rotate image
//Brut force aproach
#include<iostream>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][n - 1 - i] = matrix[i][j];
            }
        }

        return ans;
    }

int main()
{
    return 0;
}

/**
//Rotate image
//OPtimal aproach
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> rotateImage(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        return matrix;
    }

int main()
{
    vector<vector<int>> matrix = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	};

	vector<vector<int>> result = rotateImage(matrix);

	for (auto vec : result)
	{
		for (auto it : vec)
		{
			cout << it << " ";
		}
		cout << endl;
	}
    return 0;
}

/**
//Word search
#include<iostream>
#include<vector>
using namespace std;

bool bfs(vector<vector<char>>& board, string word, int i, int j, int n,
                int m, int k, vector<vector<bool>>& visited) {
        if (k >= word.size()) {
            return true;
        }
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] ||
            word[k] != board[i][j]) {
            return false;
        }
        visited[i][j] = true;
        bool temp = false;
		int x[4] = {-1, 0, 1, 0};
		int y[4] = {0, 1, 0, -1};
		for (int it = 0; it < 4; it++){
			int nrow = i + x[it];
			int ncol = j + y[it];
			temp = temp || bfs(board, word, nrow, ncol, n, m, k + 1, visited);
		}
		visited[i][j] = false;
        return temp;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if (n == 0) {
            return false;
        }
        int m = board[0].size();
        if (m == 0) {
            return false;
        }
        if (word.size() == 0) {
            return false;
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (bfs(board, word, i, j, n, m, 0, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word1 = "ABCCED";
    string word2 = "SEE";
    string word3 = "ABCB";
    string word4 = "ABCF";

    cout << exist(board, word1) << endl; // Output: 1 (true)
    cout << exist(board, word2) << endl; // Output: 1 (true)
    cout << exist(board, word3) << endl; // Output: 0 (false)
    cout << exist(board, word4) << endl; // Output: 0 (false)
	
    return 0;
}
/*
//islands
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bf(int i, int j, vector<vector<char>>& grid, int n, int m, vector<vector<int>> &vis){
        vis[i][j]=1;
        queue<pair<int, int>> q;
        q.push({i, j});

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int delrow=-1; delrow<=1; delrow++){
                for(int delcol=-1; delcol<=1; delcol++){
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int count=0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col]=='1' && !vis[row][col]){
                    count++;
                    bf(row, col, grid, n, m, vis);
                }
            }
        }
        return count;
    }

int main()
{
    vector<vector<char>> grid = {
		{'1', '1', '0', '0', '0'},
		{'0', '1', '0', '0', '1'},
        {'1', '0', '0', '1', '1'},
        {'0', '0', '0', '0', '0'},
        {'1', '0', '1', '0', '0'},
	};

    cout << numIslands(grid) << endl;
    return 0;
}
/**
#include<iostream>
using namespace std;
int main()
{
    return 0;
}
/**
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bf(vector<vector<char>>& mat, int i, int j, int n, int m, vector<vector<int>> &vis){
        vis[i][j]=1;
        queue<pair<int, int>> q;
        q.push({i, j});

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int delrow=-1; delrow<=1; delrow++){
                for(int delcol=-1; delcol<=1; delcol++){
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    mat[nrow][ncol]=='O' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

vector<vector<char>> replaceOX(vector<vector<char>> &mat){
    int n=mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    //First Row
    for (int i = 0; i < m; i++){
        if(mat[0][i]=='O' && !vis[0][i]){
            bf(mat, 0, i, n, m, vis);
        }
    }
    //First column
    for (int i = 1; i < n; i++){
        if (mat[i][0] == 'O' && !vis[i][0]){
            bf(mat, i, 0, n, m, vis);
        }
    }
    //Last row
    for (int i = 1; i < m; i++){
        if(mat[n-1][i]=='O' && !vis[n-1][i]){
            bf(mat, n-1, i, n, m, vis);
        }
    }
    //last column
    for (int i = 1; i < n-1; i++){
        if (mat[i][m-1] == 'O' && !vis[i][m-1]){
            bf(mat, i, m-1, n, m, vis);
        }
    }

    //BFS Traversal
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mat[i][j] == 'O' && !vis[i][j]){
                mat[i][j] = 'X';
            }
        }
    }

    return mat;
}

int main()
{
    vector<vector<char>> mat =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                                 {'X', 'O', 'X', 'X', 'O', 'X'},
                                 {'X', 'X', 'X', 'O', 'O', 'X'},
                                 {'O', 'X', 'X', 'X', 'X', 'X'},
                                 {'X', 'X', 'X', 'O', 'X', 'O'},
                                 {'O', 'O', 'X', 'O', 'O', 'O'},
                            };

    vector<vector<char>> result = replaceOX(mat);

    for (auto vec : result)
	{
		for (auto it : vec)
		{
			cout << it << " ";
		}
		cout << endl;
	}

    return 0;
}
/**
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

void CommonElements(vector<vector<int>> mat){
    int n = mat.size();
    int m = mat[0].size();
    unordered_map<int, int> mp;

    for (int i = 0; i < m; i++){
        mp[mat[0][i]] = 1;
    }

    for (int i = 1; i < n; i++){
        for (int j = 0; j < m; j++){
            if(mp[mat[i][j]]==i){
                mp[mat[i][j]]++;
            }
        }
    }
    
    for (int i = 0; i < m; i++){
        if(mp[mat[0][i]] == n){
            cout << mat[0][i] << " ";
        }
    }
}

int main()
{
    vector<vector<int>> mat={ 
	                    	{ 1, 2, 3, 4, 5 }, 
	                    	{ 2, 4, 5, 8, 10 }, 
	                    	{ 3, 5, 7, 9, 11 }, 
	                    	{ 1, 3, 5, 7, 9 }, 
	                    };

    CommonElements(mat);
    return 0;
}
/*
#include<iostream>
#include<vector>
using namespace std;

void alternateOX(int m, int n) {
    int left = 0, top = 0, right = n - 1, bottom = m - 1;
    char ans[m][n];
    char x = 'X';

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
            ans[top][i] = x;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            ans[i][right] = x;
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans[bottom][i] = x;
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans[i][left] = x;
            }
            left++;
        }

        x = (x == 'O') ? 'X' : 'O';
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    alternateOX(m, n);

    return 0;
}
/*
//Largest Rectangle Area in Hestogram
//Brut forse aproach
#include<iostream>
using namespace std;
#include<vector>
#include<stack>

int largestRectangleArea(vector<int> &heights){
    int n = heights.size();
    stack<int> st;
    int leftsmall[n], rightsmall[n];

    for (int i = 0; i < n; i++){
        while (!st.empty() && heights[st.top()]>=heights[i]){
            st.pop();
        }
        if(st.empty()){
            leftsmall[i] = 0;
        }
        else{
            leftsmall[i] = st.top() + 1;
        }
        st.push(i);
    }

    while(!st.empty()){
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--){
        while (!st.empty() && heights[st.top()]>=heights[i]){
            st.pop();
        }
        if(st.empty()){
            rightsmall[i] = n-1;
        }
        else{
            rightsmall[i] = st.top() - 1;
        }
        st.push(i);
    }

    int mxA = 0, a = 0;
    for (int i = 0; i < n; i++){
        a = (rightsmall[i] - leftsmall[i] + 1) * heights[i];
        mxA = max(mxA, a);
    }

    return mxA;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 4, 1};
    cout << largestRectangleArea(heights) << endl;
    
    return 0;
}
/**
//Largest Rectangle Area in Hestogram
//Optimal aproach
#include<iostream>
using namespace std;
#include<vector>
#include<stack>

int largestRectangleArea(vector<int> &histo){
    int n = histo.size();
    stack<int> st;
    int mxA = 0;
    for (int i = 0; i <= n; i++){
        while(!st.empty() && (i==n || histo[st.top()]>=histo[i])){
            int hieght = histo[st.top()];
            st.pop();
            int width;
            if(st.empty()){
                width = i;
            }
            else{
                width = i - st.top() - 1;
            }
            mxA = max(mxA, hieght * width);
        }
        st.push(i);
    }
    return mxA;
}

int main()
{
    vector<int> histo = {3, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(histo) << endl;

    return 0;
}
/*
//Largest Rectangle Area in Submatrix
//Optimal aproach
#include<iostream>
using namespace std;
#include<vector>
#include<stack>

int largestRectangleArea(vector<int> histo){
    int n = histo.size();
    stack<int> st;
    int mxA = 0;
    for (int i = 0; i <= n; i++){
        while(!st.empty() && (i==n || histo[st.top()]>=histo[i])){
            int hieght = histo[st.top()];
            st.pop();
            int width;
            if(st.empty()){
                width = i;
            }
            else{
                width = i - st.top() - 1;
            }
            mxA = max(mxA, hieght * width);
        }
        st.push(i);
    }
    return mxA;
}

int largestRectangleAreaInMatrixOfAll1(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<int> hieghts(m, 0);
    int mxA = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(mat[i][j]==1){
                hieghts[j]++;
            }
            else{
                hieghts[j]=0;
            }
        }
        int area = largestRectangleArea(hieghts);
        mxA = max(mxA, area);
    }
    return mxA;
}

int main()
{
    vector<vector<int>> mat={ 
	                    	{ 0, 1, 1, 0 }, 
	                    	{ 1, 1, 1, 1 }, 
	                    	{ 1, 1, 1, 1 }, 
	                    	{ 1, 1, 0, 0 }, 
	                    };

    cout << largestRectangleAreaInMatrixOfAll1(mat) << endl;

    return 0;
}
/*
//Smallest distance of next cell
//TC(m*n)   SC(m*n)
vector<vector<int>> nearest(vector<vector<int>>& grid) {
    // Code here
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1){
                q.push({{i, j}, 0});
                vis[i][j]=1;
            }
        }
    }

    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};

    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int steps=q.front().second;

        q.pop();
        dist[row][col]=steps;

        for(int i=0; i<4; i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                q.push({{nrow, ncol}, steps+1});
                vis[nrow][ncol]=1;
            }
        }
    }

    return dist;
}
*/
/*
//Rotten orange
//TC(m*n)   SC(m*n)

int orangesRotting(vector<vector<int>>& grid) {
        // Code here
    int n=grid.size();
    int m=grid[0].size();
    int ans=0;

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==2){
                q.push({{i, j}, 0});
                vis[i][j]=1;
            }
        }
    }

    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};

    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int steps=q.front().second;

        q.pop();
        dist[row][col]=2;
        ans=steps;

        for(int i=0; i<4; i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                q.push({{nrow, ncol}, steps+1});
                vis[nrow][ncol]=1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1 && dist[i][j]==0){
                return -1;
            }
        }
    }

    return ans;
    }
*/
/**/