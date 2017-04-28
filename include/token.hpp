#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

namespace engicalc
{
    class Token
    {
        public:

            enum Associativity{None, Left, Right};

            enum TokenType
            {
                COMPLEX,
                NUMBER,
                FUNCTION,
                SEPARATOR,
                OPERATOR,
                LEFTBRACKET,
                RIGHTBRACKET
            };
 
            Token(TokenType, std::string);
        
            TokenType getType() const;

            int getPrecedance() const;

            bool hasLeftAssociativity() const;

            std::string getKey() const;

            bool operator==(const TokenType&) const;

            bool operator!=(const TokenType&) const;

            bool operator==(const Token&) const;

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
