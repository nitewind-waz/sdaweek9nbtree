#include "nbtree.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    Isi_Tree X;
    int selector;

    Create_tree(X, 10);
    for (;;){
        system("cls");
        printf("Non Binary Tree\n");
        printf("1. PreOrder Traversal\n2. InOrder Traversal\n3. PostOrder Traversal\n4. Level Order Traversal\n5. Print Tree\n6. Search\n7. Level\n8. Depth\n9. Jumlah Node\n10. Jumlah Leaf\n11. Exit===>\n"); 
        scanf("%d", &selector);
        switch (selector) {
            case 1:
                PreOrder(X);
                printf("\nPress any key to continue...\n");
                getchar(); getchar();
                break;
            case 2:
                InOrder(X);
                printf("\nPress any key to continue...\n");
                getchar(); getchar();
                break;
            case 3:
                PostOrder(X);
                printf("\nPress any key to continue...\n");
                getchar(); getchar(); 
                break;
            case 4:
                Level_order(X, 10);
                printf("\nPress any key to continue...\n");
                getchar(); getchar();
                break;
            case 5:
                PrintTree(X);
                printf("\nPress any key to continue...\n");
                getchar(); getchar();
                break;
            case 6:
                char searchChar;
                printf("Masukkan char untuk dicari: ");
                scanf(" %c", &searchChar);
                if (Search(X, searchChar)) {
                    printf("%c ditemukan\n", searchChar);
                } else {
                    printf("%c tidak ditemukan.\n", searchChar);
                }
                printf("\nPress any key to continue...\n");
                getchar(); getchar();
                break;
            case 7:
                char levelChar;
                printf("Masukkan char untuk mengidentifikasi level: ");
                scanf(" %c", &levelChar);
                int level = Level(X, levelChar);
                if (level != -1) {
                    printf("Level dari %c adalah %d\n", levelChar, level);
                } else {
                    printf("%c tidak ada di tree.\n", levelChar);
                }
                printf("\nPress any key to continue...\n");
                getchar(); getchar();
                break;
            case 8:
                int depth = Depth(X);
                printf("Depth dari tree adalah %d\n", depth);
                printf("\nPress any key to continue...\n");
                getchar(); getchar();
                break;
            case 9:
                int jml_elmt = nbElmt(X);
                printf("Jumlah elemen dalam tree adalah %d\n", jml_elmt);
                printf("\nPress any key to continue...\n");
                getchar(); getchar();
                break;
            case 10:
                int jml_daun = nbDaun(X);
                printf("Jumlah daun dalam tree adalah %d\n", jml_daun);
                printf("\nPress any key to continue...\n");
                getchar(); getchar();
                break;
            case 11:
                printf("Exiting...\n");
                return 0;
        }
        printf("\n\nPress any key to continue...\n");
    }

    return 0;
}