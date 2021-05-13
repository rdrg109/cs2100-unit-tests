#include "catch.hpp"
#include "solution.h"

TEST_CASE("1 element") {
  DoubleList* l = new DoubleList;

  push_back(l, 1);

  REQUIRE(is_palindrome(l));
}

TEST_CASE("2 elements") {
  DoubleList* l = new DoubleList;
  push_back(l, 1);
  
  SECTION("Get true") {
    push_back(l, 1);
    REQUIRE(is_palindrome(l));
  }
  
  SECTION("Get false") {
    push_back(l, 2);
    REQUIRE_FALSE(is_palindrome(l));
  }
}

TEST_CASE("3 elements") {
  DoubleList* l = new DoubleList;
  push_back(l, 1);
  push_back(l, 2);

  SECTION("Get true") {
    push_back(l, 1);
    REQUIRE(is_palindrome(l));
  }

  SECTION("Get false") {
    push_back(l, 2);
    REQUIRE_FALSE(is_palindrome(l));
  }
}

TEST_CASE("200 elements") {
  DoubleList* l = new DoubleList;
  for(int i=0; i<100; ++i)
    push_back(l, i);
  
  SECTION("Get true") {
    for(int i=99; i>=0; --i)
      push_back(l, i);
    REQUIRE(is_palindrome(l));
  }
  SECTION("Get false") {
    for(int i=0; i<100; ++i)
      push_back(l, i);
    REQUIRE_FALSE(is_palindrome(l));
  }
}
