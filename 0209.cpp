// https://leetcode-cn.com/problems/reverse-integer
// [-16, 15]
// -16, -15, -14 ... 0, 1, 2, ... 13, 14, 15
// -61

// m = 31个2相乘
// m是int类型 最大是2^31-1
// 计算m的时候会溢出(long long)

// m-1实际上等于2^31-1
// 判断n = n * 10 + a是否溢出？
// 如果 n = (m - 1 - a) / 10 + 1
// n * 10 + a = m - 1 - r + 10 (其中r为m-1-a的个位数字) 肯定溢出
// 如果 n = (m - 1 - a) / 10是否溢出？
// n * 10 + a = m - 1 - r (其中r为m-1-a的个位数字) 肯定不溢出
// 所以 当 n <= (m - 1 - a) / 10 时 不溢出 否则会溢出


// m = -2^31
// x < 0
// n < 0
// 判断n = n * 10 + a; n是否溢出？
// 如果 n = (-m - a) / 10 - 1 
// n * 10 + a = -m + r - 10 (其中r为-m-a的个位数字, r是正数)
// 如果肯定溢出
// 如果 n = (-m - a) / 10是否溢出？
// n * 10 + a = -m + r (其中r为-m-a的个位数字, r是正数) 肯定不溢出
// 所以 当 n >= (-m - a) / 10 时 不溢出 否则会溢出

int reverse(int x){
    long long n=0,m=1,a;
    for (int i=0;i<31;i++)
        m=m*2;
    if (x > 0) {
        while (x!=0){
            a=x%10;
            x=x/10;
            if (n > (m - 1 - a) / 10) {
                return 0;
            }
            n=n*10+a;
        }
        return n;
    }
    else {
        while (x!=0){
            a=x%10;
            x=x/10;

            if (n < (-m - a) / 10)
                return 0;

            n=n*10+a;
        }
    }
    return n;
}