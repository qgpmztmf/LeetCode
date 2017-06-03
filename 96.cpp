// 96. Unique Binary Search Trees
// Writed by dtm on 2017/6/3
class Solution {
public:

    int numTrees(int n) {
        vector<int> num(n+1);
        num[0] = 1;
        num[1] = 1;
        for(int i = 2; i <= n; i ++){
            for(int j = 1; j <= i; j++) num[i] += num[j-1]*num[i-j];
        }
        return num[n];
    }
    /*
    int numTrees(int n, int m) {
        if(n <= 0){
            return 1;
        }
        else if(n == 1){
            return 1;
        }
        else if(n % 2 == 0){
            int ans = 0;
            int loopNum = n / 2;
            for(int i = 0;i < loopNum; i++){
                ans += 2 * numTrees(i) * numTrees(n - i - 1);
            }
            return ans;
        }
        else{  //(n % 2) == 1
            int ans = 0;
            int loopNum = n / 2;
            for(int i = 0;i < loopNum; i++){
                ans += 2 * numTrees(i) * numTrees(n - i - 1);
            }
            ans += numTrees(loopNum) * numTrees(loopNum);
            return ans;
        }
    }*/
};