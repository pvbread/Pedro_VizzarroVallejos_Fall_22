#pragma once

#include "pch.h"
#include "AbelianUtil.h"

constexpr int FRAMES_PER_SECOND = 60;

namespace Abelian
{
	class ABELIAN_API AbelianApp
	{
	public:
		virtual void OnUpdate();
		void Run();
	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / FRAMES_PER_SECOND };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}

