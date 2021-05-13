#include <vector>
#include "catch.hpp"
#include "solution.h"

TEST_CASE("Minimal working examples") {

  SECTION("Inserting one element in each list") {
    Node *l1 = nullptr, *l2 = nullptr;
    
    push_back(l1, 1);
    push_back(l2, 2);

    Node* l3 = SortedMergeSeq(l1, l2);

    REQUIRE(l3 -> data == 1);
    REQUIRE(l3 -> next -> data == 2);
    REQUIRE(l3 -> next -> next == nullptr);
  }
  
  SECTION("Inserting two elements in each list") {
    Node *l1 = nullptr, *l2 = nullptr;
    
    push_back(l1, 1);
    push_back(l1, 2);
    push_back(l2, 10);
    push_back(l2, 20);

    Node* l3 = SortedMergeSeq(l1, l2);

    REQUIRE(l3 -> data == 1);
    REQUIRE(l3 -> next -> data == 2);
    REQUIRE(l3 -> next -> next -> data == 10);
    REQUIRE(l3 -> next -> next -> next -> data == 20);
    REQUIRE(l3 -> next -> next -> next -> next == nullptr);
  }

}

bool SortedMergeEqualResult(vector<int> items1,
			    vector<int> items2,
			    vector<int> expected_result) {
  Node *list1 = nullptr, *list2 = nullptr, *result = nullptr;

  std::for_each(begin(items1), end(items1), [&](const int& item) {
    push_back(list1, item);
  });
  
  std::for_each(begin(items2), end(items2), [&](const int& item) {
    push_back(list2, item);
  });

  result = SortedMergeSeq(list1, list2);
  bool equal = true;

  std::for_each(begin(expected_result), end(expected_result), [&](const int& expected_item) {
    if(expected_item != result -> data)
      equal = false;
    result = result -> next;
  });
  
  return equal;
}

TEST_CASE("Multiple elements") {
  vector<int> items1 = {1, 2, 3, 4};
  vector<int> items2 = {4, 5, 6, 7};
  vector<int> result = {1, 2, 3, 4, 4, 5, 6, 7};
  REQUIRE( SortedMergeEqualResult(items1, items2, result) );
}
