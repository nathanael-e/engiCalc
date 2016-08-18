#include<iostream>
#include "tokenizer.hpp"

using namespace engicalc;

int main()
{

    Tokenizer tokenFactory;

    auto tokens = tokenFactory.toTokens("2+2");

    return 0;
}
