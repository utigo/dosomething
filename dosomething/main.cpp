#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    std::string  filename = "test.bin";
    std::fstream s(filename, std::fstream::binary | std::fstream::trunc | std::fstream::in | std::fstream::out);
    if (!s.is_open()) {
        std::cout << "failed to open " << filename << '\n';
    } else {
        // 写入
        double d = 3.14;
        s.write(reinterpret_cast<char *>(&d), sizeof d);  // 二进制输出
        s << 123 << "abc";                                // 文本输出

        // 对于 fstream ，这会移动文件位置指针（放置与获取）
        s.seekp(0);

        // 读取
        s.read(reinterpret_cast<char *>(&d), sizeof d);  // 二进制输入
        int         n;
        std::string str;
        if (s >> n >> str)  // 文本输入
            std::cout << "read back from file: " << d << ' ' << n << ' ' << str << '\n';
    }
}