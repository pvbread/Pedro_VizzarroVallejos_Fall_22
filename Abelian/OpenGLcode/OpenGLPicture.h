#pragma once
#include "pch.h"
#include "../PictureImplementation.h"

namespace Abelian
{
	class OpenGLPicture : public PictureImplementation
	{
	public:
		OpenGLPicture(const std::string& pictureFile);
		OpenGLPicture(const std::string&& pictureFile);
		virtual int GetHeight() const override;
		virtual int GetWidth() const override;

		virtual void Activate() override;
	private:
		unsigned int mImage{ 0 };
		int mWidth{ 0 };
		int mHeight{ 0 };
}