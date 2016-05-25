#ifndef UTCOMPUTER_OPERATORDIVISION_H
#define UTCOMPUTER_OPERATORDIVISION_H

#include "Operator.h"
#include "../literals/ComplexLiteral.h"
#include "../literals/ExpressionLiteral.h"

using namespace std;

class OperatorDivision : public Operator {

public:
    OperatorDivision() : Operator(2, "/") { }
    virtual ~OperatorDivision() { }


private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================

    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorDivision applies to
     *      - two ComplexLiterals
     *      - two ExpressionLiteral
     *      - an ExpressionLiteral and a ComplexLiteral */
    virtual shared_ptr<Literal> executeSpecificOperator() override;

    // ===============================================================================================================
};


#endif //UTCOMPUTER_OPERATORDIVISION_H
