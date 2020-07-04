/*#include <iostream>
using namespace std;




struct Table
{
    char name[10];
    int refer_to = -1;
};
Table table[20];

int ord(char a)
{
    char alphabet[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
    int i = 0;
    while (a != alphabet[i]) i++;
    return i;
}

int hasher(char name[])
{
    int i = 0;
    int mult = 1;
    while (name[i] != '\0')
    {
        int val = ord(name[i]);
        mult *= (val + i);
        i++;
    }
    int value = mult % 20;
    if (table[value].refer_to == -1)
    {
        int k = 0;
        while (name[k] != '\0')
        {
            table[value].name[k] = name[k];
            k++;
        }
        table[value].refer_to = value + 1 % 20;
    }
    else
    {
        while (table[value].refer_to != -1) value = table[value].refer_to;
        int k = 0;
        while (name[k] != '\0')
        {
            table[value].name[k] = name[k];
            k++;
        }
        table[value].refer_to = value + 1 % 20;
    }
    return value;
}

int main()
{
    char test[] = { 'l', 'o', 'l', '\0' };
    char test1[] = { 'l', 'l', 'l', '\0' };
    char test2[] = { 'l', 'o', 'l', '\0' };
    int x = hasher(test);
    cout << x << endl;
    x = hasher(test1);
    cout << x << endl;
    x = hasher(test2);
    cout << x << endl;

}*/
#include <iostream>
using namespace std;

const int SIZE = 16;

int Pic[SIZE][SIZE] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void print() {
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++)
            cout << Pic[y][x];
        cout << endl;
    }
}

int main()
{
    print();
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            if (Pic[y][x] == 0) continue;

            int x2 = x + 1;
            for (; x2 < SIZE; x2++)
                if (Pic[y][x2] == 0) break;
            x2--;

            int y2 = y + 1;
            for (; y2 < SIZE; y2++)
                if (Pic[y2][x] == 0) break;
            y2--;

            int mid = y + (y2 - y)/2;
            for (int ySwap = y; ySwap <= mid; ySwap++) {
                int yOther = y2 - (ySwap - y);
                for (int xSwap = x+1; xSwap <= x2; xSwap++) {
                    int swap = Pic[ySwap][xSwap];
                    Pic[ySwap][xSwap] = Pic[yOther][xSwap];
                    Pic[yOther][xSwap] = swap;
                }
            }
        }
    }
    cout << endl << endl;
    print();
}
