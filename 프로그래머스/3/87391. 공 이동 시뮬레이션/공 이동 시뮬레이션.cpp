#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> dy = {0, 0, -1, 1};
vector<int> dx = {-1, 1, 0, 0};

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = 0;
    
    long long X = y;
    long long Y = x;
    
    long long up = Y;
    long long down = Y;
    long long left = X;
    long long right = X;
    
    for(int i = queries.size()-1; i >= 0; i--)
    {
        auto query = queries[i];
        
        //l, r, u, d
        if((query[0]==0 && left==0) || (query[0]==1 && right==m-1) || (query[0]==2 && up==0) || (query[0]==3 && down==n-1))
        {
            //plus
            switch(query[0])
            {
                case 0:
                    right = right + query[1] >= m ? m-1 : right + query[1];
                    break;
                case 1:
                    left = left - query[1] < 0 ? 0 : left - query[1];
                    break;
                case 2:
                    down = down + query[1] >= n ? n-1 : down + query[1];
                    break;
                case 3:
                    up = up - query[1] < 0 ? 0 : up -query[1];
                    break;
            }
        }
        else
        {
            //move
            switch(query[0])
            {
                case 0:
                    right = right+query[1] >= m ? m-1 : right+query[1];
                    left = left+query[1];
                    if(left >= m) return 0;
                    break;
                case 1:
                    right = right-query[1];
                    left = left-query[1] < 0 ? 0 : left-query[1];
                    if(right < 0) return 0;
                    break;
                case 2:
                    up = up+query[1] >= n ? n-1 : up+query[1];
                    down = down+query[1] >= n ? n-1 : down+query[1];
                    break;
                case 3:
                    up = up-query[1] < 0 ? 0 : up-query[1];
                    down = down-query[1] < 0 ? 0 : down-query[1];
                    break;
            }
        }
    }

    answer = (down - up + 1) * (right - left + 1);
    
    return answer;
}