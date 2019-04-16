#ifndef MERGHEAP
#define MERGHEAP
#include <cstdlib>

typedef struct MergHeapNode{
    int len;
    int value;
    MergHeapNode *lchild;
    MergHeapNode *rchild;
} MergHeapNode;

class MergeableHeap
{
public: 
    static MergeableHeap& MakeHeap()
    {
        return *(new MergeableHeap());
    };
    static MergHeapNode* Union(MergHeapNode *h1, MergHeapNode *h2)
    {
        // 终止条件
        if(h1==nullptr)
            return h2;
        if(h2==nullptr)
            return h1;
        // 将小的根调成h1
        if(h1->value > h2->value)
        {
            MergHeapNode *tem = h1;
            h1 = h2;
            h2 = tem;
        }
        // 递归实现归并
        h1->rchild = Union(h1->rchild, h2);
        // h1->rchild 必定不为nullptr
        // 保证左距离大于等于右距离,并更新len
        if(h1->lchild==nullptr)
        {
            h1->lchild = h1->rchild;
            h1->rchild = nullptr;
            h1->len = 0;
            return h1;
        }else if(h1->lchild->len < h1->rchild->len)
        {
            MergHeapNode *tem = h1->lchild;
            h1->lchild = h1->rchild;
            h1->rchild = tem;
        }
        h1->len = h1->rchild->len + 1;
        return h1;
    };
    static MergeableHeap& Union(MergeableHeap &h1, MergeableHeap &h2)
    {
        MergHeapNode *n = Union(h1.root, h2.root);
        h1.root = nullptr;
        h2.root = nullptr;
        return *(new MergeableHeap(n));
    }

    bool insert(int value)
    {
        MergHeapNode *n = (MergHeapNode *)malloc(sizeof(MergHeapNode));
        n->len = 0;
        n->value = value;
        n->lchild = nullptr;
        n->rchild = nullptr;
        root = Union(root, n);
        return true;
    };
    int getMinimum()
    {
        if(root != nullptr)
            return root->value;
        return -1;
    };
    int popMinimum()
    {
        if(root == nullptr)
            return -1;
        MergHeapNode *newroot = nullptr;
        int temvalue = root->value;
        if(root->lchild!=nullptr || root->rchild!=nullptr)
        {
            newroot = Union(root->lchild, root->rchild);
        }
        delete root;
        root = newroot;
        return temvalue;
    };

private:
    MergHeapNode* root;
    MergeableHeap():root(nullptr){};
    MergeableHeap(MergHeapNode *n):root(n){};
};

#endif