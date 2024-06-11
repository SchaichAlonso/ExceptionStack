#pragma once

#if _WIN32
#    if defined(ExceptionsAPI_DLLEXPORT)
#        define ExceptionsAPI __declspec(dllexport)
#    elif defined(ExceptionsAPI_DLLIMPORT)
#        define ExceptionsAPI __declspec(dllimport)
#    else
#        define ExceptionsAPI
#    endif
#else
#    if defined(ExceptionsAPI_DLLEXPORT)
#        define ExceptionsAPI __attribute__((visibility("default")))
#    elif defined(ExceptionsAPI_DLLIMPORT)
#        define ExceptionsAPI __attribute__((visibility("default")))
#    else
#        define ExceptionsAPI
#    endif
#endif