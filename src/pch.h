#ifdef WIN32
#   include <Windows.h>
#   ifdef _DEBUG
#       include <crtdbg.h>
#   endif
#else
#   include <sys/time.h>
#   include <unistd.h>
#endif

//#include <algorithm>
#include <chrono>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>
#include <vector>