/*************************************************************************
    > File Name: test.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年09月29日 星期四 22时47分31秒
 ************************************************************************/
#include <cstddef> //for ptrdiff_t incldued
#include <cstdlib>


//this is tag of five iterators
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <class T>
struct input_iterator {
    typedef input_iterator_tag      iterator_category;
    typedef T                       value_type;
    typedef ptrdiff_t               difference_type;
    typedef T*                      pointer;
    typedef T&                      reference;
};

template <class T>
struct output_iterator {
    typedef void                    iterator_category;
    typedef void                    value_type;
    typedef void                    difference_type;
    typedef void                    pointer;
    typedef void                    reference;
};

template <class T>
struct forward_iterator {
    typedef forward_iterator_tag    iterator_category;
    typedef T                       value_type;
    typedef ptrdiff_t               difference_type;
    typedef T*                      pointer;
    typedef T&                      reference;
};

template <class T>
struct bidirectional_iterator {
    typedef bidirectional_iterator_tag      iterator_category;
    typedef T                               value_type;
    typedef ptrdiff_t                       difference_type;
    typedef T*                              pointer;
    typedef T&                              reference;
};


template <class T>
struct random_access_iterator {
    typedef random_access_iterator_tag      iterator_category;
    typedef T                               value_type;
    typedef ptrdiff_t                       difference_type;
    typedef T*                              pointer;
    typedef T&                              reference;
};

template <class I>
struct iterator_traits {
    typedef typename I::iterator_category    iterator_category;
    typedef typename I::value_type           value_type;
    typedef typename I::difference_type      difference_type;
    typedef typename I::pointer              pointer;
    typedef typename I::reference            reference;
};

//iterator_traits' partition specialization
template <class I>
struct iterator_traits <I*> {
    typedef random_access_iterator_tag      iterator_category;
    typedef I                               value_type;
    typedef ptrdiff_t                       difference_type;
    typedef I*                              pointer;
    typedef I&                              reference;
};

template <class I>
struct iterator_traits <const I*> {
    typedef random_access_iterator_tag      iterator_category;
    typedef I                               value_type;
    typedef ptrdiff_t                       difference_type;
    typedef I*                              pointer;
    typedef I&                              reference;
};

template <class I>
inline typename iterator_traits<I>::iterator_category
iterator_category (const I& iterator) {
    typedef typename iterator_traits<I>::iterator_category iterator_category;
    return iterator_category ();
}

//这里我的理解是由于iterator自身的value_type应该是一个指针
template <class I>
inline typename iterator_traits<I>::value_type*
value_type (const I& iterator) {
    return static_cast <typename iterator_traits<I>::value_type *>(0);
}

template <class I>
inline typename iterator_traits<I>::difference_type*
difference_type (const I& iterator) {
    return static_cast <typename iterator_traits<I>::difference_type *>(0);
}
