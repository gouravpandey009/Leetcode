using ll = long long;


class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        ll m = classroom.size();
        ll n = classroom[0].size();


        ll sX = 0 , sY = 0;
        ll lcount = 0;
        ll fnlMask = 0;

        ll id[21][21] = {0};

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(classroom[i][j] == 'S'){
                    sX = i;
                    sY = j;
                } else if (classroom[i][j] == 'L'){
                    fnlMask |= (1LL << lcount);
                    id[i][j] = lcount;
                    lcount++;
                }
            }
        }

        vector<vector<vector<vector<int>>>> state(m , vector<vector<vector<int>>>(
            n , vector<vector<int>>(
                energy + 1 , vector<int>(1 << lcount , -1)
            )
        )
        );

        queue<tuple<ll, ll, ll, ll>> q;

        state[sX][sY][energy][0] = 0;
        q.push({sX, sY, energy, 0});

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y, e, mask] = q.front();
            q.pop();

            int moves = state[x][y][e][mask];

            if (mask == fnlMask) {
                return moves;
            }

            for (int dir = 0; dir < 4; dir++) {
                ll nx = x + dx[dir];
                ll ny = y + dy[dir];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                if (classroom[nx][ny] == 'X')
                    continue;

                if (e == 0)
                    continue;

                ll ne = e - 1;
                ll nmask = mask;

                if (classroom[nx][ny] == 'L') {
                    nmask |= (1LL << id[nx][ny]);
                }

                if (classroom[nx][ny] == 'R') {
                    ne = energy;
                }

                if (state[nx][ny][ne][nmask] != -1)
                    continue;

                state[nx][ny][ne][nmask] = moves + 1;
                q.push({nx, ny, ne, nmask});
            }
        }

        return -1;
    }

};