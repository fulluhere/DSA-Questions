class BusBooking {
public:
    vector<vector<int>>bus;
    int tottime= 0;
    int cnt = 0;
    BusBooking(int n) {
        bus.resize(n+1, vector<int>(4, 0));
        
    }
    
    void toggle(string seat) {
        int y = seat[0]-'A';
        int x = stoi(seat.substr(1));;

        if(bus[x][y] != 0){
            
            tottime -= bus[x][y];
            cnt--;
            bus[x][y] = 0;
        }
        else if(y==1 || y == 2){
            bus[x][y] = 1;
            tottime += 1;
            cnt++;
        }

        else{
            if(y==0){
                if(bus[x][1]!=0){
                    bus[x][y] = 3;
                }else{
                    bus[x][y] = 1;
                }
            }else{
                if(bus[x][2]!=0){
                    bus[x][y] = 3;
                }else{
                    bus[x][y] = 1;
                }
            }

            tottime += bus[x][y];
            cnt++;
        }
    }
    
    int getTotalTime() {
        return tottime;
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
/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */