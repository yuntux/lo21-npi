#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H
#include "logmessage.h"

class LogSystem
{
    void ajouterFichierLog(LogMessage m);
    void ajouterConsoleLog(LogMessage m);
public:
    LogSystem();
};

#endif // LOGSYSTEM_H
