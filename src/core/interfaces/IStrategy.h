#ifndef ISTRATEGY_H
#define ISTRATEGY_H

class IStrategy {
public:
    virtual ~IStrategy() = default;
    
    // O "Contrato": Toda estratégia PRECISA implementar o wait
    virtual void wait() = 0; 
};

#endif // ISTRATEGY_H