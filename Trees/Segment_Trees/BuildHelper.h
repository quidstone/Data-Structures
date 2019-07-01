#include <iostream>
using namespace std;

void updateTree(int *tree, int start, int end, int treeNode, int diff) {

    if (start > treeNode || end < treeNode) return;

    if ((start == end) && (start == treeNode)) {
        tree[treeNode] += diff;
        return;
    }

    if (start == end)
        return;

    if (start <= treeNode && end >= treeNode) {
        tree[treeNode] += diff;
        int mid = (start + end)/  2;
        updateTree(tree, start, mid, 2 * treeNode, diff);
        updateTree(tree, mid+1, end, (2*treeNode)+1, diff);
    }
}

int minSubArray(int *tree, int start, int end, int qlow, int qhigh, int treeNode)
{
    // Total Overlap
    if (qlow <= start && qhigh >= end)
    {
        return tree[treeNode];
    }

    // No Overlap
    if (qlow > end || qhigh < start)
        return INT_MAX;

    int mid = (start + end) / 2;

    return min(minSubArray(tree, start, mid, qlow, qhigh, (2 * treeNode)), minSubArray(tree, mid + 1, end, qlow, qhigh, (2 * treeNode) + 1));
}

int sumSubArray(int *tree, int start, int end, int low, int high, int treeNode)
{
    if (low <= start && high >= end)
        return tree[treeNode];

    if (low > end || high < start)
        return 0;

    int mid = (start + end) / 2;
    return sumSubArray(tree, start, mid, low, high, (2 * treeNode)) + sumSubArray(tree, mid + 1, end, low, high, (2 * treeNode) + 1);
}