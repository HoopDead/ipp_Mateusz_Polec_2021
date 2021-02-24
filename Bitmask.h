#pragma once

#include <stdint.h>

class Bitmask
{
public:
	/*
	* Constructor for Bitmask
	* Initalize the member bits in object
	* @Param: -
	* @Return: -
	*/
	Bitmask();

	/*
	* setMask method
	* Overwrites the bitmask with other bitmask
	* @Param: Bitmask object reference
	* @Return: -
	*/
	void setMask(Bitmask& other);

	/*
	* getMask method
	* Return binary representation of bitmask
	* @Param: -
	* @Return uint_32t variable that represents bitmask
	*/
	uint32_t getMask() const;

	/*
	* getBit method
	* Return logical value whether bit at given position is 1
	* @Param: int pos - position of bit that we want to check
	* @Return:  boolean - logic value of bit at given position
	*/
	bool getBit(int pos) const;

	/*
	* setBit method
	* Set bits at given position to 1 (one) or 0 (zero)
	* @Param: int pos - position of bit that we want to set
	* @Param: bool on - is the bit 1 (one) or 0 (zero)
	* @Return: -
	*/
	void setBit(int pos, bool on);

	/*
	* setBit method
	* Set bit at given position to 1 (one)
	* @Param: int pos - position of bit that we want to set to one
	*/
	void setBit(int pos);

	/*
	* clearBit method
	* Set bit at given position to 0 (zero)
	* @Param: int pos - position of bit that we want to set to zero
	*/
	void clearBit(int pos);

	/*
	* clear method
	* Set all bit in bitmask to 0 (zero)
	*/
	void clear();

private:
	uint32_t m_bits;
};