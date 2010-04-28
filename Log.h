#ifndef LOG_H_GUARD
#define LOG_H_GUARD

#include <string>

class Log
{
public:
    struct ELevel {
        enum E {
            eDebug,
            eInfo,
            eWarn,
            eError
        };
    };

    Log(const std::string & name);

    void debug(const std::string & line);
    void debugf(const char * line, ...) __attribute__ ((format (printf, 2, 3)));

    void info(const std::string & line);
    void infof(const char * line, ...) __attribute__ ((format (printf, 2, 3)));

    void warn(const std::string & line);
    void warnf(const char * line, ...) __attribute__ ((format (printf, 2, 3)));

    void error(const std::string & line);
    void errorf(const char * line, ...) __attribute__ ((format (printf, 2, 3)));

    static void setLevel(ELevel::E l) { level_ = l; }

private:
    static const std::string & getLevelName(ELevel::E level);
    static void prepareDatetime();

    void log(ELevel::E level, const std::string & line);

    static const int BUF_LEN = 4096;
    static const int DATETIME_BUF_LEN = 25;
    static char buf_[];
    static char datetime_buf_[];

    static ELevel::E level_;

    std::string name_;
};

#endif

