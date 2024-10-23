#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    
    int num = num_list.size();
    
    int row = num / n;
    int col = n;
    
    answer.resize(row, vector<int>(col, 0));
    
    for(int i = 0 ; i < row; i++)
    {
        for(int j = 0 ; j < col; j++)
        {
            answer[i][j] = num_list[i * n + j];
        }
    }
    
    return answer;
}