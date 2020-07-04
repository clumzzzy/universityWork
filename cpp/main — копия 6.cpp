#include <iostream>
#include <math.h>
using namespace std;
bool even(int x)
{
    int sum = 0;

    while (x != 0)
    {
        sum += x % 10;
        x /= 10;
    }
    if (sum % 2 == 0) return 1;
    else return 0;
}

int main()
{
    struct list
    {
        int info;
        list *next;
        list *prev;
    };
    list *l,*r,*p;
    int x;
    cin>>x;
    l=new(list);
    l->info=x;
    l->next=NULL;
    l->prev=NULL;
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
        }
    }
    
    
    p=l;
    while(p!=NULL)
    {
        if (even(p->info)==0)
        {
            p->prev->next = p->next->prev;
            p->next = p->next->next;
        }
        p=p->next;
    }
    
    p=l;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
}


/*#include <iostream>
#include <math.h>
using namespace std;
//Номер 5
int k_del(int x)
{
    int k=0;
    for(int i=1;i<=x;i++)
    {
        if (x%i==0) k++;
    }
    return k;
}

int main()
{
    struct list
    {
        int info;
        list *next;
        list *prev;
    };
    list *l,*r = nullptr,*p;
    int x;
    cin>>x;
    l=new(list);
    l->info=x;
    l->next=NULL;
    l->prev=NULL;
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
        }
    }
    
    int min=l->info;
    
    p=l;
    while (p!=NULL)
    {
        if(p->info<min)min=p->info;
        p=p->next;
    }
    
    min*=2;
    
    p=l;
    while (p!=NULL)
    {
        if (k_del(p->info)==3)
        {
            r=new(list);
            r->info=min;
            r->next=p->next;
            p->next=r;
            r->prev=p;
            p=r;
        }
        p=p->next;
    }
    
    p=l;
       while(p!=NULL)
       {
           cout<<p->info<<" ";
           p=p->next;
       }
}*/



//Индивидулка 1
//Дано два однонаправленных списка целых чисел. Заменить все элементы с четной суммой цифр из первого списка на наибольший элемент второго списка.
/*#include <iostream>
using namespace std;

struct list
  {
      int info;
      list *next, *prev;
  } *l,*r = NULL,*p;
  
struct list1
  {
      int info;
      list1 *next, *prev;
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

int max(list1 *p1)
{
    while(p1!=NULL)
    {
        if (p1->info>maximum) maximum=p1->info;
        p1=p1->next;
    }
    return maximum;
}

int main()
{
  
    int x;
    cin>>x;
    l=new(list);
    l->info=x;
    l->next=NULL;
    l->prev=NULL;
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
            r->prev=p;
            p=r;
        }
    }
    
    int y;
    cin>>y;
    l1=new(list1);
    l1->info=y;
    l1->next=NULL;
    l1->prev=NULL;
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
            r1->prev=p1;
            p1=r1;
        }
    }*/
    
    /*p=l;
    while (p->next!=NULL)
    {
        if (x==0)
        {
            if (p->next->info>0)
            {
                p->next=p->next->next;
            }
            else p=p->next;
        }
        if (x==1)
        {
            if (pr(p->next->info)==1)
            {
                p->next=p->next->next;
            }
            else p=p->next;
        }
    }*/
    
    /*p=l;
    p1=l1;
    while(p1!=NULL)
    {
        
    }
    
    p=l;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
    
    cout<<endl<<endl;
    
    p1=l1;
       while(p1!=NULL)
       {
           cout<<p1->info<<" ";
           p1=p1->next;
       }*/

