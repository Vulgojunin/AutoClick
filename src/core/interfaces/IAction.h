#ifndef IACTION_H
#define IACTION_H

class IAction {
public:
    virtual ~IAction() = default;

    // Executa a ação concreta (clique, pressionar tecla, etc.)
    virtual void execute() = 0;
};

#endif // IACTION_H