#define DLL_EXPORT
#pragma warning( disable: 4251 4099 4204 )
#ifdef _WINDOWS
#	ifdef DLL_EXPORT
#		define LIBEXPORT __declspec(dllexport)
#	else
#		define LIBEXPORT __declspec(dllimport)
#	endif
#else
#	define LIBEXPORT
#endif