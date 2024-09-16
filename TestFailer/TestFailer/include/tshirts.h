#pragma once
#ifdef TESTFAILER_EXPORTS
#define TESTFAILER_API __declspec(dllexport)
#else
#define TESTFAILER_API __declspec(dllimport)
#endif

namespace tShirts
{
    TESTFAILER_API char size(int cms);
}

