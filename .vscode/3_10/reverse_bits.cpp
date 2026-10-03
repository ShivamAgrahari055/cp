//reverse the bits of a given number
//what it do ..shift answer 1 bit left then it create 0 there add the new element in the ans ...then shift
//n to right

class Solution {
public:
    int reverseBits(int n) {
        uint32_t ans = 0 ;
        for(int i=0;i<32;i++){
            ans = ans << 1 ;
            ans = ans | (n&1) ;
            n = n>> 1 ;
        }
        return ans ;
    }
};