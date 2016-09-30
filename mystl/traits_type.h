/*************************************************************************
    > File Name: __type_traits.h
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年09月30日 星期五 18时48分22秒
 ************************************************************************/

struct __true_type {};
struct __false_type {};

//将所有的类型全部定义为__false_type，再进行特化
template <class T>
struct __type_traits {
    typedef __false_type    has_trivial_default_constructor;
    typedef __false_type    has_trivial_copy_constructor;
    typedef __false_type    has_trivial_assignment_constructor;
    typedef __false_type    has_trivial_destructor;
    typedef __false_type    is_POD_type;
};

//特化版本，应用于内置的类型
template<>
struct __type_traits <char> {
    typedef __true_type     has_trivial_default_constructor;
    typedef __true_type     has_trivial_copy_constructor;
    typedef __true_type     has_trivial_assignment_constructor;
    typedef __true_type     has_trivial_destructor;
    typedef __true_type     is_POD_type;
};

template<>
struct __type_traits <signed char> {
    typedef __true_type     has_trivial_default_constructor;
    typedef __true_type     has_trivial_copy_constructor;
    typedef __true_type     has_trivial_assignment_constructor;
    typedef __true_type     has_trivial_destructor;
    typedef __true_type     is_POD_type;
};

template<>
struct __type_traits <unsigned char> {
    typedef __true_type     has_trivial_default_constructor;
    typedef __true_type     has_trivial_copy_constructor;
    typedef __true_type     has_trivial_assignment_constructor;
    typedef __true_type     has_trivial_destructor;
    typedef __true_type     is_POD_type;
};

template<>
struct __type_traits <short> {
    typedef __true_type     has_trivial_default_constructor;
    typedef __true_type     has_trivial_copy_constructor;
    typedef __true_type     has_trivial_assignment_constructor;
    typedef __true_type     has_trivial_destructor;
    typedef __true_type     is_POD_type;
};

template<>
struct __type_traits <unsigned short> {
    typedef __true_type     has_trivial_default_constructor;
    typedef __true_type     has_trivial_copy_constructor;
    typedef __true_type     has_trivial_assignment_constructor;
    typedef __true_type     has_trivial_destructor;
    typedef __true_type     is_POD_type;
};

template<>
struct __type_traits <int> {
    typedef __true_type     has_trivial_default_constructor;
    typedef __true_type     has_trivial_copy_constructor;
    typedef __true_type     has_trivial_assignment_constructor;
    typedef __true_type     has_trivial_destructor;
    typedef __true_type     is_POD_type;
};

template<>
struct __type_traits <unsigned int> {
    typedef __true_type     has_trivial_default_constructor;
    typedef __true_type     has_trivial_copy_constructor;
    typedef __true_type     has_trivial_assignment_constructor;
    typedef __true_type     has_trivial_destructor;
    typedef __true_type     is_POD_type;
};

template<>
struct __type_traits <long> {
    typedef __true_type     has_trivial_default_constructor;
    typedef __true_type     has_trivial_copy_constructor;
    typedef __true_type     has_trivial_assignment_constructor;
    typedef __true_type     has_trivial_destructor;
    typedef __true_type     is_POD_type;
};

template<>
struct __type_traits <unsigned long> {
    typedef __true_type     has_trivial_default_constructor;
    typedef __true_type     has_trivial_copy_constructor;
    typedef __true_type     has_trivial_assignment_constructor;
    typedef __true_type     has_trivial_destructor;
    typedef __true_type     is_POD_type;
};

template<>
struct __type_traits <float> {
    typedef __true_type     has_trivial_default_constructor;
    typedef __true_type     has_trivial_copy_constructor;
    typedef __true_type     has_trivial_assignment_constructor;
    typedef __true_type     has_trivial_destructor;
    typedef __true_type     is_POD_type;
};

template<>
struct __type_traits <double> {
    typedef __true_type     has_trivial_default_constructor;
    typedef __true_type     has_trivial_copy_constructor;
    typedef __true_type     has_trivial_assignment_constructor;
    typedef __true_type     has_trivial_destructor;
    typedef __true_type     is_POD_type;
};

template<>
struct __type_traits <long double> {
    typedef __true_type     has_trivial_default_constructor;
    typedef __true_type     has_trivial_copy_constructor;
    typedef __true_type     has_trivial_assignment_constructor;
    typedef __true_type     has_trivial_destructor;
    typedef __true_type     is_POD_type;
};

template<class T>
struct __type_traits <T*> {
    typedef __true_type     has_trivial_default_constructor;
    typedef __true_type     has_trivial_copy_constructor;
    typedef __true_type     has_trivial_assignment_constructor;
    typedef __true_type     has_trivial_destructor;
    typedef __true_type     is_POD_type; 
};
