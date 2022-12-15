#include <pthread.h>
#include <string>

class Guy {
public:
    Guy();

    ~Guy();

    std::string message; // сообщение в валентинке, которое будет отправлено даме
    std::string name; // имя парня
    int number; // каким по счёту парень написал даме

    int start_thread(); // метод запуска потока
    int wait() const; // метод ожидания
    void run(); // метод для выбора сообщения для привлекательной студентки и его вывода

    bool is_chosen; // был ли парень выбран той самой дамой

private:
    pthread_t thread_id{};

    // функция потока, то есть запуск функции run
    static void *thread_func(void *d) {
        (static_cast <Guy *>(d))->run();
        return nullptr;
    }

    pthread_mutex_t mutex; // мьютекс (двоичный семафор)
};