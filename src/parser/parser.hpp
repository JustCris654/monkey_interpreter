#ifndef PARSER_H_
#define PARSER_H_

#include "ast.hpp"
#include "lexer.hpp"
#include "token.hpp"

class Parser {
  public:
    Parser(Lexer *);
    ~Parser();

    void     nextToken();
    Program *parseProgram();

  private:
    Lexer *lexer = nullptr;
    Token  curToken;
    Token  peekToken;
};

#endif
