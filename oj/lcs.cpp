/*************************************************************************
    > File Name: lcs.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年11月23日 星期三 23时05分21秒
 ************************************************************************/

#include <iostream>
#include <string>

#define max(a,b) (((a)>(b))?(a):(b))
#define MAXN 100

using namespace std;

string a;
string b;
int r[MAXN][MAXN];
string res[MAXN][MAXN];

void dp () {
    int lena = a.size() , lenb = b.size ();
    r[0][0]=r[0][1]=r[1][0]=0;
    res[0][0]=res[0][1]=res[1][0]=string("");

    for (int i = 1 ; i < lena ; i++) {
        for (int j = 1 ; j < lenb ; j++) {
            if (a[i] == b[j]) {
                r[i][j] = r[i-1][j-1] + 1;
                res[i][j] = res[i-1][j-1] + a[i];
            }
            else {
                r[i][j] = max(r[i-1][j] , r[i][j-1]);
                res[i][j] = (r[i-1][j]>r[i][j-1]) ? res[i-1][j] : res[i][j-1];
            }
        }
    }
}

int main () {
    cin >> a >> b;
    dp();
    cout << r[a.size()-1][b.size()-1] << endl;
    cout << res[a.size()-1][b.size()-1] << endl;
}
