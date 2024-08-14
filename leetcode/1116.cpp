// https://leetcode.cn/problems/print-zero-even-odd/submissions/555343152
class ZeroEvenOdd {
private:
    int n;
    sem_t s0, s1,s2, sx;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&s0, 0, 0);
        sem_init(&s1, 0, 0);
        sem_init(&s2, 0, 0);
        sem_init(&sx, 0, 0);
        sem_post(&sx);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=0;i<n;) {
            sem_wait(&sx);
            printNumber(0);
            i++;
            if(i % 2 == 0) {
                sem_post(&s2);
            } else {
                sem_post(&s1);
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=2;i<=n;i+=2) {
            sem_wait(&s2);
            printNumber(i);
            sem_post(&sx);
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=1;i<=n;i+=2) {
            sem_wait(&s1);
            printNumber(i);
            sem_post(&sx);
        }
    }
};
