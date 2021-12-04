#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
                "3 1\n"
                "abb"
            ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();

    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    INFO(buffer.str());
    REQUIRE(buffer.str() ==
            "2 1"
    );
}

TEST_CASE("test 2", ""){
    std::stringstream input(
            "5 2\n"
            "ababa\n"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "4 1"
    );
}

TEST_CASE("1 char", ""){
    std::stringstream input(
            "1 1\n"
            "a\n"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "1 1"
    );
}

TEST_CASE("4 same chars", ""){
    std::stringstream input(
            "4 2\n"
            "aaaa\n"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "2 1"
    );
}
