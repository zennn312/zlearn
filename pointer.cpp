#include <iostream>
using namespace std;

int main () {
    
    // int *p, *q, *r;
    // float *x;
    // char *s;
    // int n=10;
    // p=&n;

    // cout << *p << endl;
    // cout << p << endl;;
    // cout << n;

    // int array[3] = {10,20,30};
    // cout << *(array+2) << endl;

    // int i;
    // int *k;

    // k = array;
    // for(i=0;i<3;i++){
    //     cout << *(k+1) << " ";
    // }

    // char kota[] = "Jogja";
    // cout << kota << endl;
    // char *i = kota;
    // cout << *i;

    // int j;
    // for(j=0;j<5;j++){
    //     cout << *(i+j) <<" ";
    // }

    // int x=20;
    // int *i=&x;
    // int **ii=&i;
    // cout << &x << endl;
    // cout << &i;

    // int a = 1;
    // int b;

    // int *c = &a;
    // int d = *c;
    // cout << &a << endl;
    // cout << &b << endl;
    // cout << c << endl;
    // cout << &c << endl;
    // cout << *c << endl;
    // cout << d;

    int array[9] = {1,2,3,4,5,6,7,8,9};

    int i;
    int *j;
    j = array;
    for(i=0;i<9;i++){
        cout << *(j+i) << " ";
    }
    cout << endl;

    int max = *array;
    int min = *array;

    for(i=0;i<9;i++){
        if(*(array+i) > max){
            max = *(array+i);
        }
    }

    for(i=0;i<9;i++){
        if(*(array+i) < min){
            min = *(array+i);
        }
    }

    cout << "Nilai Max : " << max << endl;
    cout << "Nilai Min : " << min << endl;

    int jmlh = 0;
    for(i=0;i<9;i++){
        jmlh += *(array+i);
    }

    int rata = jmlh/9;

    cout << "Jumlah    : " << jmlh << endl;
    cout << "Rata-rata : " << rata;



    return 0;
}
