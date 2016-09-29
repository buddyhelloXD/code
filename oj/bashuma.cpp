/*************************************************************************
    > File Name: bashuma.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年09月30日 星期五 03时27分15秒
 ************************************************************************/

#include <iostream>
#include <set>
#include <queue>
#include <utility>
#include <map>

using namespace std;

int map_temp[3][3];
int map_final[3][3];
int map_cur[3][3];
int count = 0;
set<int> st_set;
queue<int> st_que;
map<int , int> dis_map; 

bool is_equal () {
    bool flag = true;

    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            if (map_final[i][j] != map_cur[i][j]) {
                flag = false;
                goto end;
            }
        }
    }
end:
    return flag;
}

void swap (int *x , int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void make_map_temp (int x , int y , int type) {
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            map_temp[i][j] = map_cur[i][j];
        }
    }

    switch (type) {
        case 1:
            swap (&map_temp[x][y] , &map_temp[x-1][y]);
            /*for (int i = 0 ; i < 3 ; i++) {
                for (int j = 0 ; j < 3 ; j++) {
                    map_temp[i][j] = map_cur[i][j];
                }
            }*/
            break;
        case 2:
            swap (&map_temp[x][y] , &map_temp[x+1][y]);
            break;
        case 3:
            swap (&map_temp[x][y] , &map_temp[x][y-1]);
            break;
        case 4:
            swap (&map_temp[x][y] , &map_temp[x][y+1]);
            break;
        default:
            return;
    }
    int value = 0;

    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            value = value*10 + map_temp[i][j];
        }
    }
    st_que.push (value);
    int dis_temp = dis_map[st_que.front()];
    dis_map.insert (pair<int,int>(value,dis_temp+1));
}

int jiema () {
    int x = 0;

    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            x = x * 10 + map_cur[i][j];
        }
    }
    return x;
}

void yima (int value) {
    for (int i = 2 ; i >= 0 ; i--) {
        for (int j = 2 ; j >= 0 ; j--) {
            map_cur[i][j] = value%10;
            value = value/10;
        }
    }
}

pair<int,int> pos_zero () {
    int x , y;

    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            if (map_cur[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }
    return pair<int,int> (x,y);
}

void bfs () {
    
    int value = jiema ();
    st_que.push (value);
    dis_map.insert (pair<int,int> (value,0));

    while (!st_que.empty ()) {
        int temp = st_que.front ();

        yima (temp);

        if (is_equal ()) {
            count = 1;
            return;
        }

        pair<int,int> pos = pos_zero ();
        if (pos.first-1 >= 0) 
            make_map_temp (pos.first , pos.second , 1);
        if (pos.first+1 <= 2)
            make_map_temp (pos.first , pos.second , 2);
        if (pos.second-1 >= 0)
            make_map_temp (pos.first , pos.second , 3);
        if (pos.second+1 <= 2)
            make_map_temp (pos.first , pos.second , 4);
        st_que.pop ();
   }
}

int main () {
    int temp;
    int x , y;

    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            cin >> temp;
            map_final[i][j] = temp;
        }
    }
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            cin >> temp;
            map_cur[i][j] = temp;
        }
    }
    bfs ();
    int key_to_dis = 0;
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            key_to_dis = key_to_dis * 10 + map_final[i][j];
        }
    }
    cout << "the min distance is :" << dis_map[key_to_dis] << endl;
}
