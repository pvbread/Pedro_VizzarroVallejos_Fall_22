#pragma once
#include "AbelianUtil.h"

namespace Abelian
{
	class ABELIAN_API KeyPressedEvent
	{
	public:
		KeyPressedEvent(int codeOfKey);
		KeyPressedEvent() = delete;

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class ABELIAN_API KeyReleasedEvent
	{
	public:
		KeyReleasedEvent(int codeOfKey);
		KeyReleasedEvent() = delete;

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};
}