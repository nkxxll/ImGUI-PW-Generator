#pragma once
#ifndef PWGENERATOR_H

#    define PWGENERATOR_H
#    include <string>
#    include <random>

class Generator
{
public:
    Generator();
    ~Generator();

    std::string generatePassword(int length);
    void        setCharset(int charset);
    static const int   ALPHABETIC = 1;
    static const int   NUMERIC    = 2;
    static const int   SYMBOLIC   = 4;

    static const int ALPHANUMERIC = Generator::ALPHABETIC | Generator::SYMBOLIC;
    static const int ALPHANUMERIC_WITH_SYMBOLS =
        Generator::ALPHABETIC | Generator::SYMBOLIC | Generator::NUMERIC;

private:
    int               charset;
    std::mt19937      rng;
    const std::string charset_alphabetic =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string charset_numeric = "0123456789";
    const std::string charset_symbols = "!@\\|_=[](){}%$#^&+*";
};

#endif // !PWGENERATOR_H
