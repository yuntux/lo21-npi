#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H
#include "logmessage.h"

class LogSystem
{
    static LogSystem* instance;
    void ajouterFichierLog(LogMessage m);
    void ajouterConsoleLog(LogMessage m);
public:
    LogSystem();
    static LogSystem& getInstance();
    static void libereInstance();
protected:
    LogSystem(const LogSystem&){}
    void operator=(const LogSystem &);
};

#endif // LOGSYSTEM_H
