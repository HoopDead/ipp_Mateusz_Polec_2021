#include "Bitmask.hpp"

Bitmask::Bitmask() : m_bits(0) { }

void Bitmask::SetMask(Bitmask& other) {
	m_bits = other.GetMask();
}

uint32_t Bitmask::GetMask() const {
	return m_bits;
}

bool Bitmask::GetBit(int pos) const {
	return (m_bits & (1 << pos)) != 0;
}

void Bitmask::SetBit(int pos, bool on) {
	on ? SetBit(pos) : ClearBit(pos);
}

void Bitmask::SetBit(int pos) {
	m_bits = m_bits | 1 << pos;
}

void Bitmask::ClearBit(int pos) {
	m_bits = m_bits & ~(1 << pos);
}

void Bitmask::Clear() {
	m_bits = 0;
}


