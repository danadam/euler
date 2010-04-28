#include "Log.h"

#include <cstdarg>
#include <cstdio>
#include <iostream>

#include <sys/time.h>

using namespace std;

char Log::buf_[BUF_LEN];
char Log::datetime_buf_[DATETIME_BUF_LEN];

Log::ELevel::E Log::level_ = Log::ELevel::eDebug;

Log::Log(const std::string & name)
{
    name_ = name;
}

void
Log::debug(const std::string & line) {
    if (level_ <= ELevel::eDebug) {
        log(ELevel::eDebug, line);
    }
}

void
Log::debugf(const char * line, ...) {
    if (level_ <= ELevel::eDebug && line != NULL) {
        va_list args;
        va_start(args, line);
        vsnprintf(buf_, BUF_LEN, line, args);
        va_end(args);

        debug(buf_);
    }
}

void
Log::error(const std::string & line) {
    if (level_ <= ELevel::eError) {
        log(ELevel::eError, line);
    }
}

void
Log::errorf(const char * line, ...) {
    if (level_ <= ELevel::eError && line != NULL) {
        va_list args;
        va_start(args, line);
        vsnprintf(buf_, BUF_LEN, line, args);
        va_end(args);

        error(buf_);
    }
}

void
Log::info(const std::string & line) {
    if (level_ <= ELevel::eInfo) {
        log(ELevel::eInfo, line);
    }
}

void
Log::infof(const char * line, ...) {
    if (level_ <= ELevel::eInfo && line != NULL) {
        va_list args;
        va_start(args, line);
        vsnprintf(buf_, BUF_LEN, line, args);
        va_end(args);

        info(buf_);
    }
}

const std::string &
Log::getLevelName(ELevel::E level) {
    static const std::string DEBUG("DEBUG ");
    static const std::string INFO (" INFO ");
    static const std::string WARN (" WARN ");
    static const std::string ERROR("ERROR ");
    static const std::string EMPTY;

    switch (level) {
        case ELevel::eDebug:
            return DEBUG;
        case ELevel::eInfo:
            return INFO;
        case ELevel::eWarn:
            return WARN;
        case ELevel::eError:
            return ERROR;
        default:
            return EMPTY;
    }
}

void
Log::log(ELevel::E level, const std::string & line) {
    prepareDatetime();

    cout << datetime_buf_ << getLevelName(level) << name_ << ": " << line << endl;
}

void
Log::prepareDatetime() {
    // Get current time
    timeval tv;
    struct timezone tz;
    gettimeofday(&tv,&tz);

    // Change data to normal format
    tm f;
    localtime_r(&tv.tv_sec, &f);
    snprintf(datetime_buf_, DATETIME_BUF_LEN, "%04d-%02d-%02d %02d:%02d:%02d.%03d ",
            (f.tm_year + 1900), (f.tm_mon + 1), f.tm_mday,
            f.tm_hour, f.tm_min, f.tm_sec, (int)(tv.tv_usec / 1000)
        );
}

void
Log::warn(const std::string & line) {
    if (level_ <= ELevel::eWarn) {
        log(ELevel::eWarn, line);
    }
}

void
Log::warnf(const char * line, ...) {
    if (level_ <= ELevel::eWarn && line != NULL) {
        va_list args;
        va_start(args, line);
        vsnprintf(buf_, BUF_LEN, line, args);
        va_end(args);

        warn(buf_);
    }
}

