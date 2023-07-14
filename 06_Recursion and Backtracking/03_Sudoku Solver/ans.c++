// Question Link : https://leetcode.com/problems/sudoku-solver/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_poss(char ch, int i, int j, vector<set<char>> &row, vector<set<char>> &column, vector<vector<char>> &board)
    {
        // Checking Condition 1
        if (row[i].find(ch) != row[i].end())
        {
            // This means this ch exists in this row somewhere
            return false;
        }

        // Checking Condition 2
        if (column[j].find(ch) != column[j].end())
        {
            // This means this ch exists in this column somewhere
            return false;
        }

        // Checking Condition 3
        int box_start_row = 3 * (i / 3);
        int box_end_row = box_start_row + 2;

        int box_start_column = 3 * (j / 3);
        int box_end_column = box_start_column + 2;

        for (int x = box_start_row; x <= box_end_row; x++)
        {
            for (int y = box_start_column; y <= box_end_column; y++)
            {
                if (board[x][y] != '.' && board[x][y] == ch)
                {
                    return false;
                }
            }
        }

        return true;
    }

    void f(int index, int n, vector<vector<char>> &board, vector<set<char>> &row, vector<set<char>> &column, vector<pair<int, int>> &unfilled, vector<vector<char>> &ans)
    {
        if (index == n)
        {
            // This means now our board is completely filled
            ans = board;
            return;
        }

        for (char ch = '1'; ch <= '9'; ch++)
        {
            if (is_poss(ch, unfilled[index].first, unfilled[index].second, row, column, board) == true)
            {
                // Recursive step
                row[unfilled[index].first].insert(ch);
                column[unfilled[index].second].insert(ch);
                board[unfilled[index].first][unfilled[index].second] = ch;
                f(index + 1, n, board, row, column, unfilled, ans);

                // Backtracking step
                row[unfilled[index].first].erase(ch);
                column[unfilled[index].second].erase(ch);
                board[unfilled[index].first][unfilled[index].second] = '.';
            }
        }

        return;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        vector<set<char>> row(9), column(9);
        vector<pair<int, int>> unfilled;
        for (int i = 0; i < 9; i += 1)
        {
            for (int j = 0; j < 9; j += 1)
            {
                if (board[i][j] != '.')
                {
                    row[i].insert(board[i][j]);
                    column[j].insert(board[i][j]);
                }
                else
                {
                    unfilled.push_back({i, j});
                }
            }
        }

        vector<vector<char>> ans;
        f(0, unfilled.size(), board, row, column, unfilled, ans);
        board = ans;
        return;
    }
};