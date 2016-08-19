#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include<iostream>
#include<vector>
#include<regex>
#include "unkown_char_sequence.hpp"
#include "token.hpp"

namespace engicalc
{
    using TokenType = Token::TokenType; 
    using Tokens = std::vector<Token>;

    class Tokenizer
    {
        public:

            Tokens toTokens(std::string);
        
        private:

            Token parse(std::string&);
            
            const int nTokens = 7;
            static std::regex tokenTypes[];
    };
}

#endif /*tokenzier*/
