#pragma once
#include <debug.h>
#include <macro.h>
#include <generated/config.h>

#if CONFIG_LOGLEVEL == 'I'
    #define LOG_INSANE(str) log::log(__FILE__ ":" TOSTRING(__LINE__) " -> " str)
    #define LOG_DEBUG(str) log::log(__FILE__ ":" TOSTRING(__LINE__) " -> " str)
    #define LOG_NORMAL(str) log::log(__FILE__ ":" TOSTRING(__LINE__) " -> " str)
    #define LOG_FATAL(str) log::log(__FILE__ ":" TOSTRING(__LINE__) " -> " str)
#elif CONFIG_LOGLEVEL == 'D'
    #define LOG_INSANE(str)
    #define LOG_DEBUG(str) log::log(__FILE__ ":" TOSTRING(__LINE__) " -> " str)
    #define LOG_NORMAL(str) log::log(__FILE__ ":" TOSTRING(__LINE__) " -> " str)
    #define LOG_FATAL(str) log::log(__FILE__ ":" TOSTRING(__LINE__) " -> " str)
#elif CONFIG_LOGLEVEL == 'N'
    #define LOG_INSANE(str)
    #define LOG_DEBUG(str)
    #define LOG_NORMAL(str) log::log(__FILE__ ":" TOSTRING(__LINE__) " -> " str)
    #define LOG_FATAL(str) log::log(__FILE__ ":" TOSTRING(__LINE__) " -> " str)
#elif CONFIG_LOGLEVEL == 'F'
    #define LOG_INSANE(str)
    #define LOG_DEBUG(str)
    #define LOG_NORMAL(str)
    #define LOG_FATAL(str) log::log(__FILE__ ":" TOSTRING(__LINE__) " -> " str)
#else
    #define LOG_INSANE(str)
    #define LOG_DEBUG(str)
    #define LOG_NORMAL(str)
    #define LOG_FATAL(str)
#endif

namespace log {
    void log(const char *str);
    void log_service(const char *servicename, const char *str, bool issue = false);
}