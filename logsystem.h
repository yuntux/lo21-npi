#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H
#include "logmessage.h"

class LogSystem
{
    static LogSystem* instance;

public:
    LogSystem();
    static LogSystem& getInstance();
    static void libereInstance();
    void ajouterFichierLog(LogMessage m);
    void ajouterConsoleLog(LogMessage m);
    void ajouterConsoleEtFichierLog(LogMessage m);
protected:
    LogSystem(const LogSystem&){}
    void operator=(const LogSystem &);
};

#endif // LOGSYSTEM_H
