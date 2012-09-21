#define DLL_EXPORT

#ifdef _WINDOWS
#	ifdef DLL_EXPORT
#		define LIBEXPORT __declspec(dllexport)
#	else
#		define LIBEXPORT __declspec(dllimport)
#	endif
#endif