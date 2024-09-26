#pragma once
#ifdef TESTFAILER_EXPORTS
#define TESTFAILER_API __declspec(dllexport)
#else
#define TESTFAILER_API __declspec(dllimport)
#endif
#include <map>

namespace misaligned
{
    TESTFAILER_API int getZeroBasedColorCombinationIndex(int i, int j);
    TESTFAILER_API std::map<int, std::pair<std::string, std::string>> computeColorMap();
}
