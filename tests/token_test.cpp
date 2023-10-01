#include <gtest/gtest.h>

#include <vector>

#include "lexer.hpp"
#include "token.hpp"

typedef struct {
    std::string expectedType;
    std::string expectedLiteral;
} ExpectedToken;

TEST(TokenTest, BasicAssertions) {
    const char *input = "=+(){},;";

    std::vector<ExpectedToken> expectedTokens;
    const ExpectedToken        tkns[] = {
        {TOKEN::ASSIGN, "="}, {TOKEN::PLUS, "+"},      {TOKEN::LPAREN, "("},
        {TOKEN::RPAREN, ")"}, {TOKEN::LBRACE, "{"},    {TOKEN::RBRACE, "}"},
        {TOKEN::COMMA, ","},  {TOKEN::SEMICOLON, ";"}, {TOKEN::END_OF_FILE, ""},
    };
    for (size_t i = 0; i < sizeof(tkns) / sizeof(tkns[0]); ++i) {
        expectedTokens.push_back(tkns[i]);
    }

    Lexer lexer = Lexer(input);

    for (auto it = expectedTokens.begin(); it != expectedTokens.end(); ++it) {
        auto token = lexer.nextToken();

        EXPECT_STREQ(token.type, it->expectedType);
        EXPECT_STREQ(token.literal, it->expectedLiteral);
    }
}
