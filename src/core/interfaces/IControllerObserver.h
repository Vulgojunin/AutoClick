#ifndef ICONTROLLEROBSERVER_H
#define ICONTROLLEROBSERVER_H

enum class Status { Idle, Running, Paused, Error };

class IControllerObserver {
public:
    virtual ~IControllerObserver() = default;
    virtual void onStatusChanged(Status s) = 0;
    // Adicionamos para que a UI se atualize se o delay mudar via atalho
    virtual void onSettingsChanged(int delay, int clickType) = 0; 
};

#endif