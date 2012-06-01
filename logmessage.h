#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H
#include <QtGui>

class LogMessage
{
    enum level _level;
    QString message;
public:
    LogMessage();
};

#endif // LOGMESSAGE_H
