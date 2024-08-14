#include<semaphore.h>
// https://leetcode.cn/problems/print-foobar-alternately/submissions/555338676
class FooBar {
private:
    int n;
    sem_t foo_, bar_;
public:
    FooBar(int n) {
        this->n = n;
        sem_init(&foo_, 0, 0);
        sem_init(&bar_, 0, 0);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            if(i != 0) {
                sem_wait(&bar_);
            }
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            sem_post(&foo_);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&foo_);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            sem_post(&bar_);
        }
    }
};
