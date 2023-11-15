#include <gtest/gtest.h>

#include <string>

#include "ast.hpp"
#include "lexer.hpp"
#include "parser.hpp"

TEST(ParserTest, BasicAssertions) {
    const char *input = "let x = 5;\n"
                        "let y = 10;\n"
                        "let foobar = 3478\n";

    Lexer  lexer{input};
    Parser parser{&lexer};

    Program *program = parser.parseProgram();

    ASSERT_NE(program, nullptr);
    EXPECT_EQ(program->getStatements()->size(), 3);

    std::vector<std::string> expectedIdentifiers;
    const std::string        identifiers[] = {
        {"x"},
        {"y"},
        {"foobar"},
    };

    for (size_t i = 0; i < sizeof(identifiers) / sizeof(identifiers[0]); ++i) {
        expectedIdentifiers.push_back(identifiers[i]);
    }

    for (size_t i = 0; i < expectedIdentifiers.size(); i++) {
        Statement   stmt = program->getStatements()->at(i);
        std::string name = expectedIdentifiers.at(i);

        EXPECT_EQ(stmt.tokenLiteral(), "let");

        // auto letStmt = stmt.letStatemenet();
        // EXPECT_NE(letStmt, nullptr);
        // EXPECT_STREQ(letStmt.name.value, name);
        //
        // EXPECT_STREQ(letStmt.tokenLiteral(), name);
    }
}
