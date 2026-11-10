class BusBooking {

private:
    vector<int>nums;
    int total = 0;
    int cnt = 0;

    int getIndex(string &seat){
        int r = stoi(seat.substr(1));

        return r * 4 + (seat[0] - 'A');
    }
public:
    BusBooking(int n) {
        nums.assign((n + 1) * 4 , 0); 
    }
    
    void toggle(string seat) {
        int idx = getIndex(seat);

        if(nums[idx] > 0){
            total -= nums[idx];
            nums[idx] = 0;
            cnt--;
            return;
        }

        int temp = 1;
        char ch = seat[0];
        if((ch == 'A' && nums[idx + 1] > 0) || (ch == 'D' && nums[idx - 1] > 0)){
            temp = 3;
        }

        nums[idx] = temp;
        total += temp;
        cnt++;
    }
    
    int getTotalTime() {
        return total;
    }
    
    int getMinTime() {
        return cnt;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */