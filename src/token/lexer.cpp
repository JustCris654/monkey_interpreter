#include "lexer.hpp"
#include "token.hpp"

Lexer::Lexer(std::string input) {
    this->input = input;

    this->readChar();
}

Lexer::~Lexer() {}

void Lexer::readChar() {
    if (this->readPosition >= this->input.size()) {
        this->byte = 0;
    } else {
        this->byte = this->input[this->readPosition];
    }

    this->position = readPosition++;
}

Token Lexer::nextToken() {
    Token tok;

    switch (this->byte) {
    case '=':
        tok = Token{TOKEN::ASSIGN, std::string(1, this->byte)};
        break;
    case ';':
        tok = Token{TOKEN::SEMICOLON, std::string(1, this->byte)};
        break;
    case ',':
        tok = Token{TOKEN::COMMA, std::string(1, this->byte)};
        break;
    case '+':
        tok = Token{TOKEN::PLUS, std::string(1, this->byte)};
        break;
    case '(':
        tok = Token{TOKEN::LPAREN, std::string(1, this->byte)};
        break;
    case ')':
        tok = Token{TOKEN::RPAREN, std::string(1, this->byte)};
        break;
    case '{':
        tok = Token{TOKEN::LBRACE, std::string(1, this->byte)};
        break;
    case '}':
        tok = Token{TOKEN::RBRACE, std::string(1, this->byte)};
        break;
    case 0:
        tok = Token{TOKEN::END_OF_FILE, ""};
        break;
    }

    this->readChar();

    return tok;
}
