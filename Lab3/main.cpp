#include <iostream>
using namespace std;

int main() {
    /*Ввод данных*/
    long n, s = 0, ser, p = 0, m = 0;
    cin >> n;
    int coll[n], clon[n], petya[n], masha[n];
    for(int i = 0; i < n; i++){
        cin >> coll[i];
        s += coll[i];
    }
    ser = s / 2;
    
    /*Сортировка массива по убыванию*/
    for(int i = 0; i < n; i++){
        int max = 0, t = -1;
        for(int j = 0; j < n; j++){
            if(coll[j] > max){
                max = coll[j];
                t = j;
            }
        }
        coll[t] = 0;
        clon[i] = max;
    }
    
    /*Распределение значений по группам*/
    for(int i = 0; i < n; i++){
        if(ser == p + clon[i]){
            petya[i] = clon[i];
            p += clon[i];
        }
        else if(ser == m + clon[i]){
            masha[i] = clon[i];
            m += clon[i];
        }
        else if(ser - p >= ser - m){
            petya[i] = clon[i];
            p += clon[i];
        }
        else{
            masha[i] = clon[i];
            m += clon[i];
        }
    }
    
    /*Вывод ответа*/
    if (p >= m){
        cout << (p - m) << "\n";
    }
    else{
        cout << (m - p) << "\n";
    }
    return 0;
}

