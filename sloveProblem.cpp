#include <iostream>
using namespace std;

#define MAX 20
//Definition variable
const char defineChar[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int result[MAX];
bool check[MAX]{0};
int n = 8;

bool kiemTraHopLe(){
    for(int i = 1; i < n; i++){
        if (defineChar[result[i]] == 'C' && defineChar[result[i - 1]] == 'D' || 
            defineChar[result[i]] == 'D' && defineChar[result[i - 1]] == 'C'){
            return false;
        }
    }
    return true;
}

void xuatHopLe(){
    if (kiemTraHopLe()){
        for (int j = 0; j < n; j++)
            cout << defineChar[result[j]] << " ";
        cout << endl;
    }
}

void lietKe(int k){
    for (int i = 0; i < n;i++){
        if (check[i] == 0){
            result[k] = i;
            check[i] = 1;
            if (k == n - 1)
                xuatHopLe();
            else
                lietKe(k + 1);
            check[i] = 0;
        }
    }
}

int main(){
    lietKe(0);
}