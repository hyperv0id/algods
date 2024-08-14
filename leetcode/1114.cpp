#include <semaphore.h>
// https://leetcode.cn/problems/print-in-order/submissions/555337300
class Foo {
public:
    sem_t done_1, done_2;
    Foo() {
        
        sem_init(&done_1, 0, 0);
        sem_init(&done_2, 0, 0);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&done_1);
    }

    void second(function<void()> printSecond) {
        sem_wait(&done_1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&done_2);
    }

    void third(function<void()> printThird) {
        sem_wait(&done_2);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
