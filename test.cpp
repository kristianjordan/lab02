#include "c-echo.h"
#include "c-count.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo-count";
    EXPECT_EQ("", echo(1, test_val));
}

TEST(CountTest, HelloWorld) {
    std::string test_str = "hello world";
    EXPECT_EQ(2, count(test_str));
}

TEST(CountTest, EmptyString) {
    std::string test_str = "";
    EXPECT_EQ(0, count(test_str));
}

TEST(CountTest, ManySpaces) {
    std::string test_str = "   this   string has     weird   spacing";
    EXPECT_EQ(5, count(test_str));
}

TEST(EchoTest, Capitalization) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "A"; test_val[2] = "Capital";
    EXPECT_EQ("A Capital", echo(3, test_val));
}

TEST(EchoTest, Numbers) {
    char* test_val[4]; test_val[0] = "./c-echo"; test_val[1] = "1"; test_val[2] = "1.2"; test_val[3] = "1.2, 2.3, 3.4, 4.5";
    EXPECT_EQ("1 1.2 1.2, 2.3, 3.4, 4.5", echo(4,test_val));
}

TEST(EchoTest, MultiSentences) {
    char* test_val[6]; test_val[0] = "./c-echo"; test_val[1] = "One becomes two."; test_val[2] = "Two becomes four."; test_val[3] = "Four becomes eight."; test_val[4] = "Eight becomes sixteen."; test_val[5] = "-And so on.";
    EXPECT_EQ("One becomes two. Two becomes four. Four becomes eight. Eight becomes sixteen. -And so on.", echo(6, test_val));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

