

// class Solution {
// public:
//     vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
//         int m = image.size();
//         int n = image[0].size() ;
//         vector<vector<int>> ans ;

//         for(int i=0;i<m;i++){
//             vector<int> temp ;
//             for(int j=0;j<n;j++){
//                 int num = 1 - image[i][j];
//                 temp.push_back(num);

//             }
//             reverse(temp.begin(),temp.end());
//             ans.push_back(temp) ;
//         }
//         return ans ;
//     }
// };
// class Solution {
// public:
//     vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

//         for(int i = 0; i < image.size(); i++) {

//             reverse(image[i].begin(), image[i].end());

//             for(int j = 0; j < image[i].size(); j++) {
//                 image[i][j] = 1 - image[i][j];
//             }
//         }

//         return image;
//     }
// };
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        for(int i = 0; i < image.size(); i++) {

            int l = 0;
            int r = image[i].size() - 1;

            while(l <= r) {

                // reverse + invert simultaneously
                int temp = image[i][l] ^ 1;

                image[i][l] = image[i][r] ^ 1;
                image[i][r] = temp;

                l++;
                r--;
            }
        }

        return image;
    }
};