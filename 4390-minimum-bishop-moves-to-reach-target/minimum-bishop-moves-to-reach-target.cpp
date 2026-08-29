class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0];
        int sc = source[1];
        int tr = target[0];
        int tc = target[1];

        if(abs(tr-sr) == abs(tc-sc)){
            return 1;
        }

        else if((tr+tc)%2 != (sr+sc)%2){
            return -1;
        }

        else if(tr == sr &&  tc==sc){
            return 0;
        }

        return 2;
    }
};