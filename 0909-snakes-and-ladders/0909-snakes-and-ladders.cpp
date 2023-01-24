class Solution {
public:
    pair<int,int> coordinates(int curr,int n)
    {
        int r = n - (curr-1)/n -1;
        int c = (curr-1)%n;
        
        if(r%2 == n%2)
        {
            return {r,n-1-c};
        }
        else
        {
            return {r,c};
        }
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int>q;
        q.push(1);
        int steps = 0;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[n-1][0] = true;
        
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                int x = q.front();
                q.pop();

                if(x == n*n)
                {
                    return steps;
                }

                for(int k=1;k<=6;k++)
                {
                    if(x+k > n*n)
                    {
                        break;
                    }
                  pair<int,int>p = coordinates(x+k,n);
                    int r = p.first;
                    int c = p.second;

                    if(!visited[r][c])
                    {
                        visited[r][c] = true;
                        if(board[r][c] == -1)
                        {
                            q.push(k+x);
                        }
                        else
                        {
                            q.push(board[r][c]);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};