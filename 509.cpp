class Solution {
public:
    int fib(int n) {
        
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

       int ans = fib(n - 1) + fib(n - 2);

       return ans;
    }
};



int fib(int n) {

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int ans = fib(n - 1) + fib(n - 2);
}

int main()
{
    int a = fib(7);

    int b = 0;

    return 0;
}