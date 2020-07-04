/*#include <iostream>
using namespace std;

int C[50][50];
int D[50];

int main() {

    int size = 25;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> C[i][j];

    for (int i = 0; i < size; i++) D[i] = C[0][i];

    for (int w = 0; w < size; w++)
        for (int v = 0; v < size; v++)
            D[v] = D[v] < D[w] + C[w][v] ? D[v] : D[w] + C[w][v];

    cout << D[size] << endl;

    return 0;
}*/


/*#include <iostream>
using namespace std;

int main() {

    int inf = 999999;
    int W[5][5] = {     {0, inf, 1, inf, inf},
                        {inf, 0, inf, inf, 1},
                        {inf, inf, 0, 1, inf},
                        {inf, 1, inf, 0, inf},
                        {inf, inf, inf, inf, 0} };

    int H[5];

    for (int i = 0; i < 5; i++) H[i] = 0 + i;

    
    int L[5] = { 0, inf, 1, inf, inf };

    for (int k = 0; k < 5; k++){
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++)
            {
                if (L[i] + W[i][j] < L[j]) {
                    L[j] = L[i] + W[i][j];
                    H[j] = H[i] * 10 + j;
                }
            }
            for (int i = 0; i < 5; i++) cout << H[i] << "_" << L[i] << "|";
            cout << endl;
        }
    }
    cout << L[4] << endl;
    cout << H[4] << endl;

    return 0;
}*/


/*#include <iostream>
using namespace std;

int main() {

    int inf = 999999;

    int W[5][5] = { {inf, 8, 1, 3, inf},
                    {8, inf, inf, 10, 1},
                    {1, inf, inf, 1, 6},
                    {3, 10, 1, inf, 4},
                    {inf, 1, 6, 4, inf} };

    int R[5][5];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            R[i][j] = inf;


    bool U[5] = { 1, 0, 0, 0, 0 };

    for (int i = 0; i < 5; i++)
    {
        int min_length = inf;
        int next_vertice = -1;

        for (int j = 0; j < 5; j++)
        {
            if (W[i][j] < min_length && !U[j])
            {
                min_length = W[i][j];
                next_vertice = j;
            }
        }

        if (next_vertice != -1 && min_length < R[i][next_vertice])
        {
            R[i][next_vertice] = min_length;
            R[next_vertice][i] = min_length;
            U[i] = true;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) cout << R[i][j] << " ";
        cout << endl;
    }

    return 0;
}*/


//дз от 23.04
#include <iostream>
#include <fstream>
using namespace std;


char a[100];

char abc[27] = "abcdefghijklmnopqrstuvwxyz";

int letters[26];

int ord(char letter){
    for (int i = 0; i < 26; i++)
        if (abc[i] == letter) return i;
    return -1;
}

char chr(int i) {
    return abc[i];
}

int main() {

    ifstream file("text.txt");

    for (int i = 0; i < 26; i++) letters[i] = 0;

    char tmp;
    int c = 0;

    while (!file.eof()) {
        file >> tmp;
        if (tmp == ' ' || tmp == '.' || tmp == ',' || tmp == '!') continue;
        a[c] = tmp;
        c++;
    }
    
    for (int i = 0; i < c-1; i++) letters[ord(a[i])]++;

    bool polinomable = true;

    int stringLength = c - 1;

    int odd = 0;
    for (int i = 0; i < 26; i++) if (letters[i] % 2 == 1) odd++;

    if (stringLength % 2 == 1 && odd > 1) polinomable = false;
    else
        if (odd > 0) polinomable = false;

    if (polinomable) cout << "Yes" << endl;
    else cout << "No" << endl;
 
    file.close();
    
    ofstream answer("answer.txt");
    
    if(answer.is_open())
        answer << polinomable;
    else cout<<"False";
    
    answer.close();
}
