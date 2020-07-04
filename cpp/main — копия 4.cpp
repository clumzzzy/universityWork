//Двунаправленные списки. Кольца. Задание 8
//Дан двунаправленный список целых чисел. Отсортировать элементы списка в порядке убывания.

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, 0);
    cout<<"Данная программа позволяет отсортировать элементы списка в порядке убывания."<<endl<<endl;
    
    struct list
    {
        int info;
        list *next;
        list *prev;
    }*l,*r = nullptr ,*p;
    
    cout<<"Введите список через пробел -> ";
    int x;
    cin>>x;
    l=new(list);
    l->info=x;
    l->next=NULL;
    l->prev=NULL;
    int k=1;
    p=l;
    while(x!=0)
    {
        cin>>x;
        if(x!=0)
        {
            r=new(list);
            r->info=x;
            r->next=NULL;
            r->prev=p;
            p->next=r;
            p=r;
            k++;
        }
    }
    
    int i;
    int tmp=0;
    
    for(i=0;i<k;i++)
    {
        p=l;
        while (p->next!=NULL)
        {
            if(p->info>p->next->info)
            {
                tmp=p->info;
                p->info=p->next->info;
                p->next->info=tmp;
            }
            p=p->next;
        }
    }
    
    cout<<endl;
    cout<<"Отсортированный список -> ";
    p=r;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->prev;
    }
    
    /*char g;
    cout<<"Введите 'u', если хотите отсортировать список по убыванию"<<endl;
    cout<<"Введите 'v', если хотите отсортировать список по возрастанию"<<endl;
    cout<<"  ->  ";
    cin>>g;
    
    if(g=='u')
    {
        cout<<"Отсортированный список -> ";
        p=r;
        while(p!=NULL)
        {
            cout<<p->info<<" ";
            p=p->prev;
        }
    }
    
    if(g=='v')
    {
        cout<<"Отсортированный список -> ";
        p=l;
        while(p!=NULL)
        {
            cout<<p->info<<" ";
            p=p->next;
        }
    }*/
    
    cin.get();cin.get();
}

//Пример 1
//4 2 3 1 6 7 5 0

//Пример 2
//2 5 7 -1 2 3 4 7 8 5 0

//Пример 3
//-2 -4 -1 -5 -2 -3 -7 -10 -2 0

