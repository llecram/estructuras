#include <iostream>
using namespace std;
template<class T>
class niterator{
public:
    T* m_i;
    niterator(T*p=nullptr){
        this->m_i=p;
    }
    niterator operator=(niterator<T> x){
        m_i=x.m_i;
        return *this;
    }
    bool operator!= (niterator<T> x){
        return m_i!=x.m_i;
    }
    T&operator*(){
        return *m_i;
    }
    niterator operator++ (int){
        m_i++;
        return *this;
    }
};
template<class T>
class riterator{
public:
    T* m_i;
    riterator(T*p=nullptr){
        this->m_i=p;
    }
    riterator operator=(riterator<T> x){
        m_i=x.m_i;
        return *this;
    }
    bool operator!= (riterator<T> x){
        return m_i!=x.m_i;
    }
    T&operator*(){
        return *m_i;
    }
    riterator operator++ (int){
        m_i--;
        return *this;
    }
};
template<class T>
struct vector{
    typedef niterator<T> nor_iterator;
    typedef riterator<T> rev_iterator;
    int tam;
    T* p;
    vector(int a){
        tam=a;
        p=new T[a];
    }
    nor_iterator begin();
    nor_iterator end();
    rev_iterator rbegin();
    rev_iterator rend();
};
template<class T>
typename vector<T>::nor_iterator vector<T>::begin(){
    return nor_iterator(p);
}
template<class T>
typename vector<T>::nor_iterator vector<T>::end(){
    return p+tam;
}

template<class T>
typename vector<T>::rev_iterator vector<T>::rbegin(){
    return (p+tam)-1;
    //return riterator(p);
}
template<class T>
typename vector<T>::rev_iterator vector<T>::rend(){
    return p-1;
    //return p+tam;
}
int main()
{
    vector<int> mivector(10);
    vector<int>::nor_iterator x;
    vector<int>::rev_iterator j;
    int i=0;
    for(x=mivector.begin();x!=mivector.end();x++){
        *x=i;
        i++;
    }
    for(x=mivector.begin();x!=mivector.end();x++){
        cout<<*x;
    }
    cout<<endl;
    for(j=mivector.rbegin();j!=mivector.rend();j++){
        cout<<*j;
    }
    //cout<<*mivector.rbegin();
    //cout<<*mivector.rend();
}
