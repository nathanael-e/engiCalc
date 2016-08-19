#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

namespace engicalc
{
    class Token
    {

        enum Associativity{None, Left, Right};

        enum TokenType
        {
            Complex,
            Number,
            Function,
            Separator,
            Operator,
            LeftBracket,
            RightBracket
        };

        public:
 
            Token(TokenType, std::string);
        
            TokenType getType() const;

            int getPrecedance() const;

            bool hasLeftAssociativity() const;

            std::string getKey() const;

            bool operator==(const Token& ) const;

            bool operator!=(const Token&) const;

            bool operator>(const Token&) const;

            bool operator<(const Token&) const;

            bool operator>=(const Token&) const;

            bool operator<=(const Token&) const;
            
         private:

            TokenType type;
            std::string key;
            int precedance = 0;
            Associativity asc = None;
    };
}

#endif /*token.hpp*/
