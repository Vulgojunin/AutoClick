#ifndef ICONTROLLEROBSERVER_H
#define ICONTROLLEROBSERVER_H

class IControllerObserver {
public:
    virtual ~IControllerObserver() = default;

    // Chamado quando o motor inicia o loop de cliques
    virtual void onExecutionStarted() = 0;

    // Chamado quando o motor encerra a execução (por erro ou comando de stop)
    virtual void onExecutionStopped() = 0;
};

#endif // ICONTROLLEROBSERVER_H