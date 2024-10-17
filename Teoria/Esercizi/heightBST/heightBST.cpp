#include <iostream>
using namespace std;
int heightBST(Node *node);

int heightBST(Node *node){
    if (node == nullptr)
        return 0;
    else {
        int leftHeight = calculationHeight(node->getNodeLeft());
        int rightHeight = calculationHeight(node->getNodeRight());
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}