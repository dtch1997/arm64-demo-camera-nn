# ifndef 3DARRAY_H
# define 3DARRAY_H

#include <vector>
#include <tuple>

template <typename T> 
using 1darray = vector<T>;
using 2darray = vector<1darray>;
using 3darray = vector<2darray>;

template<typename T>
/*
 * Since we can't use Boost, I'm implementing a lightweight 3DArray
 */
class 3DArray<T>
{
    public: 
        3DArray<T>(tuple<T> size);
        T GetEntry(tuple<T> index);

    private: 
        3darray<T> data_;
}

# endif
