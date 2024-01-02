#include <pwgenerator.hpp>
#include <random>
#include <chrono>

Generator::Generator()
{
    this->charset = Generator::ALPHABETIC;
    this->rng = std::mt19937(std::chrono::steady_clock::now().time_since_epoch().count());
}

Generator::~Generator()
{
    // nothing to do
}

std::string Generator::generatePassword(int length)
{
    std::string charset;
    if (this->charset == Generator::ALPHANUMERIC)
    {
        charset = Generator::charset_numeric + Generator::charset_alphabetic;
    }
    else if (this->charset == Generator::ALPHANUMERIC_WITH_SYMBOLS)
    {
        charset = Generator::charset_alphabetic + Generator::charset_numeric +
                  Generator::charset_symbols;
    }
    else
    {
        charset = Generator::charset_alphabetic;
    }
    std::string password = "";
    for (int i = 0; i < length; i++)
    {
        // get a random number
        // isn't there a os.random() function for this purpose with quantum
        // mechanics?
        int random = this->rng() % charset.length();
        // index the string at the random numbers idx & add the char to our
        // password
        password += charset[random];
    }
    return password;
}

void Generator::setCharset(int charset)
{
    this->charset = charset;
}
