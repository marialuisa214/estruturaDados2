#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // char vetorLetras[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    // 'K',
    //                       'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', '\0'};

    int matriz[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = 0;
        }
    }

    char lugar;
    int cadeira;

    while (scanf("%*c"), scanf("%c%d", &lugar, &cadeira) != EOF) {
        // for (int i = 0; i < n; i++) {
        //     if (lugar == vetorLetras[i]) {
        //         int numeroAcento = (cadeira - 1);
        //         matriz[i][numeroAcento] = 1;
        //     }
        // }

        int numeroAcento = (cadeira - 1);
        int linha = lugar - 'A';
        matriz[linha][numeroAcento] = 1;
    }
    printf(" ");
    for (int i = 0; i < m; i++) {
        printf(" %02d", i + 1);
    }
    puts("");
    for (int i = n - 1; i >= 0; i--) {
        printf("%c", 'A' + i);
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] == 1) {
                printf(" XX");
            } else {
                printf(" --");
            }
        }
        puts("");
    }
}