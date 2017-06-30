class Solution {
public:
    double myPow(double x, int n) {
    	return myPow(x, long(n));
    }
    
    double myPow(double x, long n) {
        if(n == 0) return 1;
        if(n < 0) return 1 / myPow(x, -1 * n);
        if(n % 2 == 1) {
            return x * myPow(x, n - 1);
        } 
        if(n % 2 == 0) {
            double tmp = myPow(x, n / 2);
            return tmp * tmp;
        }
    }
};
