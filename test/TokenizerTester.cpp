#include "gtest/gtest.h"
#include "tokenizer.hpp"
#include "token.hpp"

using namespace engicalc;

using Associativity = Token::Associativity;
using TokenType = Token::TokenType;

class TokenizerTester:
    public ::testing::Test
{

};

TEST_F(TokenizerTester, OperatorTest)
{
    Tokenizer tokenFactory;

    {
        auto tokens = tokenFactory.toTokens("+");
        ASSERT_EQ(1, tokens.size());
        
        auto t = tokens[0];

        ASSERT_EQ(TokenType::Operator, t.getType());
        ASSERT_EQ(2, t.getPrecedance());
        ASSERT_EQ(Associativity::Left, t.hasLeftAssociativity());
        ASSERT_EQ("+", t.getKey());
    }

    {
        auto tokens = tokenFactory.toTokens("-");
        ASSERT_EQ(1, tokens.size());

        auto t = tokens[0];

        ASSERT_EQ(TokenType::Operator, t.getType());
        ASSERT_EQ(2, t.getPrecedance());
        ASSERT_EQ(true, t.hasLeftAssociativity());
        ASSERT_EQ("-", t.getKey());
    }

    {
        auto tokens = tokenFactory.toTokens("*");
        ASSERT_EQ(1, tokens.size());

        auto t = tokens[0];

        ASSERT_EQ(TokenType::Operator, t.getType());
        ASSERT_EQ(3, t.getPrecedance());
        ASSERT_EQ(true, t.hasLeftAssociativity());
        ASSERT_EQ("*", t.getKey());

    }

    {
        auto tokens = tokenFactory.toTokens("/");
        ASSERT_EQ(1, tokens.size());

        auto t = tokens[0];

        ASSERT_EQ(TokenType::Operator, t.getType());
        ASSERT_EQ(3, t.getPrecedance());
        ASSERT_EQ(true, t.hasLeftAssociativity());
        ASSERT_EQ("/", t.getKey());
    }

    
    {
        auto tokens = tokenFactory.toTokens("^");
        ASSERT_EQ(1, tokens.size());

        auto t = tokens[0];

        ASSERT_EQ(TokenType::Operator, t.getType());
        ASSERT_EQ(4, t.getPrecedance());
        ASSERT_EQ(false, t.hasLeftAssociativity());
        ASSERT_EQ("^", t.getKey());
    }
}

TEST_F(TokenizerTester, RandomTests)
{

    Tokenizer tokenFactory;

    {
        auto tokens = tokenFactory.toTokens("sin(45)");
        ASSERT_EQ(4, tokens.size());

        auto t = tokens[0];
        
        ASSERT_EQ(TokenType::Function, t.getType());
        ASSERT_EQ("sin", t.getKey());

        t = tokens[1];

        ASSERT_EQ(TokenType::LeftBracket, t.getType());
        ASSERT_EQ("(", t.getKey());

        t = tokens[2];

        ASSERT_EQ(TokenType::Number, t.getType());
        ASSERT_EQ("45", t.getKey());

        t = tokens[3];

        ASSERT_EQ(TokenType::RightBracket, t.getType());
        ASSERT_EQ(")", t.getKey());
    }
}
