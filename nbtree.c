#include "nbtree.h"

void Create_tree(Isi_Tree X, int Jml_Node){

    char karakter = 'A';
    int i = 1, ascii = (int)karakter;

    while (i <= Jml_Node )
    {
        X[i].info = ascii;
        ascii++;
        i++;
    }
    
    X[1].ps_fs = 2; 
    X[1].ps_nb = nil; 
    X[1].ps_pr = nil; 

    X[2].ps_fs = 4; 
    X[2].ps_nb = 3; 
    X[2].ps_pr = 1;

    X[3].ps_fs = 6; 
    X[3].ps_nb = nil; 
    X[3].ps_pr = 1;

    X[4].ps_fs = nil; 
    X[4].ps_nb = 5; 
    X[4].ps_pr = 2;

    X[5].ps_fs = 9; 
    X[5].ps_nb = nil; 
    X[5].ps_pr = 2;

    X[6].ps_fs = nil; 
    X[6].ps_nb = 7; 
    X[6].ps_pr = 3;

    X[7].ps_fs = nil; 
    X[7].ps_nb = 8; 
    X[7].ps_pr = 3;

    X[8].ps_fs = nil; 
    X[8].ps_nb = nil; 
    X[8].ps_pr = 3;

    X[9].ps_fs = nil; 
    X[9].ps_nb = 10; 
    X[9].ps_pr = 5;

    X[10].ps_fs = nil; 
    X[10].ps_nb = nil; 
    X[10].ps_pr = 5;
    
}

boolean IsEmpty (Isi_Tree P){
    return P[1].ps_fs == nil;
}

void PreOrder (Isi_Tree P){
    int indeks = 1 ;
    printf("%c ", P[indeks].info);
    for (int i = 1; i < 10; i++)
    {
        if (P[indeks].ps_fs == nil && P[indeks].ps_nb == nil)
        {
            while (P[indeks].ps_nb == nil)
            {
                indeks = P[indeks].ps_pr;
                if (indeks == 1)
                {
                    break;
                }
            }
            indeks = P[indeks].ps_nb;
            printf("=> %c ", P[indeks].info);

        }else{
            if (P[indeks].ps_fs != nil){
                printf("=> %c ",P[P[indeks].ps_fs].info );
                indeks = P[indeks].ps_fs;
            }
            else{
                if (P[indeks].ps_nb != nil){
                    printf("=> %c ", P[P[indeks].ps_nb].info);
                    indeks = P[indeks].ps_nb;
                }
            }
        }
    }
}

void InOrder(Isi_Tree P) {
    int current = 1, fsr; 
    boolean firstroot = false, dontprint = false;
    while (firstroot == false){
        if (P[current].ps_fs != nil){
            if (current == 1){
                fsr = P[current].ps_fs;
            }
            current = P[current].ps_fs;
            if (P[current].ps_fs == nil){
                printf("%c ", P[current].info);
                if (dontprint == false){
                    printf("%c ", P[P[current].ps_pr].info);
                    dontprint = true;
                } 
                else {
                    dontprint = false;
                }
            } 
        }
        else{
            if (P[current].ps_nb != nil){
                current = P[current].ps_nb;
                if (P[current].ps_fs == nil){
                    printf("%c ", P[current].info);
                    if (dontprint == false){
                        printf("%c ", P[P[current].ps_pr].info);
                        dontprint = true;
                    } 
                }
            } else {
                firstroot = true;
                if (firstroot == true && P[fsr].ps_nb !=nil){
                    firstroot = false;
                    dontprint = false;
                    fsr = P[fsr].ps_nb;
                    current = fsr;
                    printf("%c ", P[1].info);
                }
            }
        }
    }
}

void PostOrder (Isi_Tree P){
    int current = 1; // Asumsi node 1 adalah root
    boolean firstroot = false, edgestatus = false;
    while (firstroot == false){
        if (P[current].ps_fs != nil && edgestatus == false){
            current = P[current].ps_fs;
            if (P[current].ps_fs == nil){
                printf("%c ", P[current].info);
            } 
        }
        else{
            if (P[current].ps_nb != nil){
                current = P[current].ps_nb;
                if (P[current].ps_fs == nil){
                    printf("%c ", P[current].info);
                }
            } else {
                edgestatus = true;
                current = P[current].ps_pr;
                printf("%c ", P[current].info);
            }
            if (P[current].ps_pr == 1){
                firstroot = true;
                if (firstroot == true && P[current].ps_nb !=nil){
                    firstroot = false;
                    edgestatus = false;
                    current = P[current].ps_nb;
                }
            }
        }
    }
    printf("%c ", P[1].info);
}

void Level_order(Isi_Tree X, int Maks_node){
    int i = 1;
    while (i <= Maks_node){
        printf("%c ", X[i].info);
        i++;
    }
}

void PrintTree (Isi_Tree P){
    for (int i = 1; i <= 10; i++)
    {
        printf("%c ", P[i].info);
        printf("%d ",P[i].ps_fs); 
        printf("%d ",P[i].ps_nb); 
        printf("%d\n\n",P[i].ps_pr);
    }
    
}

int nbElmt (Isi_Tree P){
    hitungNode(P, 1);
}

int hitungNode(Isi_Tree P, address nodeIdx) {
    if (nodeIdx == nil) return 0;

    int count = 1; // hitung node ini sendiri

    // Hitung semua anak dari node ini
    address child = P[nodeIdx].ps_fs;
    while (child != nil) {
        count += hitungNode(P, child);
        child = P[child].ps_nb; // pindah ke adik
    }

    return count;
}

int nbDaun(Isi_Tree P){
    int count = 0;
    boolean firstroot = false, edgestatus = false;
    int current = 1; // Asumsi node 1 adalah root
    while (firstroot == false){
        if (P[current].ps_fs != nil && edgestatus == false){
            current = P[current].ps_fs;
            if (P[current].ps_fs == nil){
                count++;
            } 
        }
        else{
            if (P[current].ps_nb != nil){
                current = P[current].ps_nb;
                if (P[current].ps_fs == nil){
                    count++;
                }
            } else {
                edgestatus = true;
                current = P[current].ps_pr;
            }
            if (P[current].ps_pr == 1){
                firstroot = true;
                if (firstroot == true && P[current].ps_nb !=nil){
                    firstroot = false;
                    edgestatus = false;
                    current = P[current].ps_nb;
                }
            }
        }
    }
    return count;
}

boolean Search (Isi_Tree P, infotype X){
    int i = 1;
    boolean found = false;
    while (i <= 10 && found == false){
        if (P[i].info == X){
            found = true;
        } else {
            i++;
        }
    }
    return found;
}

int Level (Isi_Tree P, infotype X){
    int i = 1, level = 0;
    boolean found = false;
    while (i <= 10 && found == false){
        if (P[i].info == X){
            found = true;
        } else {
            i++;
        }
    }
    if (found == true){
        while (i != 1){
            level++;
            i = P[i].ps_pr;
        }
    }
    return level;
}

int Depth (Isi_Tree P){
    return HitungDepth(P, 1);
}

int HitungDepth(Isi_Tree P, address node) {
    if (node == 0) return -1;

    int max = -1;
    address child = P[node].ps_fs;
    while (child != 0) {
        int d = HitungDepth(P, child);
        if (d > max) max = d;
        child = P[child].ps_nb;
    }
    return max + 1;
}

int Max (infotype Data1, infotype Data2){
    if (Data1 > Data2){
        return Data1;
    } else {
        return Data2;
    }
}

