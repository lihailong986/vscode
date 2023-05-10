#include <chrono>
#include <mutex>
#include <random>
#include <string>
#include <iostream>

using namespace std;

std::string generateMessageId() {
    // 获取当前时间的毫秒值
    auto now = std::chrono::system_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    // 将毫秒值转换成字符串，并在前面补零到固定长度
    std::string timestampStr = std::to_string(ms);
    timestampStr = std::string(16 - timestampStr.length(), '0') + timestampStr;

    // 生成一个四位的随机数，并在前面补零到固定长度
    thread_local std::random_device rd;
    thread_local std::mt19937 gen(rd());
    thread_local std::uniform_int_distribution<> dis(0, 9999);
    std::string randomStr = std::to_string(dis(gen));
    randomStr = std::string(4 - randomStr.length(), '0') + randomStr;

    // 拼接时间戳和随机数，形成最终的messageId
    return timestampStr + randomStr;
}

int main(){
    
    std::string messageId = generateMessageId();
    std::cout << messageId << std::endl;
}