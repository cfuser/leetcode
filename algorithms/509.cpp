//INNNNoVation!!!
class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1;
        if (n == 0) return 0;
        while (n > 1)
        {
            int c = a + b;
            a = b;
            b = c;
            n--;
        }
        return b;
    }
};