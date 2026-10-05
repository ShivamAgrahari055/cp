
a number is power of 2 or not
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        for(int i=0;i<32;i++){
            if(n == (1 << i)) return true ;
        }
        return false ;
    }
};
//m2

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

A power of 2 has exactly one 1 bit:

8  = 1000
7  = 0111
------------
     0000