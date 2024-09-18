#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// N: 表示数组 values 中元素的个数。
// initialGuess: 初始猜测值，用于开始迭代。
// values[]: 存储需要计算平方根的输入数组。
// output[]: 存储计算结果的输出数组。
void sqrtSerial(int N,
                float initialGuess,
                float values[],
                float output[])
{
    // 迭代停止的阈值
    static const float kThreshold = 0.00001f;

    for (int i=0; i<N; i++) {

        float x = values[i];
        float guess = initialGuess;

        float error = fabs(guess * guess * x - 1.f);

        while (error > kThreshold) {
            guess = (3.f * guess - x * guess * guess * guess) * 0.5f;
            error = fabs(guess * guess * x - 1.f);
        }

        output[i] = x * guess;
    }
}

