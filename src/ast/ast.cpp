#include "ast.hpp"

Statement::Statement() : Node() {}
Statement::~Statement() {}

Expression::Expression() : Node() {}
Expression::~Expression() {}

std::string Program::tokenLiteral() {
    if (this->statements.size() > 0) {
        return this->statements[0].tokenLiteral();
    } else {
        return std::string("");
    }
}

void LetStatement::statementNode() {}

std::string LetStatement::tokenLiteral() {
    return this->token.literal;
}

void Identifier::expressionNode() {}

std::string Identifier::tokenLiteral() {
    return this->token.literal;
}
