#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;
    Fibonacci() : cached(1), cache{0, 1} {
        // cache[0] = 0, cache[1] = 1; 其余元素默认为 0
    }

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
       if (i > cached) {
            for (int j = cached + 1; j <= i; ++j) {
                cache[j] = cache[j - 1] + cache[j - 2];
            }
            cached = i;  // 更新缓存状态
        }
        return cache[i];  // 返回缓存中的第 i 项
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
