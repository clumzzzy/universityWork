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

tree* root;

int main()
{
    int x;
    root = new tree;
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
    
    cin.get();cin.get();
    return 0;
}

void add(tree* t,int x)
{
    tree* q;
    if (t->info % 2 != 0)
        if (t->L!=NULL)
            {
                q = new(tree);
                q->info = x;
                q->L = NULL;
                q->R = NULL;
                t->L = q;
            }
        else {add(t->L, x); cout<<"L";}
    else
        if (t->R == NULL)
            {
                q = new(tree);
                q->info = x;
                q->L = NULL;
                q->R = NULL;
                t->R = q;
            }
        {add(t->R, x); cout<<"R";}
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
