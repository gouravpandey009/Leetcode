class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        
        //visited[i] = true -> ball has moved to i + 1 friend

        vector<bool> visited(n , false);

        int current = 0;


        visited[current] = true;

        int turn = 1;


        while(true){

            current = (current + turn * k) % n;

            if(visited[current])
            break;

            visited[current] = true;

            turn++;
        }

        vector<int> answer;

        for(int i = 0 ; i < n ; i++){
            if(!visited[i])
            answer.push_back(i + 1);
        }

        return answer;

        
    }
};