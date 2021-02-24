#pragma once

#include <stdint.h>

class Bitmask
{
public:

	//TODO: Documentation
	Bitmask();

	//TODO: Documentation
	void setMask(Bitmask& other);

	//TODO: Documentation
	uint32_t getMask() const;

	//TODO: Documentation
	bool getBit(int pos) const;

	//TODO: Documentation
	void setBit(int pos, bool on);

	//TODO: Documentation
	void setBit(int pos);

	//TODO: Documentation
	void clearBit(int pos);

	//TODO: Documentation
	void clear();

private:

	uint32_t m_bits;
};