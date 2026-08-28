class DataStream {

public:
int val;
int k;
int cnt = 0;
vector<int>vec;
    DataStream(int value, int k) {
        val = value;
        this->k  = k;
        
    }
    
    bool consec(int num) {
        vec.push_back(num);

        if(vec.back() == val){
            cnt++;
        }else{
            cnt=0;
        }

        if(vec.size()<k){
            return false;
        }

        else{
            if(cnt == k){
                cnt--;
                return true;
            }
        }


        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */