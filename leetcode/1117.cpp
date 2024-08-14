// https://leetcode.cn/problems/building-h2o/submissions/555347748
class H2O {
public:
    sem_t h,o;
    H2O() {
        // 保证最开始两个线程都能输出
        sem_init(&h, 0, 1);
        sem_init(&o, 0, 2);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&h);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        sem_post(&o);
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&o);
        sem_wait(&o);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        sem_post(&h);
        sem_post(&h);
    }
};
