#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 5005
#define INF 1000000000
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int d[MAXN][MAXN];
char p[MAXN],q[MAXN];
int sp[26],ep[26],sq[26],eq[26];
int lenp,lenq;

void dp () {
    for (int i = 0 ; i <= lenp ; i++) {
        for (int j = 0 ; j <= lenq ; j++) {
            int cnt = 0,res = INF;
            for (int k = 0 ; k < 26 ; k++)
                if ((i >= sp[k] || j >= sq[k]) && (i < ep[k] || j < eq[k])) cnt++;
            if (i > 0) res = min(res,d[i-1][j]);
            if (j > 0) res = min(res,d[i][j-1]);
            d[i][j] = cnt+(res == INF ? 0 : res);
        }
    }
    cout << d[lenp][lenq] << endl;
}

int main () {
    scanf ("%s%s",p+1,q+1);
    lenp = strlen(p+1);
    lenq = strlen(q+1);
    for (int i = 1 ; i <= lenp ; i++) p[i] -= 'A';
    for (int i = 1 ; i <= lenq ; i++) q[i] -= 'A';

    for (int i = 0 ; i < 26 ; i++) {
        sp[i]=sq[i]=INF;
        ep[i]=eq[i]=0;
    }
    for (int i = 1 ; i <= lenp ; i++) {
        sp[p[i]] = min(sp[p[i]],i);
        ep[p[i]] = i;
    }
    for (int i = 1 ; i <= lenq ; i++) {
        sq[q[i]] = min(sq[q[i]],i);
        eq[q[i]] = i;
    }
    dp ();
    return 0;
}
