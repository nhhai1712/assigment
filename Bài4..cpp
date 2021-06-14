#include <iostream>
using namespace std;
#include <stdlib.h>
#include <map>
#include <time.h>
 
int main(){
    srand((int)time(0));
    int r, minN, maxN;
    cout << "\nNhap minN = ";
    cin >> minN;
    cout << "\nNhap maxN = ";
    cin >> maxN;
    int cnt;
    do{
        cout << "\nNhap so luong so can random = ";
        cin >> cnt;
    }while(cnt > maxN - minN + 1);
    map<int, bool> vis;
    for(int i = 0; i < cnt; ++i){
        do{
            r = minN + rand() % (maxN + 1 - minN);
        }while(vis.find(r) != vis.end());
        printf("%d ",r);
        vis[r] = true;
    }    
}
 
