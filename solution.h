
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol2265
{

  class Solution
  {
  private:
    int getLevel(Node *root);

  public:
    int countNodes(Node *root);
  };
}
#endif