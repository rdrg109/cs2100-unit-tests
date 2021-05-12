#include "catch.hpp"
#include "bst.h"

TEST_CASE("Getting the minimum value in a BST", "[BSTree][minValue]") {
  BSTree<int> items;

  SECTION("with no elements must throw an error") {
    REQUIRE_THROWS([&items](){
      items.minValue();
    }());
  }

  SECTION("with one element must return that element") {
    int data = 10;
    items.insert(data);
    REQUIRE(items.minValue() == data);    
  }

  SECTION("with two elements must return the minimum") {
    items.insert(10);
    items.insert(20);
    REQUIRE(items.minValue() == 10);
  }

  SECTION("with multiple elements must return the minimum") {
    int start=0;
    int end=100;
    
    for(int i=start; i<end; i++)
      items.insert(i);
    
    REQUIRE(items.minValue() == start);
  }
  
}

TEST_CASE("Getting the maximum value in a BST", "[BSTree][maxValue]") {
  BSTree<int> items;

  SECTION("with no elements must throw an error") {
    REQUIRE_THROWS([&items](){
      items.maxValue();
    }());
  }

  SECTION("with one element must return that element") {
    int data = 10;
    items.insert(data);
    REQUIRE(items.maxValue() == data);    
  }

  SECTION("with two elements must return the minimum") {
    items.insert(10);
    items.insert(20);
    REQUIRE(items.maxValue() == 20);
  }

  SECTION("with multiple elements must return the minimum") {
    int start=0;
    int end=100;
    
    for(int i=start; i<end; i++)
      items.insert(i);
    
    REQUIRE(items.maxValue() == end - 1);
  }
  
}
