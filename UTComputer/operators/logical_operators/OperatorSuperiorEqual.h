#ifndef UTCOMPUTER_OPERATORSUPERIOREQUAL_H
#define UTCOMPUTER_OPERATORSUPERIOREQUAL_H
#include "../CalculationOperator.h"
#include "../../literals/ComplexLiteral.h"

class OperatorSuperiorEqual : public CalculationOperator {


public:

    OperatorSuperiorEqual() : CalculationOperator(2, ">=",2) {}
    virtual ~OperatorSuperiorEqual() {}

private:

    // ===============================================================================================================
    // ======================                 Implement Operator interface                  ==========================
    // ===============================================================================================================
    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorSuperiorEqual applies to
     *      - two ComplexLiterals with no imaginary parts
     */
    virtual shared_ptr<Literal> executeSpecificOperator() override;
    // ===============================================================================================================

};


#endif //UTCOMPUTER_OPERATORSUPERIOREQUAL_H
