class Solution {
public:
    int converter(string date) {

        vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string monthStr = {date[0] , date[1]};
        int month = stoi(monthStr);

        string dayStr = {date[3] , date[4]};
        int day = stoi(dayStr);

        int count = 0;
        for(int i = 0 ; i < month - 1; i++){
            count += daysInMonths[i];
        }

        return count + day;
        
    }


    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob){
        int startAlice = converter(arriveAlice);
        int endAlice = converter(leaveAlice);
        int startBob = converter(arriveBob);
        int endBob = converter(leaveBob);

        int overLapStart = max(startAlice , startBob);
        int overLapEnd = min(endAlice , endBob);

        if(overLapStart <= overLapEnd){
            return overLapEnd - overLapStart + 1;
        }

        return 0;
    }
};