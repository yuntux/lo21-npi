#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H
#include <QtGui>

enum level {warning, error};

class LogMessage
{
    enum level _level;
    QString _message;

public:
    LogMessage();
    QString getMessage() const {return _message;}
    QString getLevel() const {
        if (_level==warning) return "Warning";
        if (_level==error) return "Error";
    }
};

#endif // LOGMESSAGE_H
