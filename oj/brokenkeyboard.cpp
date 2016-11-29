#include <cstdio>
#include <cstring>
#define MAXN 100005

using namespace std;

char s[MAXN];
int next[MAXN];
int cur,last;

int main () {
    scanf ("%s",s+1);
    int len = strlen(s+1);
    next[0] = 0;

    for (int i = 1 ; i <= len ; i++) {
        char c = s[i];
        if(c == '[') cur = 0;
        else if(c==']') cur = last;
        else {
            next[i] = next[cur];
            next[cur] = i;
            if (cur == last) last++;
            cur = i;
        }
    }
    for (int i = next[0] ; i != 0 ; i = next[i])
        printf ("%c",s[i]);
    printf("\n");
}
