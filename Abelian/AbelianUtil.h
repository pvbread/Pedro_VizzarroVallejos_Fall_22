#pragma once

#define START_ABELIAN_GAME(GameClass) \
	int main()\
	{ \
		GameClass __abelian__game;\
		__abelian__game.Run();\
		return 0;\
	}

#ifdef ABELIAN_WINDOWS
	#ifdef ABELIAN_LIB
		#define ABELIAN_API __declspec(dllexport)
	#else
		#define ABELIAN_API __declspec(dllimport)
	#endif
#else
	#define ABELIAN_API
#endif

#ifdef ABELIAN_DEBUG
	#define ABELIAN_LOG(x) std::cout << x << std::endl;
#else
	#define ABELIAN_LOG(x)
#endif