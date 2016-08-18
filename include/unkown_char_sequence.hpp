#ifndef PARSE_EXCEPTION_HPP
#define PARSE_EXCEPTION_HPP

#include<exception>
#include<string>

namespace engicalc
{
    struct unkown_char_sequence:
        public std::exception
    {

        unkown_char_sequence(std::string _err_msg)
            :err_msg(_err_msg)
        {}

        virtual const char* what() const throw()
        {
            return this->err_msg.c_str();  
        }

        std::string err_msg;
    };
}

#endif /*unkown_char_sequence.hpp*/
