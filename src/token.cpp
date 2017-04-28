#include "token.hpp"

using namespace engicalc;

Token::Token(TokenType _type, std::string _key):
    type(_type), key(_key)
{
   if(type == OPERATOR)
   {
        if(key[0] == '+' || key[0] == '-')
        {
            precedance = 2;
            asc = Left;
        }
        else if(key[0] == '*' || key[0] == '/')
        {
            precedance = 3;
            asc = Left;
        }
        else
        {
            precedance = 4;
            asc = Right;
        }
   } 
}

auto Token::getType() const
    -> TokenType
{
   return type;
}

int Token::getPrecedance() const
{
    return precedance;
}

bool Token::hasLeftAssociativity() const
{
    return asc == Left;
}

std::string Token::getKey() const
{
    return key;
}

bool Token::operator==(const TokenType& _type) const
{
    return type == _type;
}

bool Token::operator!=(const TokenType& _type) const
{
    return type != _type;
}

bool Token::operator==(const Token& other) const
{
    return key == other.getKey();
}

bool Token::operator!=(const Token& other) const
{
    return key != other.getKey();
}

bool Token::operator>(const Token& other) const
{
    return precedance > other.getPrecedance();
}

bool Token::operator<(const Token& other) const
{
    return precedance < other.getPrecedance();
}

bool Token::operator>=(const Token& other) const
{
    return precedance >= other.getPrecedance();
}

bool Token::operator<=(const Token& other) const
{
    return precedance <= other.getPrecedance();
}
