#include <iostream>
#include <iterator>
#include <concepts>
#include <algorithm>
#include <vector>

static constexpr int Starting_count {0};

template< typename container>
    concept forward_support = requires (container obj)
    {
        std::forward_iterator<decltype(obj.begin())>;
    };
       


template <forward_support T>
void select_sort(T& container)
{
    int count = Starting_count ;
    while(count != std::distance(container.begin() , container.end()) )
    {
        auto start_element = std::next(container.begin(), count );
        for(auto step = start_element ; step != container.end(); ++step)
                if(step != start_element && *step < *start_element)
                        std::iter_swap(step ,start_element) ;
        ++count ;
    }
}


int main()
{
    std::vector<int> numbers = {5, 3, 1, 4, 2};
    static_assert(forward_support<decltype(numbers)>);  // check concept
    select_sort(numbers);
    for (const auto& element : numbers)
        std::cout << element << " ";
    return 0;
}