#ifndef UTCOMPUTER_MINUSOPERATOR_H
#define UTCOMPUTER_MINUSOPERATOR_H

#include "Operator.h"
#include "../literals/ComplexLiteral.h"
#include "../literals/ExpressionLiteral.h"

class OperatorMinus : public Operator {

public:
    OperatorMinus() : Operator(2, "-") { }
    virtual ~OperatorMinus() { }

private:

    virtual Literal* executeSpecificOperator(StackUTComputer *st) override {
        /* test done before in superclass :
         *      - test that pointer to stack is not null
         *      - test that stack contains enough Literal* (st.size() >= operator arity)
         *      - test that every Literal* unstacked isn't null
         * */
        try {
            return applyOperator(arguments[0], arguments[1]);
        }
        catch (UTComputerException e) {
            UTComputerException e1(e.getMessage());
            e1.insertBefore(" --> ");
            e1.insertBefore(arguments[1]->toString());
            e1.insertBefore(" and ");
            e1.insertBefore(arguments[0]->toString());
            e1.insertBefore("Error in applying OperatorMinus on ");
            throw e1;
        }
    }


    Literal* applyOperator(Literal* a, Literal* b) {
        ComplexLiteral* comp_a = dynamic_cast<ComplexLiteral*>(a);
        ComplexLiteral* comp_b = dynamic_cast<ComplexLiteral*>(b);
        ExpressionLiteral* exp_a = dynamic_cast<ExpressionLiteral*>(a);
        ExpressionLiteral* exp_b = dynamic_cast<ExpressionLiteral*>(b);

        // if the two literals are instance of ComplexLiteral
        if (comp_a != nullptr && comp_b != nullptr) {
            return *comp_a - *comp_b; // ComplexLiteral::operator-(ComplexLiteral &l) const
        }

        // if the two literals are instance of ExpressionLiteral
        else if (exp_a != nullptr && exp_b != nullptr) {
            return *exp_a - *exp_b; // ExpressionLiteral::operator-(ExpressionLiteral &l) const
        }

        // if one of the two elements is not instance of ComplexLiteral
        else if (comp_a != nullptr) {
            /* then b is not instance of ComplexLiteral and can only be instance of
                *  ExpressionLiteral. If not, then b is an illegal argument for OperatorPlus */
            if (exp_b != nullptr) {
                /* Addition between Complex and Expression is in fact addition between two Expression :
                 *      We have to create a temporary Expression with the Complex::toString() function
                 *      and then apply addition between the two Expression */
                ExpressionLiteral tmp(comp_a->toString());
                return tmp - *exp_b; // ExpressionLiteral::operator-(ExpressionLiteral &l) const
            }
            else {
                UTComputerException e(exp_b->toString());
                e.insertBefore("Error in OperatorPlus::applyOperator : second argument has invalid type.");
                throw e;
            }
        }
        else if (comp_b != nullptr) {
            /* then a is not instance of ComplexLiteral and can only be instance of
                *  ExpressionLiteral. If not, then a is an illegal argument for OperatorPlus */
            if (exp_a != nullptr) {
                /* Addition between Complex and Expression is in fact addition between two Expression :
                 *      We have to create a temporary Expression with the Complex::toString() function
                 *      and then apply addition between the two Expression */
                ExpressionLiteral tmp(comp_b->toString());
                return *exp_a - tmp; // ExpressionLiteral::operator-(ComplexLiteral &l) const
            }
            else {
                UTComputerException e(exp_a->toString());
                e.insertBefore("Error in OperatorPlus::applyOperator : first argument is of invalid type.");
                throw e;
            }
        }
        else {
            UTComputerException e(a->toString());
            e.insertBefore(" and ");
            e.insertBefore(b->toString());
            e.insertBefore("Error in OperatorPlus::applyOperator : invalid literal types for both arguments");
            throw e;
        }
    }
};


#endif //UTCOMPUTER_MINUSOPERATOR_H
