#include "catch.h"
#include <od.h>

template<class T>
constexpr T max(T a, T b)
{
    return (a < b) ? b : a;
}


template<size_t COUNT>
constexpr size_t max_();

template<>
constexpr size_t max_<0>()
{
    return 0;
}

template <size_t COUNT, class FIRST, typename... REST>
constexpr size_t max_()
{
    return max(sizeof(FIRST), max_<sizeof ... (REST), REST...>());
}

template<class ... ARGS>
constexpr size_t max_buffer_size()
{
	return max_<sizeof...(ARGS), ARGS ...>();
}




template<size_t COUNT>
constexpr size_t align_();

template<>
constexpr size_t align_<0>()
{
    return 0;
}

template <size_t COUNT, class FIRST, typename... REST>
constexpr size_t align_()
{
    return max(std::alignment_of<FIRST>::value, align_<sizeof ... (REST), REST...>());
}


template<class ... ARGS>
constexpr size_t alignment_value()
{
	return align_<sizeof...(ARGS), ARGS ...>();
}



template<class ... ARGS>
struct Buffer
{
private:
	using Self_t = Buffer<ARGS...>;

	static constexpr std::size_t Alignment = alignment_value<ARGS...>();
	static constexpr std::size_t Size = max_buffer_size<ARGS...>();

	alignas(Alignment) uint8_t s_[Size];
	size_t pos_ = 0;


public:
	template<class T>
	operator T () const
	{
		return *reinterpret_cast<T const*>(s_);
	}

	template<class T>
	bool operator==(T const& val)
	{
		return *reinterpret_cast<T const*>(s_) == val;
	}

	template<class T>
	Self_t& operator=(T const& value)
	{
		(*reinterpret_cast<T*>(s_)) = value;
		pos_ = 0;
		return *this;
	}

	void put(uint8_t byte)
	{
		s_[pos_++] = byte;
	}

	uint8_t get()
	{
		return s_[pos_++];
	}

	void reset()
	{
		pos_ = 0;
	}
};




struct foo
{
	int a, b;
	double c;
};


TEST_CASE("calculate max buffer size")
{

	REQUIRE(max_buffer_size() == 0);
	REQUIRE((max_buffer_size<bool>()) == 1);
	REQUIRE((max_buffer_size<bool, bool>()) == 1);
	REQUIRE((max_buffer_size<bool, uint16_t>()) == 2);
	REQUIRE((max_buffer_size<bool, uint16_t, foo>()) == 16);
}

TEST_CASE("calculate alignment")
{
	REQUIRE(alignment_value() == 0);
	REQUIRE((alignment_value<bool>()) == 1);
	REQUIRE((alignment_value<bool, bool>()) == 1);
	REQUIRE((alignment_value<bool, uint16_t>()) == 2);
	REQUIRE((alignment_value<bool, uint16_t, foo>()) == 8);
}


TEST_CASE("Buffer")
{
	Buffer<int, bool, float> buffer;

	buffer = false;

	bool val = (buffer == false);

	REQUIRE(val);

	buffer = true;

	val = (buffer == true);

	REQUIRE(val);



}