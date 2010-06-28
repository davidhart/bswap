#ifndef _UTIL_H
#define _UTIL_H

#include <iostream>

class Util
{
private:
	static inline void BSwapN(void* b, int n)
	{
		int i = 0;
		int j = n - 1;
		while (i < j)
		{
			std::swap(((unsigned char*)b)[i], ((unsigned char*)b)[j]);
			i++, j--;
		}
	}

	static inline void BSwap16(void * b)
	{
		__asm
		{
			mov eax, [b]
			mov bx, [eax]
			xchg bl, bh
			mov [eax], bx
		}
	}

	static inline void BSwap32(void * b)
	{
		__asm
		{
			mov eax, [b]
			mov ebx, [eax]
			bswap ebx
			mov [eax], ebx
		}
	}

	static inline void BSwap64(void * b)
	{
		__asm
		{
			mov ecx, dword ptr[b]
			mov eax, [ecx]
			lea edx, [ecx]+4
			mov ebx, [edx]

			bswap eax
			bswap ebx

			mov [ecx], ebx 
			mov [edx], eax
		}
	}

public:
	template <size_t S> static void BSwap(void* data) { BSwapN(data, S); }
	template <> static inline void BSwap<1>(void* data) { }
	template <> static inline void BSwap<2>(void* data) { BSwap16(data); }
	template <> static inline void BSwap<4>(void* data) { BSwap32(data); }
	template <> static inline void BSwap<8>(void* data) { BSwap64(data); }

	template <class T> static inline void BSwap( T& data )
	{
		BSwap<sizeof(T)>(&data);
	}

};

#endif