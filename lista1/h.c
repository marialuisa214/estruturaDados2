#include <stdio.h>
#include <string.h>

int main() {
    char sheldon[8], raj[8];
    scanf("%s %s", sheldon, raj);

    if (strcmp(sheldon, raj) == 0) {
        puts("De novo!");
        return 0;
    } else if (strcmp(sheldon, "papel") == 0 &&
               (strcmp(raj, "pedra") == 0 || strcmp(raj, "Spock") == 0)) {
        puts("Bazinga!");
    } else if (strcmp(sheldon, "tesoura") == 0 &&
               (strcmp(raj, "lagarto") == 0 || strcmp(raj, "papel") == 0)) {
        puts("Bazinga!");
    } else if (strcmp(sheldon, "pedra") == 0 &&
               (strcmp(raj, "tesoura") == 0 || strcmp(raj, "lagarto") == 0)) {
        puts("Bazinga!");
    } else if (strcmp(sheldon, "Spock") == 0 &&
               (strcmp(raj, "tesoura") == 0 || strcmp(raj, "pedra") == 0)) {
        puts("Bazinga!");
    } else if (strcmp(sheldon, "lagarto") == 0 &&
               (strcmp(raj, "papel") == 0 || strcmp(raj, "Spock") == 0)) {
        puts("Bazinga!");
    }

    else {
        puts("Raj trapaceou!");
    }
}