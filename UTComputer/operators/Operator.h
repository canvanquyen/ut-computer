#ifndef TESTLO21CLION_OPERATOR_H
#define TESTLO21CLION_OPERATOR_H

#include <iostream>
#include <string>
#include "../stack/StackUTComputer.h"
#include "../exceptions/UTComputerException.h"
using namespace std;

class Operator {
protected:
    int arity;
    string key;
    int priority;
public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    Operator(int nb, string key, int prio) : arity(nb), key(key), priority(prio) {
    }
    virtual ~Operator() { }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================
    int getArite() const {
        return arity;
    }

    const string &getKey() const {
        return key;
    }

    int getPriority() const {
        return priority;
    }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                     Interface for subclasses                  ==========================
    // ===============================================================================================================

/*
     * Address of stack must not be changed, but "st" do not point to a const stack : we use a constant pointer
     * and not a pointer to constant
     */
    virtual void execute(StackUTComputer * const st) = 0;
    // ===============================================================================================================
};


#endif //TESTLO21CLION_OPERATOR_H
