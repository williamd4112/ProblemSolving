#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

template <typename T>
T*
polynomial_addition(T *dest, T *src_a_begin, T *src_a_end, T *src_b_begin, T *src_b_end){
    for(; src_a_begin != src_a_end && src_b_begin != src_b_end;){
        if(*src_a_begin == *src_b_begin)
            *dest++ = *src_a_begin++ + *src_b_begin++;
        else if(*src_a_begin < *src_b_begin)
            *dest++ = *src_b_begin++;
        else
            *dest++ = *src_a_begin++;
    }
    
    while(src_a_begin != src_a_end)
        *dest++ = *src_a_begin++;
    while(src_b_begin != src_b_end)
        *dest++ = *src_b_begin++;
        
    return dest;
}


template <typename T, typename F>
T*
polynomial_addition(T *dest, T *src_a_begin, T *src_a_end, T *src_b_begin, T *src_b_end, F f, T zero){
    for(; src_a_begin != src_a_end && src_b_begin != src_b_end;){
        if(*src_a_begin == *src_b_begin)
            *dest++ = f(*src_a_begin++, *src_b_begin++);
        else if(*src_a_begin < *src_b_begin)
            *dest++ = f(zero, *src_b_begin++);
        else
            *dest++ = f(zero, *src_a_begin++);
    }
    
    while(src_a_begin != src_a_end)
        *dest++ = f(zero, *src_a_begin++);
    while(src_b_begin != src_b_end)
        *dest++ = f(zero, *src_b_begin++);
        
    return dest;
}


#endif