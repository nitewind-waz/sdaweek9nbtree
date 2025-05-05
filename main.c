#include "nbtree.h"

int main(){
    Isi_Tree X;

    Create_tree(X, 10);
    int depth = Depth(X);
    printf("Depth of the tree: %d\n", depth);
    

    return 0;
}