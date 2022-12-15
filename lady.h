#include <pthread.h>
#include "guy.h"

class Lady {
public:
    explicit Lady(int n);

    ~Lady();

    std::string name; // имя прекрасной дамы (которая привлекательная студентка)

    void selectGuy(char *out); // метод выбора парня, out - куда выводить информацию о выборе

private:
    Guy *guys; // поклонники (массив)
    Guy *selected_guy; // тот самый поклонник, который проведёт с дамой вечер 14 февраля
    int number_of_fans; // количество поклонников
};