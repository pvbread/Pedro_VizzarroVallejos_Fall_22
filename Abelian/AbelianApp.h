#pragma once

#include "pch.h"
#include "AbelianUtil.h"

namespace Abelian
{
	class ABELIAN_API AbelianApp
	{
	public:
		virtual void OnUpdate();
		void Run();
	private:
		//std::chrono::milliseconds mFrameDuration{};
	};
}

