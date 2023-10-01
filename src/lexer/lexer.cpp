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

char Lexer::peekChar() {
    if (this->readPosition >= this->input.size()) {
        return 0;
    } else {
        return this->input[this->readPosition];
    }
}

Token Lexer::nextToken() {
    Token tok;

    this->skipWhitespaces();

    switch (this->byte) {
    case '=':
        if (this->peekChar() == '=') {
            const std::string val(1, this->byte);
            this->readChar();
            tok = Token{TOKEN::EQ, val + this->byte};
        } else {
            tok = Token{TOKEN::ASSIGN, std::string(1, this->byte)};
        }
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
    case '-':
        tok = Token{TOKEN::MINUS, std::string(1, this->byte)};
        break;
    case '!':
        if (this->peekChar() == '=') {
            const std::string val(1, this->byte);
            this->readChar();
            tok = Token{TOKEN::NOT_EQ, val + this->byte};
        } else {
            tok = Token{TOKEN::BANG, std::string(1, this->byte)};
        }
        break;
    case '*':
        tok = Token{TOKEN::ASTERISK, std::string(1, this->byte)};
        break;
    case '/':
        tok = Token{TOKEN::SLASH, std::string(1, this->byte)};
        break;
    case '<':
        tok = Token{TOKEN::LT, std::string(1, this->byte)};
        break;
    case '>':
        tok = Token{TOKEN::GT, std::string(1, this->byte)};
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
    default: // this means it is a letter or an illegal token
        if (this->isLetter(this->byte)) {
            tok.literal = this->readIdentifier();
            tok.type = lookupIdent(tok.literal);
            return tok;
        } else if (std::isdigit(this->byte)) {
            tok.literal = this->readNumber();
            tok.type = TOKEN::INT;
            return tok;
        } else {
            tok = Token{TOKEN::ILLEGAL, std::string(1, this->byte)};
        }
        break;
    }

    this->readChar();

    return tok;
}

std::string Lexer::readIdentifier() {
    const size_t position = this->position;

    while (this->isLetter(this->byte)) {
        this->readChar();
    }

    return this->input.substr(position, this->position - position);
}

std::string Lexer::readNumber() {
    const size_t position = this->position;

    while (std::isdigit(this->byte)) {
        this->readChar();
    }

    return this->input.substr(position, this->position - position);
}

bool Lexer::isLetter(char &ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_';
}

void Lexer::skipWhitespaces() {
    while (this->byte == ' ' || this->byte == '\n' || this->byte == '\t' ||
           this->byte == '\r') {
        this->readChar();
    }
}
