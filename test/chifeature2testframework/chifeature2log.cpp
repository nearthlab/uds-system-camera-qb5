////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017-2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  chifeature2log.cpp
/// @brief Implementation of logging framework.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "chifeature2log.h"

#include <stdarg.h>

ChiFeature2Log CF2Log;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Constructor for ChiFeature2Log
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ChiFeature2Log::ChiFeature2Log()
{
    // Set default log level to debug and above messages
    m_eLogLevel = eDebug;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Helper function for logging
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::string ChiFeature2Log::GetMSGPrefixString(
    verboseSeverity severity)  ///< [in] severity level
{
    switch (severity)
    {
    case eEntry:        return "[ENTRY] ";
    case eExit:         return "[ EXIT] ";
    case eDebug:        return "[DEBUG] ";
    case eInfo:         return "[ INFO] ";
    case ePerformance:  return "[ PERF] ";
    case eUnsupported:  return "[UNSUP] ";
    case eWarning:      return "[ WARN] ";
    case eError:        return "[ERROR] ";
    default:
        return "Severity Unsupported";
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Sets the logging level
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ChiFeature2Log::SetLogLevel(
    verboseSeverity level)
{
    switch (level)
    {
    case eEntry:        m_eLogLevel = eEntry;
        break;
    case eExit:         m_eLogLevel = eExit;
        break;
    case eDebug:        m_eLogLevel = eDebug;
        break;
    case eInfo:         m_eLogLevel = eInfo;
        break;
    case ePerformance:  m_eLogLevel = ePerformance;
        break;
    case eUnsupported:  m_eLogLevel = eUnsupported;
        break;
    case eWarning:      m_eLogLevel = eWarning;
        break;
    case eError:        m_eLogLevel = eError;
        break;
    default:
        return -1;
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Print the message to console and logcat
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ChiFeature2Log::Log(verboseSeverity severity, const char* mFormat, ...)
{
    std::string fullMessage;
    char message[CF2_STRLEN_MAX];
    //variable argument inputs
    //TODO: Add a try-catch for vsnprintf
    va_list args;
    va_start(args, mFormat);
    vsnprintf(message, CF2_STRLEN_MAX-1, mFormat, args);
    va_end(args);

    fullMessage = GetMSGPrefixString(severity) + message;

    // Print to console
    fprintf(stdout, "%s\n", fullMessage.c_str());
}