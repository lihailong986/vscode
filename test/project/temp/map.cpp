#include <iostream>
#include <map>
using namespace std;
enum class PublishType
{
    DEVICE_PROPERTIES_REPORT = 0, //鸿蒙设备属性上报
    DEVICE_PROPERTIES_READ, //鸿蒙设备读取属性
    DEVICE_PROPERTIES_WRITE, //鸿蒙设备修改属性
    DEVICE_FUNCTION_INVOKE, //调用设备功能
    SUB_DEVICE_FUNCTION_INVOKE, //调用子设备功能
    SUB_DEVICE_REGISTER,    //子设备注册
    SUB_DEVICE_UNREGISTER,  //子设备注销
    SUB_DEVICE_CONNECTED,   //子设备上线
    SUB_DEVICE_DISCONNECT,  //子设备下线
    SUB_DEVICE_PROPERTIES_WRITE,  //子设备修改属性
    SUB_DEVICE_PROPERTIES_READ,     //子设备读取属性
    DEVICE_EVENT,   //上报设备事件 topic : /{productId}/{deviceId}/event/{eventId}
   // SUB_DEVICE_EVENT,   //上报子设备事件 topic : /{productId}/{deviceId}/child/{childDeviceId}/event/{eventId}
};
using PUBLISH_TYPE = enum PublishType;

const std::map<PUBLISH_TYPE, std::string> TOPIC_APPEND = {
        {PUBLISH_TYPE::DEVICE_PROPERTIES_REPORT, "properties/report"},
        {PUBLISH_TYPE::DEVICE_EVENT, "event/"},
        {PUBLISH_TYPE::SUB_DEVICE_REGISTER,"register"},
        {PUBLISH_TYPE::SUB_DEVICE_UNREGISTER, "unregister"}
};

int main(){
    auto item = TOPIC_APPEND.find(PUBLISH_TYPE::DEVICE_PROPERTIES_REPORT);
    string topic = "avjk/" + item->second;
    cout<<item->second<<endl;
    cout<<topic<<endl;
    return 0;
}
