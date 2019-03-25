#include <canopen/type_traits.h>
#include <canopen/od/access_type.h>
#include <canopen/od/index_type.h>
#include <tuple>
#include <algorithm>
#include <stdint.h>
#include <type_traits>

namespace canopen
{

namespace od
{


template<class LAST = void>
constexpr size_t max_buffer_size()
{
    return sizeof(LAST::base_type);
}

template<class FIRST, class... REST>
constexpr size_t max_buffer_size()
{
    return std::max(sizeof(FIRST::base_type), max_buffer_size<REST...>());
}


template<class ... ENTRIES>
struct ObjectDictionay : ENTRIES ...
{
	static size_t required_buffer_size()
	{
		return max_buffer_size<ENTRIES...>();
	}
};


} //namespace od

} //namespace canopen
