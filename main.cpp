#include <iostream>
#include "lady.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *nol = "";
    if (strcmp(argv[1], "-f") == 0) {
        FILE *input = fopen(argv[2], "r");

        if (input == nullptr) {
            printf("Incorrect file!\n");
            return 0;
        }
        int n;
        fscanf(input, "%d", &n);
        if (n < 1 || n > 10) {
            std::cout << "Invalid N! Should be from 1 to 10\n";
            return 0;
        }
        Lady lady(n);
        lady.selectGuy(argv[3]);
        fclose(input);
    } else if (strcmp(argv[1], "-c") == 0) {
        std::cout << "Помогите прекрасной даме! Введите количество парней, которые ей напишут (от 1 до 10):\n";
        int n;
        scanf("%d", &n);
        if (n < 1 || n > 10) {
            std::cout << "Invalid N! Should be from 1 to 10\n";
            return 0;
        }
        Lady lady(n);
        std::cout << "Вы помогли даме по имени " << lady.name << "! Вот что ей написали: \n";
        lady.selectGuy(nol);
    } else if (strcmp(argv[1], "-r") == 0) {
        int n;
        srand(time(nullptr));
        n = (rand() + 1) % 10 + 1;
        if (n < 1 || n > 10) {
            std::cout << "Invalid N! Should be from 1 to 10\n";
            return 0;
        }
        Lady lady(n);
        lady.selectGuy(nol);
    }
    return 0;
}
