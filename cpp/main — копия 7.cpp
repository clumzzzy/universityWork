//Двоичные деревья. Задание 8
//Дано дерево двоичного поиска. Верно ли, что сумма элементов дерева больших среднего арифметического листьев дерева равна заданному числу N.

#include <iostream>
using namespace std;

    struct tree
{
    int info;
    tree* L;
    tree* R;
};

void add(tree* t,int x);

void print(tree* p);

float sum_l(tree* p);

float Kolvo(tree* p);

float sred_a_l(tree* p);

float sum(tree* p);

tree* root;

int main()
{
    cout<<"Данная программа позволяет определить, верно ли, что сумма элементов дерева больших среднего арифметического листьев дерева равна заданному числу N."<<endl<<endl;
    int x;
    root=new tree;
    cout<<"Введите дерево через пробел -> ";
    cin>>x;
    root->info=x;
    root->L=NULL;
    root->R=NULL;
    while (x!=0)
    {
        cin >> x;
        if (x != 0) add(root, x);
    }
    
    int N;
    cout<<"Введите число N -> ";
    cin>>N;
    
    cout<<"Сумма листьев -> "<<sum_l(root)<<endl;
    cout<<"Количество листьев -> "<<Kolvo(root)<<endl;
    cout<<"Среднее арифметическое листьев -> "<<sred_a_l(root)<<endl;
    cout<<"Искомая сумма -> "<<sum(root)<<endl;
    
    if(sum(root)==N) cout<<"Верно, сумма равна N!";
    else cout<<"Неверно, сумма не равна N!";
    
    cin.get();cin.get();
    return 0;
}

void add(tree* t,int x)
{
    tree* q;
    if (x < t->info)
        if (t->L == NULL)
            {
                q = new(tree);
                q->info = x;
                q->L = NULL;
                q->R = NULL;
                t->L = q;
            }
        else add(t->L, x);
    else
        if (t->R == NULL)
            {
                q = new(tree);
                q->info = x;
                q->L = NULL;
                q->R = NULL;
                t->R = q;
            }
        else add(t->R, x);
}

void print(tree *p)
{
    if (p!=NULL)
    {
        cout<<p->info<<" ";
        print(p->L);
        print (p->R);
    }
}

float sum_l(tree *p)
{
    int s=0;
    if (p != NULL)
    {
        if (p->L==NULL && p->R==NULL)
        {
            s+=p->info;
            return s;
        }
        return sum_l(p->L) + sum_l(p->R);
    }
    return 0;
}

float Kolvo(tree *p)
{
    if (p != NULL)
    {
        if (p->L==NULL && p->R==NULL) return 1;
        else return Kolvo(p->L) + Kolvo(p->R);
    }
    return 0;
}

float sred_a_l(tree *p)
{
    return sum_l(p)/Kolvo(p);
}

float sum(tree *p)
{
    if (p != NULL)
    {
        if (p->info > sred_a_l(root)) return p->info + sum(p->L) + sum(p->R);
        else return sum(p->L) + sum(p->R);
    }
    return 0;
}

//Пример 1
//8 3 10 1 6 14 4 7 13 0
//Среднее арифметическое листьев: 6,25
//Сумма: 52

//Пример 2
//7 3 9 5 2 8 6 1 4 0
//Среднее арифметическое листьев: 4.75
//Сумма: 35

//Пример 3
//7 -1 9 -5 2 11 8 4 1 6 3 0
//Среднее арифметическое листьев: 4
//Сумма: 41




