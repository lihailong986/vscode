 #include <iostream>
 #include <vector>
 #include <string>
 #include <sstream>
 #include <algorithm>
using namespace std;
void SplitString(const string str,const char split, vector<string>& res)
{    
    if(str.empty()) return;
    string strs = str + split;
    size_t pos = strs.find(split);
    while(pos != strs.npos){
        string temp = strs.substr(0,pos);
        res.push_back(temp);
        strs = strs.substr(pos + 1, strs.size());
        pos = strs.find(split);
    }
}

std::vector<std::string> split(const std::string &input, char delimiter) {
  std::vector<std::string> result;
  std::stringstream stream(input);
  std::string item;
  while (std::getline(stream, item, delimiter)) {
    result.push_back(item);
  }
  return result;
}

void ReceiveDeviceMessage(char *topic, char *msg)
{
    vector<string> topicSplit;
    topicSplit = split((string)topic, '/');
    if (find(topicSplit.begin(), topicSplit.end(), "child") == topicSplit.end())
    {
        cout << "device operated" << endl;
        // if (find(topicSplit.begin(), topicSplit.end(), "properties") != topicSplit.end())
        // {
        //     cout << "device properties" << endl;
        //     if (topicSplit.back() == "read")
        //     {
        //         cout << "device read" << endl;
        //         cout<<((string)topic + "/reply")<<endl;
        //     }
        //     if (topicSplit.back() == "write")
        //     {
        //         cout << "device write" << endl;
        //         cout<<((string)topic + "/reply")<<endl;
        //     }
        // }
        // else if (find(topicSplit.begin(), topicSplit.end(), "function") != topicSplit.end())
        // {
        //     cout << "device function" << endl;
        //     cout<<((string)topic + "/reply")<<endl;
        // }

        auto riter = topicSplit.rbegin() + 1;
        if(riter == topicSplit.rend()) {
            return ;
        }
        if (*riter == "properties" && topicSplit.back() == "read")
        {
            cout << "device properties" << endl;
            cout << "device read" << endl;
            cout<<((string)topic + "/reply")<<endl;
        } else if (*riter == "properties" && topicSplit.back() == "write") {
            cout << "device write" << endl;
            cout<<((string)topic + "/reply")<<endl;
        } else if (*riter == "function" && topicSplit.back() == "invoke")
        {
            cout << "device function" << endl;
            cout<<((string)topic + "/reply")<<endl;
        }

    }
    else {
        cout << "child device operated" << endl;
        string str[] = {"child"};
        // cout<<"count : "<<count(topicSplit.begin(), topicSplit.end(), "child")<<endl;
        string subDeviceId;
        vector<string>::iterator it = find_end(topicSplit.begin(), topicSplit.end(), str, str + 1);
        subDeviceId = topicSplit[it - topicSplit.begin() + 1];
        cout << subDeviceId << endl;
        if (find(topicSplit.begin(), topicSplit.end(), "properties") != topicSplit.end())
        {
            cout << "child device properties" << endl;
            if (topicSplit.back() == "read")
            {
                cout << "child device read" << endl;
                cout<<((string)topic + "/reply")<<endl;
            }
            if (topicSplit.back() == "write")
            {
                cout << "child device write" << endl;
                cout<<((string)topic + "/reply")<<endl;
            }
        }
        else if (find(topicSplit.begin(), topicSplit.end(), "function") != topicSplit.end())
        {
            cout << "child device function" << endl;
            cout<<((string)topic + "/reply")<<endl;
        }
    }
}

int main(){
   vector<string> topic = 
   {
    "/harmony_controller/harmony_controller_001/child/wind_mill_001/child/aralm/child/jafasbfhfb/child/kajkfj/properties/read",
    "/harmonydevice/harmony001/properties/read",
    "/harmonydevice/harmony001/properties/write",
    "/harmonydevice/harmony001/child/windmill001/properties/write",
    "/{productId}/{deviceId}/child/{childDeviceId}/function/invoke",
    "/{productId}/{deviceId}/function/invoke"
   };
   string msg = "";
   for(int i = 0;i < topic.size();i++){
    cout<<"---------------------------------->"<<i<<endl;
    ReceiveDeviceMessage((char*)(topic[i].c_str()), (char*)(msg.c_str()));
   }
//ReceiveDeviceMessage((char*)(topic[3].c_str()), (char*)(msg.c_str()));
//   std::string input = "hello,world,how,are,you";
//   char delimiter = ',';
//   std::vector<std::string> words = split(input, delimiter);
//   for (const auto &word : words) {
//     std::cout << word << std::endl;
//   }
}