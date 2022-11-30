#pragma once
#include "pch.h"

namespace Abelian
{
	class PictureImplementation
	{
	public:
		virtual int GetHeight() const = 0;
		virtual int GetWidth() const = 0;

		virtual void Activate() = 0;
	};
}