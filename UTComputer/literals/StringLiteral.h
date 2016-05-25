#ifndef TESTLO21CLION_STRINGLITERAL_H
#define TESTLO21CLION_STRINGLITERAL_H

#include "Literal.h"

class StringLiteral : public Literal {
protected:
    string value;
public:

    // ===============================================================================================================
    // ======================               Constructors and Destructors                    ==========================
    // ===============================================================================================================
    StringLiteral(const string &value) : value(value) { }
    virtual ~StringLiteral() { }
    // ===============================================================================================================




    // ===============================================================================================================
    // ======================                       Getters and Setters                     ==========================
    // ===============================================================================================================
    const string &getValue() const {
        return value;
    }

    void setValue(const string &val) {
        value = val;
    }
    // ===============================================================================================================





    // ===============================================================================================================
    // ======================                         Override Methods                      ==========================
    // ===============================================================================================================
    virtual string toString() const override = 0;
    // ===============================================================================================================

};


#endif //TESTLO21CLION_STRINGLITERAL_H
