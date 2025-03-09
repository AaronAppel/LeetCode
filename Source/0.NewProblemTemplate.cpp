
// Link to leetcode problem https://leetcode.com/problemset/

// #include "Helpers.h"
#include "Problem.h"

// #TODO Move class declaration to Problem.h file
class ProblemNewProblem : public Problem
{
public:
    ProblemNewProblem(const std::string& m_name, unsigned short m_number);

    virtual void Run(unsigned char solutionNumber) override;
};

ProblemNewProblem::ProblemNewProblem(const std::string& m_name, unsigned short m_number) :
    Problem(m_name, m_number)
{
    // #TODO Setup case data

    m_numberOfSolutions = 0;
}

void ProblemNewProblem::Run(unsigned char solutionNumber)
{
    // #TODO Execute 1 solution with all case data
}