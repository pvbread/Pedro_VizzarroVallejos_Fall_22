#include "pch.h"
#include "Event.h"

Abelian::KeyPressedEvent::KeyPressedEvent(int codeOfKey)
{
	mKeyCode = codeOfKey;
}

int Abelian::KeyPressedEvent::GetKeyCode() const
{
	return mKeyCode;
}

Abelian::KeyReleasedEvent::KeyReleasedEvent(int codeOfKey)
{
	mKeyCode = codeOfKey;
}

int Abelian::KeyReleasedEvent::GetKeyCode() const
{
	return mKeyCode;
}
