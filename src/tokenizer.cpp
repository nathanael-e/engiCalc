#include "tokenizer.hpp"

using namespace engicalc;

Tokenizer::Token::Token(TokenType _type, std::string _key):
    type(_type), key(_key)
{
     if(type == Operator)
    {
        if(key[0] == '+' || key[0] == '-')
            precedance = 2;
        else if(key[0] == '*' || '/')
            precedance = 3;
        else
        {
            precedance = 4;
            leftAssociativity = false;
        }
    }
}

auto Tokenizer::Token::getType() const
    -> TokenType
{
    return type;
}

int Tokenizer::Token::getPrecedance() const
{
    return precedance;
}

bool Tokenizer::Token::hasLeftAssociativity() const
{
    return leftAssociativity;
}

std::string Tokenizer::Token::toString() const
{
    return key;
}

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
    std::regex("^[\\+\\-\\*\\/\\^]"),
    std::regex("^\\("),
    std::regex("^\\)")
};
