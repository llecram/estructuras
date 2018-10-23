#include <iostream>
using namespace std;
template<class T>
struct vector{
    typedef T * niterator;
    typedef T * riterator;
    int tam;
    T* p;
    vector(int a){
        tam=a;
        p=new T[a];
    }
    niterator begin();
    niterator end();
    riterator rbegin();
    riterator rend();
};
template<class T>
class niterator{
public:
    vector<T>* m_i;
    niterator(vector<T>*p=nullptr){
        this->m_i=p;
    }
    niterator operator=(niterator<T> x){
        m_i=x.m_i;
        return *this;
    }
    bool operator!= (niterator<T> x){
        return m_i!=x.m_i;
    }
    T operator*(){
        return m_i->p;
    }
    niterator operator++ (int){
        m_i++;
        return *this;
    }
};
template<class T>
class riterator{
public:
    vector<T>* m_i;
    riterator(vector<T>*p=nullptr){
        this->m_i=p;
    }
    riterator operator=(riterator<T> x){
        m_i=x.m_i;
        return *this;
    }
    bool operator!= (riterator<T> x){
        return m_i!=x.m_i;
    }
    T operator*(){
        return m_i->p;
    }
    riterator operator-- (int){
        m_i--;
        return *this;
    }
};
template<class T>
typename vector<T>::niterator vector<T>::begin(){
    return niterator(p);
}
template<class T>
typename vector<T>::niterator vector<T>::end(){
    return p+tam;
}

template<class T>
typename vector<T>::riterator vector<T>::rbegin(){
    return (p+tam)-1;
    //return riterator(p);
}
template<class T>
typename vector<T>::riterator vector<T>::rend(){
    return p-1;
    //return p+tam;
}
int main()
{
    vector<int> mivector(10);
    vector<int>::niterator x;
    vector<int>::riterator j;
    int i=0;
    for(x=mivector.begin();x!=mivector.end();x++){
        *x=i;
        i++;
    }
    for(x=mivector.begin();x!=mivector.end();x++){
        cout<<*x;
    }
    cout<<endl;
    for(j=mivector.rbegin();j!=mivector.rend();j--){
        cout<<*j;
    }
    //cout<<*mivector.rbegin();
    //cout<<*mivector.rend();
}
