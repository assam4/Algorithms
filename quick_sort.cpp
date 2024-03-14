#include <concepts>
#include <algorithm>
#include <vector>
#include <iostream>

const int Unit = 1;
const int Half = 2;

template <typename T>  // limitation for correct operation
concept Bidirectional_iterator = requires(T) 
{ 
    typename std::iterator_traits<T>::iterator_category;  // std::bidirectional_iterator<T>;
};

template <Bidirectional_iterator _iterator>
void qsort(_iterator first, _iterator last )  
{
    auto left = first;
    auto right = last ;
    auto middle = std::next(left, std::distance(left, right) / Half);
    
    do
    {
        while (*left < *middle) ++left;
        while (*right > *middle) --right;
    
        if (left <= right) 
        {
            std::iter_swap(left, right);
            ++left;
            --right;
        }
    }
    while (left != right && left < right); 

    if (right > first) qsort(first, right);
    if (left < last) qsort(left, last);
}

int main()
{
    std::vector<int> vec = { 5 , 3 , 1 , 4, 2 , 6 , 9 , 10 , 7 , 8 };
    static_assert(Bidirectional_iterator<decltype(vec.begin())>);  // check concept
    qsort(vec.begin(), (vec.end() - Unit));
    for (const auto& element : vec)
        std::cout << element << " ";
    return 0;
}
