#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol2265;
using namespace std;

/*takeaways
  - a perfect binary tree has 2^level - 1 nodes
    - if the left child is a perfect binary tree
      and its level is "level" then the total
      number of nodes of the entire tree can
      be written as
      2^level - 1 +  1 (root) + number of nodes on the right child
      = 2^level + number of nodes on the right child

*/

int Solution::getLevel(Node *root)
{
  if (root == nullptr)
    return 0;
  /* find the leftmost child and you get the level
     of the complete binary tree
     - as all nodes in the last level are
       as far left as possible
  */
  return 1 + getLevel(root->left);
}

int Solution::countNodes(Node *root)
{
  if (root == nullptr)
    return 0;

  auto ll = getLevel(root->left);
  auto rl = getLevel(root->right);

  if (ll == rl)
    /*
      - left child must be a perfect binary tree
        - or the level of the right child should
          be smaller as we will not have enough
          node to extend the right child to the
          same level as the left child
      - left child has 2^ll - 1 nodes + plus 1
        for root to become 2^ll
    */
    return (1 << ll) + countNodes(root->right);
  else
    /* right child is short of one level, and it must be
       a perfect binary tree
    */
    return (1 << rl) + countNodes(root->left);
}