#include "../exercise.h"
#include <numeric>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    
    // 计算张量的总元素数
    int size = std::accumulate(std::begin(shape), std::end(shape), 1, std::multiplies<int>());
    
    // 计算张量占用的字节数
    size *= sizeof(DataType);
    
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}
