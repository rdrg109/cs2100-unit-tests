#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
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

// Builds a string with a equal formatting to that from the methods
// displayInOrder, displayPreOrder, displayPostOrder.

std::string build_string_display(std::vector<int>items) {
  std::string result = "";
  std::for_each(begin(items), end(items), [&](const int& item) {
    result = result + std::to_string(item) + ", ";
  });
  return result;
}

TEST_CASE("Traversing the tree using the inorder variant", "[BSTree][displayInOrder]") {
  using std::vector;
  
  BSTree<int> items;
  auto insert = [&] (const int& item) { items.insert(item); };
  ostringstream oss;
  streambuf* p_cout_streambuf = cout.rdbuf();

  SECTION("explicitly inserting") {

    SECTION("1 element") {
      vector<int> to_insert = {10};
      vector<int> inorder = {10};

      for_each(begin(to_insert), end(to_insert), insert);
      
      cout.rdbuf(oss.rdbuf());
      items.displayInOrder();
      cout.rdbuf(p_cout_streambuf);

      REQUIRE(oss.str() == build_string_display(inorder));
    }

    SECTION("2 elements") {
      vector<int> to_insert = {10, 6};
      vector<int> inorder = {6, 10};

      for_each(begin(to_insert), end(to_insert), insert);
      
      cout.rdbuf(oss.rdbuf());
      items.displayInOrder();
      cout.rdbuf(p_cout_streambuf);

      REQUIRE(oss.str() == build_string_display(inorder));
    }

    SECTION("3 elements") {
      vector<int> to_insert = {3, 3, 3};
      vector<int> inorder = {3, 3, 3};

      for_each(begin(to_insert), end(to_insert), insert);
      
      cout.rdbuf(oss.rdbuf());
      items.displayInOrder();
      cout.rdbuf(p_cout_streambuf);

      REQUIRE(oss.str() == build_string_display(inorder));
    }

    SECTION("4 elements") {
      vector<int> to_insert = {6, 5, 4, 3};
      vector<int> inorder = {3, 4, 5, 6};

      for_each(begin(to_insert), end(to_insert), insert);
      
      cout.rdbuf(oss.rdbuf());
      items.displayInOrder();
      cout.rdbuf(p_cout_streambuf);

      REQUIRE(oss.str() == build_string_display(inorder));
    }

    SECTION("6 elements") {
      vector<int> to_insert = {10, 6, 4, 3, 5, 8};
      vector<int> inorder = {3, 4, 5, 6, 8, 10};

      for_each(begin(to_insert), end(to_insert), insert);
      
      cout.rdbuf(oss.rdbuf());
      items.displayInOrder();
      cout.rdbuf(p_cout_streambuf);

      REQUIRE(oss.str() == build_string_display(inorder));
    }

    SECTION("9 elements") {
      vector<int> to_insert = {8, 3, 1, 6, 4, 7, 10, 14, 13};
      vector<int> inorder = {1, 3, 4, 6, 7, 8, 10, 13, 14};
      
      for_each(begin(to_insert), end(to_insert), insert);
      
      cout.rdbuf(oss.rdbuf());
      items.displayInOrder();
      cout.rdbuf(p_cout_streambuf);

      REQUIRE(oss.str() == build_string_display(inorder));
    }
    
  }
  
}
