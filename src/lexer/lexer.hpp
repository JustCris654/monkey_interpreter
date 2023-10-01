#include <string>

#include "token.hpp"

class Lexer {

  public:
    Lexer(std::string);
    ~Lexer();

    Token nextToken();

  private:
    void        readChar();
    char        peekChar();
    std::string readIdentifier();
    std::string readNumber();
    bool        isLetter(char &);
    void        skipWhitespaces();

  private:
    std::string input;
    size_t position = 0; // current position in input, points to current char
    size_t readPosition = 0; // current reading position, after current char
    char   byte = 0;         // current char
};
