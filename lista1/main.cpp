#include <iostream>
using namespace std;
template<class T>
struct Cnode{
    T m_data;
    Cnode<T>* m_next;
    Cnode(T x){
        m_data=x;
        m_next=nullptr;
    }
};
template<class T>
class List_iterator{
public:
    Cnode<T>* m_i;
    List_iterator(Cnode<T>* p=nullptr){
        this->m_i=p;
    }
    List_iterator operator= (List_iterator<T> x){
        m_i=x.m_i;
        return *this;
    }
    bool operator!= (List_iterator<T> x){
        return m_i!=x.m_i;
    }
    T operator* (){
        return m_i->m_data;
    }
    List_iterator operator++ (int){
        this->m_i=this->m_i->m_next;
        return *this;
    }
};
template<class T, class C>
struct Clist{
    typedef List_iterator<T> iterator;
    Cnode<T>* m_head;
    Clist(){
        m_head=nullptr;
    }
    bool busca(T x, Cnode<T>**&p){
        p=&m_head;
        while(*p&&(*p)->m_data<x){
            p=&((*p)->m_next);
        }
        return *p&&(*p)->m_data==x;
    }
    bool inserta(T x){
        Cnode<T>** p;
        if(busca(x,p)){
            return 0;
        }
        Cnode<T>* n=new Cnode<T>(x);
        n->m_next=*p;
        *p=n;
        return 1;
    }
    bool saca(T x){
        Cnode<T>** p;
        if(!busca(x,p)){
            return 0;
        }
        Cnode<T>* t=*p;
        *p=t->m_next;
        delete t;
        return 1;
    }
    iterator begin();
    iterator end();
    void print(){
        while(m_head!=nullptr){
            cout<<" Valor: "<<m_head->m_data;
            if(m_head->m_next){
                cout<<" ";
            }
            m_head=m_head->m_next;
        }
    }
};
template <class T,class C>
typename Clist<T,C>::iterator Clist<T,C>::begin(){
    return iterator(m_head);
}
template <class T,class C>
typename Clist<T,C>::iterator Clist<T,C>::end(){
    return iterator();
}
int main()
{
    Clist<int,less<int>> L1;
    Clist<int,less<int>>::iterator x;
    L1.inserta(156);
    L1.inserta(7);
    L1.inserta(8);
    L1.inserta(9);
    for(x=L1.begin(); x!=L1.end(); x++){
        cout<< *x <<" ";
    }
}
