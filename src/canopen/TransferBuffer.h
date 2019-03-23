#pragma once

namespace canopen
{


template<size_t ALLIGNMENT, size_t SIZE>
struct Buffer
{
private:
	using Self_t = Buffer<ALLIGNMENT, SIZE>;

	alignas(ALLIGNMENT) uint8_t s_[SIZE];
	size_t pos_ = 0;


public:
	template<class T>
	operator T () const
	{
		return *reinterpret_cast<T const*>(s_);
	}

	template<class T>
	T as() const
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


} //namespace canopen
