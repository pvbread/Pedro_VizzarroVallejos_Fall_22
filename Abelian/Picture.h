#pragma once

#include "pch.h"
#include "AbelianUtil.h"
#include "PictureImplementation.h"

namespace Abelian
{
	class ABELIAN_API Picture
	{
	public:
		Picture(const std::string& soureFile);
		Picture(const std::string&& soureFile);

		int GetHeight() const;
		int GetWidth() const;

		void Activate();

	private:
		PictureImplementation* mImplementation{ nullptr };
	};
}