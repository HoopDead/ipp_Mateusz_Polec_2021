#include "Bitmask.h"

Bitmask::Bitmask() : m_bits(0) { }

void Bitmask::setMask(Bitmask& other) {
	m_bits = other.getMask();
}

uint32_t Bitmask::getMask() const {
	return m_bits;
}

bool Bitmask::getBit(int pos) const {
	return (m_bits & (1 << pos)) != 0;
}

void Bitmask::setBit(int pos, bool on) {
	on ? setBit(pos) : clearBit(pos);
}

void Bitmask::setBit(int pos) {
	m_bits = m_bits | 1 << pos;
}

void Bitmask::clearBit(int pos) {
	m_bits = m_bits & ~(1 << pos);
}

void Bitmask::clear() {
	m_bits = 0;
}


