#include "tokenizer.hpp"

using namespace engicalc;

auto Tokenizer::toTokens(std::string expression)
    -> Tokens
{
    Tokens T;

    while(!expression.empty())
    {
        Token t = parse(expression);
        T.push_back(t);
    }

    return T;
}

auto Tokenizer::parse(std::string& expression)
    -> Token
{
    std::smatch match;

    for(int i = 0; i < nTokens; ++i)
    {
        std::regex rgx = tokenTypes[i];
   
        if(std::regex_search(expression, match, rgx))
        {
            std::string key = match[0];
            expression = std::regex_replace(expression, rgx, "");
            return Token(static_cast<TokenType>(i), key);
        }
    }

    throw unkown_char_sequence(expression);
}

std::regex Tokenizer::tokenTypes[] = 
{
    std::regex("^\\d*\\.?\\d+[ij]"),
    std::regex("^\\d*\\.?\\d+"),
    std::regex("^[a-z]+"),
    std::regex("^\\,"),
    std::regex("^[\\+\\-\\/\\^\\*]"),
    std::regex("^\\("),
    std::regex("^\\)")
};
