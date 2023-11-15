#include "ast.hpp"

Node::Node() {}

Node::~Node() {}

std::string Node::tokenLiteral() {
    return "";
}

Statement::Statement() : Node() {}
Statement::~Statement() {}

std::string Statement::tokenLiteral() {
    return "";
}

Expression::Expression() : Node() {}
Expression::~Expression() {}

std::string Expression::tokenLiteral() {
    return "";
}

std::string Program::tokenLiteral() {
    if (this->statements.size() > 0) {
        return this->statements[0].tokenLiteral();
    } else {
        return std::string("");
    }
}

const std::vector<Statement> *Program::getStatements() {
    return &this->statements;
}

void LetStatement::statementNode() {}

std::string LetStatement::tokenLiteral() {
    return this->token.literal;
}

void Identifier::expressionNode() {}

std::string Identifier::tokenLiteral() {
    return this->token.literal;
}
