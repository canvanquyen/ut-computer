#ifndef UTCOMPUTER_OPERATORDIVISION_H
#define UTCOMPUTER_OPERATORDIVISION_H

#include "Operator.h"
#include "../literals/ComplexLiteral.h"
#include "../literals/ExpressionLiteral.h"

class OperatorDivision : public Operator {

public:
    OperatorDivision() : Operator(2, "/") { }
    virtual ~OperatorDivision() { }


private:

    /* Tests done before in superclass :
     *      - test that pointer to stack is not null
     *      - test that stack contains enough Literal* (st.size() >= operator arity)
     *      - test that every Literal* unstacked isn't null
     *
     * OperatorDivision applies to
     *      - two ComplexLiterals
     *      - two ExpressionLiteral
     *      - an ExpressionLiteral and a ComplexLiteral */
    virtual Literal* executeSpecificOperator(StackUTComputer *st) override {
        /* Verification that we do not perform divisions by zero is made in ComplexLiteral and NumericLiteral
         * and exceptions raised are caught here */
        try {
            Literal* a = arguments[0];
            Literal* b = arguments[1];
            ComplexLiteral* comp_a = dynamic_cast<ComplexLiteral*>(a);
            ComplexLiteral* comp_b = dynamic_cast<ComplexLiteral*>(b);
            ExpressionLiteral* exp_a = dynamic_cast<ExpressionLiteral*>(a);
            ExpressionLiteral* exp_b = dynamic_cast<ExpressionLiteral*>(b);

            // if the two literals are instance of ComplexLiteral
            if (comp_a != nullptr && comp_b != nullptr)
                return *comp_a / *comp_b; // ComplexLiteral::operator/(ComplexLiteral &l) const


            // if the two literals are instance of ExpressionLiteral
            if (exp_a != nullptr && exp_b != nullptr)
                return *exp_a / *exp_b; // ExpressionLiteral::operator/(ExpressionLiteral &l) const


            /* If one of the two arguments isn't instance of ComplexLiteral then it must be instance of
             * ExpressionLiteral. Otherwise, it's an illegal argument.*/

            // if the first element is instance of ComplexLiteral but not the second
            if (comp_a != nullptr) {
                /* then b is not instance of ComplexLiteral (because of the first if statement) and can only be instance of
                 * ExpressionLiteral. If not, then b is an illegal argument */
                if (exp_b != nullptr) {
                    /* division between Complex and Expression is in fact division between two Expression :
                     *      We have to create a temporary Expression with the Complex::toString() function
                     *      and then apply division between the two Expression */
                    ExpressionLiteral tmp(comp_a->toString());
                    return tmp / *exp_b; // ExpressionLiteral::operator/(ExpressionLiteral &l) const
                }
                else {
                    throw UTComputerException("Error in OperatorDivision::executeSpecificOperator : second argument has invalid type.");
                }
            }

            // if the second element is instance of ComplexLiteral but not the first
            if (comp_b != nullptr) {
                /* then a is not instance of ComplexLiteral (because of the first if statement) and can only be instance of
                 * ExpressionLiteral. If not, then b is an illegal argument */
                if (exp_a != nullptr) {
                    /* division between Complex and Expression is in fact division between two Expression :
                     *      We have to create a temporary Expression with the Complex::toString() function
                     *      and then apply division between the two Expression */
                    ExpressionLiteral tmp(comp_b->toString());
                    return *exp_a / tmp; // ExpressionLiteral::operator/(ComplexLiteral &l) const
                }
                else {
                    throw UTComputerException("Error in OperatorDivision::executeSpecificOperator : first argument is of invalid type.");
                }
            }


            // Here we didn't return anything or throw any exception, so both arguments have invalid type.
            throw UTComputerException("Error in OperatorDivision::executeSpecificOperator : invalid literal types for both arguments");
        }
        catch (UTComputerException e) {
            UTComputerException e1(e.getMessage());
            e1.insertBefore(" --> ");
            e1.insertBefore(arguments[1]->toString());
            e1.insertBefore(" and ");
            e1.insertBefore(arguments[0]->toString());
            e1.insertBefore("Error in applying OperatorDivision on ");
            throw e1;
        }
    }
};


#endif //UTCOMPUTER_OPERATORDIVISION_H
