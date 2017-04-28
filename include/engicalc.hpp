#ifndef ENGICALC_HPP
#define ENGICALC_HPP

#include<deque>
#include<stack>

#include "tokenizer.hpp"
#include "missmatched_engicalc_expression.hpp"

#include "addition.hpp"
#include "number.hpp"
namespace engicalc
{
    using Stack = std::stack<Token>;
    using Queue = std::deque<Token>;

    class EngiCalc
    {
        public:
            std::string calculate(const std::string&);
        
        private:
            
            Queue shuntingYard(Tokens&);

            std::string evalRPN(Queue&); 

            Tokenizer tokenFactory;

    };
}


#endif /*engicalc.hpp*/
