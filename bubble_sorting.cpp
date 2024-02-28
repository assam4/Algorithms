#include <iostream>
#include <vector>

template <typename T> // Forward_iterator type 
concept forward_iterator =
        std::input_iterator<T> &&
        std::derived_from<typename std::iterator_traits<T>::iterator_category, std::forward_iterator_tag> &&
        std::incrementable<T> &&
        std::sentinel_for<T, T>;

template <typename Container> // concept forward_iterator
concept ForwardContainer = requires(Container& container)   {
                                                                { container.begin() } -> forward_iterator;
                                                                { container.end() } -> forward_iterator;
                                                            };

template <ForwardContainer Container>
void bubble_sorting(Container& container)  // Bubble_sorting method for containers supporting  ForwardContainer concept 
{
    bool is_sorted = false ;
    while(!is_sorted)
    {
        is_sorted = true ;
        for(auto current = container.begin() ; current != container.end() ; ++current )
            if(current != container.begin())
            {
                if( *current < *(current - 1))
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
    bubble_sorting(vec);
    for (const auto& element : vec)
        std::cout << element << " ";

    return 0;
}