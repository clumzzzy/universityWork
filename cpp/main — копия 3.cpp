//Динамические структуры. Списки. Задание 8
//Дано два однонаправленных списка целых чисел. Заменить все элементы с четной суммой цифр из первого списка на наибольший элемент второго списка.
#include <iostream>
using namespace std;

struct list
  {
      int info;
      list *next;
  } *l,*r = NULL,*p;
  
struct list1
  {
      int info;
      list1 *next;
  } *l1,*r1 = NULL,*p1;
  
int maximum;

bool chet_sum(int x)
{
    int s=0;
    while (x!=0)
    {
        s+=x%10;
        x/=10;
    }
    if(s%2==0) return true;
    else return false;
}

int max(list1 *p)
{
    while(p!=NULL)
    {
        if (p->info>maximum) maximum=p->info;
        p=p->next;
    }
    return maximum;
}

int main()
{
      cout<<"Данная программа позволяет заменить все элементы с четной суммой цифр из первого списка на наибольший элемент второго списка"<<endl<<endl;
    cout<<"Введите первый список через пробел -> ";
    int x;
    cin>>x;
    l=new(list);
    l->info=x;
    l->next=NULL;
    p=l;
    while(x!=0)
    {
        cin>>x;
        if(x!=0)
        {
            r=new(list);
            r->info=x;
            r->next=NULL;
            p->next=r;
            p=r;
        }
    }
    
    cout<<"Введите второй список через пробел -> ";
    int y;
    cin>>y;
    l1=new(list1);
    l1->info=y;
    l1->next=NULL;
    p1=l1;
    while(y!=0)
    {
        cin>>y;
        if(y!=0)
        {
            r1=new(list1);
            r1->info=y;
            r1->next=NULL;
            p1->next=r1;
            p1=r1;
        }
    }
    
    maximum=l1->info;
    p1=l1;
    maximum=max(p1);
    
    p=l;
    while(p!=NULL)
    {
        if(chet_sum(p->info)) p->info=maximum;
        p=p->next;
    }
    
    cout<<endl<<"Первый список после преобразований -> ";
    p=l;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
    
    cout<<endl<<"Второй список после преобразований -> ";
    p1=l1;
    while(p1!=NULL)
    {
        cout<<p1->info<<" ";
        p1=p1->next;
    }
    
    cin.get();cin.get();
}

//Пример 1
// 12 22 32 42 52 62 72 82 92 0
// 11 8 -44 3 33 26 -2 0

// Пример 2
// 12 35 7 123 45 281 -44 2 -3 8 0
// 12 34 32 -2 -3 43 222 -89 0

// Пример 3
// -12 -22 -32 -42 -52 -62 -72 -82 -92 0
// -12 -34 -32 -4 -3 -33 -26 -22 0

