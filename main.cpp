#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol2265;

/*
Input:
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
*/

tuple<Node *, int>
testFixture1()
{
  auto root = new Node(1);
  root->left = new Node(2);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  root->right = new Node(3);
  root->right->left = new Node(6);

  return make_tuple(root, 6);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  auto path = sol.countNodes(get<0>(f));
  cout << "Expect to see :" << get<1>(f) << endl;
  cout << path << endl;
}

main()
{
  test1();
  return 0;
}