// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

// Your score is the sum of the points of the cards you have taken.

// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int total = 0;

        for(int x:cardPoints){
            total += x ;
            
        }
        int window = n-k ;

        if(window == 0) return total ;

        int sum = 0;
        for(int i=0;i<window;i++){
            sum += cardPoints[i] ;

        }
        int mn = sum ;
        for(int i=window ;i<n;i++){
            sum += cardPoints[i] ;
            sum -= cardPoints[i-window] ;
            mn = min(mn,sum) ;
        }
        return total - mn ;
    }
};