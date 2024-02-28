#include <concepts>
#include <algorithm>
#include <vector>
#include <iostream>

template <typename Container>  // limitation for correct operation
concept Bidirectional_support = requires(Container& container) { std::bidirectional_iterator<decltype(container.begin())>; };

template <Bidirectional_support Container>
void bubble_sorting(Container& container)  
{
    bool is_sorted = false ;
    while(!is_sorted)
    {
        is_sorted = true ;
        for(auto current = container.begin() ; current != container.end() ; ++current )
            if(current != container.begin())
            {
                if(*current < *(current - 1))
               {
                 std::iter_swap(current, current - 1);
                 is_sorted = false ;
               }
            }
    }
}

int main()
{
    std::vector<int> vec = {5, 3, 1, 4, 2};
    static_assert(Bidirectional_support<decltype(vec)>);  // check concept
    bubble_sorting(vec);
    for (const auto& element : vec)
        std::cout << element << " ";
    return 0;
}
