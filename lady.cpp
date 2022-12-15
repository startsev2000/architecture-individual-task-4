#include <iostream>
#include <unistd.h>
#include "lady.h"
#include "strings.h"
#include <memory>
#include <string.h>

Lady::Lady(int n) {
    name = girl_names[n - 1];
    guys = new Guy[n];
    number_of_fans = n;
}

Lady::~Lady() {
    delete[] guys;
}

void Lady::selectGuy(char *out) {
    // запуск потоков
    for (int i = 0; i < number_of_fans; i++) {
        guys[i].number = i + 1;
        guys[i].start_thread();
    }
    int index;
    // выбор того самого поклонника, который проведёт вечер 14 февраля в прекрасной компании
    do {
        index = rand() % number_of_fans;
        Guy potential_guy = guys[index];
        selected_guy = (potential_guy.message.length() > 50) ? &potential_guy : nullptr;
    } while (!selected_guy);
    selected_guy->is_chosen = true;

    sleep(1);

    // вывод результата выбора куда необходимо
    if (strcmp(out, "") == 0) {
        std::cout << "И всё-таки она выбрала... парня по имени " << selected_guy->name << ", который написал "
                  << selected_guy->number << "м!\n";
    } else {
        FILE *fout = fopen(out, "w");
        fprintf(fout, "И всё-таки она выбрала... парня по имени %s, который написал %dм!\n", selected_guy->name.c_str(),
                selected_guy->number);
        fclose(fout);
    }
}