#include <iostream>
#include "guy.h"
#include "strings.h"

Guy::Guy() {
    name = guy_names[rand() % 10];
    is_chosen = false;
}

Guy::~Guy() = default;

int Guy::start_thread() {
    return pthread_create(&thread_id, nullptr, Guy::thread_func, this);
}

int Guy::wait() const {
    return pthread_join(thread_id, nullptr);
}

void Guy::run() {
    // используется двоичный семафор
    pthread_mutex_lock(&mutex);
    message = offers[rand() % 10];
    std::string info = "(" + std::to_string(number) + ") Парень " + name + " написал ей: \"" + message + "\"\n";
    std::cout << info;
    pthread_mutex_unlock(&mutex);
    wait();
}

