#include <iostream>
using namespace std;

int min(int x, int y)
{
    if (x>y) return y;
    return x;
}
int min_arr(int a[5])
{
    int minimum=a[0];
    for(int i=0; i<5; i++)
    {
        if (minimum > a[i]) minimum = a[i];
    }
    return minimum;
}


int main()
{
    int N = 999;
    
    int m_s[10][10] = { {0, 10, N, 30, 100},
                        {N, 0, 50, N, N},
                        {N, N, 0, N, 10},
                        {N, N, 20, 0, 60},
                        {N, N, N, N, 0}};
    
    int rez[5]; //результирующий массив веса кратчайших путей
    for (int v = 0; v < 5; v++)
        rez[v] = m_s[0][v];
    
    for (int w = 0; w < 5; w++)
        for (int v = 0; v < 5; v++)
            if (rez[v] > rez[w] + m_s[w][v])
                rez[v] = rez[w] + m_s[w][v];
    
    for(int i = 0; i < 5; i++)
        cout<<rez[i]<<" ";
   
    cin.get(); cin.get();
    return 0;
}

#include <iostream>
using namespace std;


int main()
{
setlocale(0, "");

int metka = 0, flag = 0, min = 0;
int n;
cout << "Введите длину графа: ";
cin >> n;
int a[100][100], k[100+1][100], otv[100];

for (int j = 0; j < n; j++)
    otv[j] = 0;

for (int i = 0; i < n+1; i++)
    for (int j = 0; j < n; j++)
        k[i][j] = 99;

k[0][0] = 0;

for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        cin >> a[i][j];

for (int i = 1; i < n+1; i++) {
    
    for (int j = 0; j < n; j++) {
        if (a[metka][j] > 0) {
            if(a[metka][j] + flag < k[i-1][j])
                k[i][j] = a[metka][j] + flag;
        }
    }

    for (int j = 0; j < n; j++) {
        if (k[i - 1][j] < k[i][j]) {
            if (j != metka)
                k[i][j] = k[i - 1][j];
        }
    }

    min = k[i][0];

    for (int j = 0; j < n; j++) {
        if (k[i][j] < min) {
            min = k[i][j];
            metka = j;
            flag = min;
        }
    }
    
    otv[metka] = flag;
}

cout << "Кратчайшее растояние от начала до конца: " << flag <<endl;

for (int i = 0; i < n; i++)
    cout <<"Расстояние от начала до точки "<< i+1 <<": " << otv[i] <<" "<<endl;
    
}










