#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include<iostream>
#include<vector>
#include<regex>

#include "unkown_char_sequence.hpp"

namespace engicalc
{
    class Tokenizer
    {
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

        class Token
        {
            public:

                Token(TokenType, std::string);

                TokenType getType() const;

                int getPrecedance() const;

                bool hasLeftAssociativity() const;

                std::string toString() const;
            
            private:

                TokenType type;
                std::string key;
                int precedance = -1;
                bool leftAssociativity = true;
        };

        using Tokens = std::vector<Token>;

        public:

            Tokens toTokens(std::string);
        
        private:

            Token parse(std::string&);
            
            const int nTokens = 7;
            static std::regex tokenTypes[];
    };
}

#endif /*tokenzier*/
