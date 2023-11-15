#include "parser.hpp"

Parser::Parser(Lexer *lexer) {
    this->lexer = lexer;

    this->nextToken();
    this->nextToken();
}

Parser::~Parser() {}

void Parser::nextToken() {
    this->curToken = this->peekToken;
    this->peekToken = this->lexer->nextToken();
}

Program *Parser::parseProgram() {
    return nullptr;
}
