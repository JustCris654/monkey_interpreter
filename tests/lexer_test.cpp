#include <gtest/gtest.h>

#include <vector>

#include "lexer.hpp"
#include "token.hpp"

typedef struct {
    std::string expectedType;
    std::string expectedLiteral;
} ExpectedToken;

TEST(TokenTest, BasicAssertions) {
    const char *input = "let five = 5;\n"
                        "let ten = 10;\n"
                        "let add = fn(x, y) {\n"
                        "x + y;\n"
                        "};\n"
                        "let result = add(five, ten);\n"
                        "!-/*5;\n"
                        "5 < 10 > 5;\n";

    std::vector<ExpectedToken> expectedTokens;
    const ExpectedToken        tkns[] = {
        {TOKEN::LET, "let"},     {TOKEN::IDENT, "five"},
        {TOKEN::ASSIGN, "="},    {TOKEN::INT, "5"},
        {TOKEN::SEMICOLON, ";"}, {TOKEN::LET, "let"},
        {TOKEN::IDENT, "ten"},   {TOKEN::ASSIGN, "="},
        {TOKEN::INT, "10"},      {TOKEN::SEMICOLON, ";"},
        {TOKEN::LET, "let"},     {TOKEN::IDENT, "add"},
        {TOKEN::ASSIGN, "="},    {TOKEN::FUNCTION, "fn"},
        {TOKEN::LPAREN, "("},    {TOKEN::IDENT, "x"},
        {TOKEN::COMMA, ","},     {TOKEN::IDENT, "y"},
        {TOKEN::RPAREN, ")"},    {TOKEN::LBRACE, "{"},
        {TOKEN::IDENT, "x"},     {TOKEN::PLUS, "+"},
        {TOKEN::IDENT, "y"},     {TOKEN::SEMICOLON, ";"},
        {TOKEN::RBRACE, "}"},    {TOKEN::SEMICOLON, ";"},
        {TOKEN::LET, "let"},     {TOKEN::IDENT, "result"},
        {TOKEN::ASSIGN, "="},    {TOKEN::IDENT, "add"},
        {TOKEN::LPAREN, "("},    {TOKEN::IDENT, "five"},
        {TOKEN::COMMA, ","},     {TOKEN::IDENT, "ten"},
        {TOKEN::RPAREN, ")"},    {TOKEN::SEMICOLON, ";"},
        {TOKEN::BANG, "!"},      {TOKEN::MINUS, "-"},
        {TOKEN::SLASH, "/"},     {TOKEN::ASTERISK, "*"},
        {TOKEN::INT, "5"},       {TOKEN::SEMICOLON, ";"},
        {TOKEN::INT, "5"},       {TOKEN::LT, "<"},
        {TOKEN::INT, "10"},      {TOKEN::GT, ">"},
        {TOKEN::INT, "5"},       {TOKEN::SEMICOLON, ";"},
    };
    for (size_t i = 0; i < sizeof(tkns) / sizeof(tkns[0]); ++i) {
        expectedTokens.push_back(tkns[i]);
    }

    Lexer lexer = Lexer(input);

    for (auto it = expectedTokens.begin(); it != expectedTokens.end(); ++it) {
        auto token = lexer.nextToken();

        EXPECT_STREQ(token.type.c_str(), it->expectedType.c_str());
        EXPECT_STREQ(token.literal.c_str(), it->expectedLiteral.c_str());
    }
}
