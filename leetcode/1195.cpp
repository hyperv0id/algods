#include<semaphore.h>
// https://leetcode.cn/problems/fizz-buzz-multithreaded/submissions/555350445
class FizzBuzz {
private:
    int n;
    
    sem_t fi, bu, fb, nu;
public:
    FizzBuzz(int n) {
        this->n = n;
        sem_init(&fi, 0, 0);
        sem_init(&bu, 0, 0);
        sem_init(&fb, 0, 0);
        sem_init(&nu, 0, 1);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for(int i=3;i<=n;i+=3){
            if(i%5!=0){
                sem_wait(&fi);
                printFizz();
                sem_post(&nu);
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for(int i=5;i<=n;i+=5){
            if(i%3!=0){
                sem_wait(&bu);
                printBuzz();
                sem_post(&nu);
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for(int i=15;i<=n;i+=15){
            sem_wait(&fb);
            printFizzBuzz();
            sem_post(&nu);
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(int i=1;i<=n;i++){
            sem_wait(&nu);
            if(i%3!=0&&i%5!=0){
                printNumber(i);
                sem_post(&nu);
            }else if(i%3==0&&i%5!=0){
                sem_post(&fi);
            }else if(i%5==0&&i%3!=0){
                sem_post(&bu);
            }else if(i%15==0){
                sem_post(&fb);
            }
        }
    }
};
