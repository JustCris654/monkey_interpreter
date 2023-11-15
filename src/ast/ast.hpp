#ifndef AST_H_
#define AST_H_

#include <string>
#include <vector>

#include "token.hpp"

class Node {
  public:
    Node();
    ~Node();

    virtual std::string tokenLiteral();
};

class Statement : public Node {
  public:
    Statement();
    ~Statement();

    Node statementNode();

    std::string tokenLiteral() override;
};

class Expression : public Node {
  public:
    Expression();
    ~Expression();

    Node expressionNode();

    std::string tokenLiteral() override;
};

class Program {
  public:
    std::string tokenLiteral();

    const std::vector<Statement> *getStatements();

  private:
    std::vector<Statement> statements;
};

class Identifier : public Expression {
  public:
    Identifier();
    ~Identifier();

    void        expressionNode();
    std::string tokenLiteral() override;

  private:
    Token       token; // the TOKEN::IDENT token
    std::string value;
};

class LetStatement : public Statement {
  public:
    LetStatement();
    ~LetStatement();

    void        statementNode();
    std::string tokenLiteral() override;

  private:
    Token       token;
    Identifier *name;
    Expression  value;
};

#endif
