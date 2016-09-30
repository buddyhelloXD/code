/*************************************************************************
    > File Name: constructor.h
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年09月30日 星期五 19时40分22秒
 ************************************************************************/

#include "iterator_traits.h"
#include "traits_type.h"

template <class T1 , class T2>
inline void construct (T1 *p , const T2 &value) {
    new (p) T1(value);
}

template <class T>
inline void destruct (T *p) {
    p->~T();
}

template <>
inline void destruct (char *) {

}

template <>
inline void destruct (wchar_t *) {

}

template <class Iterator>
inline void destruct (Iterator first , Iterator last) {
    __destruct (first , last , value_type (first));
}

template <class Iterator , class T>
inline void __destruct (Iterator first , Iterator last , T*) {
    typedef typename __type_traits<T>::has_trivial_destructor has_trivial_destructor;
    __destruct_aux (first , last , has_trivial_destructor ());
}

template <class Iterator>
inline void __destruct_aux (Iterator first , Iterator last , __true_type) {
    
}

template <class Iterator>
inline void __destruct_aux (Iterator first , Iterator last , __false_type) {
    for (Iterator temp = last ; temp > first ; temp--) {
        destruct (&*temp);
    }
}
