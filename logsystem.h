#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H
#include "logmessage.h"
#include <iostream>

class LogSystem
{
    static LogSystem* instance;

public:

    static LogSystem& getInstance();
    static void libereInstance();
    void ajouterFichierLog(LogMessage m);
    void ajouterConsoleLog(LogMessage m);
    void ajouterFcihierEtConsole(LogMessage m);

protected:
    LogSystem(const LogSystem&){}
    LogSystem();
    //virtual ~LogSystem(){}
    void operator=(const LogSystem &);
};

#endif // LOGSYSTEM_H
