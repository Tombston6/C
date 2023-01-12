/*
如果一个自然数N的K进制表示中任意的相邻的两位都不是相邻的数字，
那么我们就说这个数是K好数。求L位K进制数中K好数的数目。
例如K = 4，L = 2的时候，所有K好数为11、13、20、22、30、31、33 共7个。
由于这个数目很大，请你输出它对1000000007取模后的值。
*/

#include <iostream>
using namespace std;
#define MOD 1000000007
int dp[105][105];

int main()
{
    int k,l,sum=0;
    cin>>k>>l;
    //任意进制一位数都满足条件且个数是1
    for(int i=0;i<k;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<=l;i++){
        for(int j=0;j<k;j++){
            for(int m=0;m<k;m++){
                if(m!=j-1 && m!=j+1){
                    dp[i][j] += dp[i-1][m];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    
    for(int i=1;i<k;i++){
        sum += dp[l][i];
        sum %= MOD;
    }
    cout<<sum<<endl;
    return 0;
}
