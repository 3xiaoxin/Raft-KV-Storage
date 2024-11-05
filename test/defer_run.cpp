//
// Created by henry on 24-1-23.
//
#include <iostream>
#include <string>
#include "include/defer.h"

using namespace std;

void testFun1(const string& name) { cout << name; }

void testFun2(const string& name) { cout << name; }

int main() {
  cout << "begin..." << endl;
  string str1 = "Hello";
  string str2 = " world";
  DEFER {
    testFun1(str1);
    testFun2(str2);
  };
  cout << "end..." << endl;
  return 0;
}




/////////////////////////////////////////////
void DecoderServerImp::addDecoder(const DecoderApp::addDecoderStruct &data_, tars::Int32 &code, std::string &msg, tars::TarsCurrentPtr _current_)
{
  string tokenInfo;
  map<string, string> TokencontextMap = _current_->getContext();
  tokenInfo - TokencontextMap["X-Verify-Token"];
  string loginName;
  string loginIP;
  if(!CRedidMgr::instance()->GetLoginInfo(REDISCOMM::PERMISSIONCOMM, tokenInfo, loginName, loginIP))
  {
    IVMS_LOG_ERROR("CDecoderManager::AddDecoder GetLoginInfo is error.");
  }
  CDecoderManager::instance()->AddDecoder(data_, code, msg, tokenInfo);
  if(code == 1)
  {
    string logMsg = str_fmt("%s%s%s%s", loginName.c_str(), "添加解码器", data_.decoderName.c_str(), "成功");
    DECLOG_INFO(u8"电视墙模块",loginName.c_str(), data_decoderName.c_str(), u8"失败", logMsg.c_str(),u8"一般行为", "m", loginIP);
  }
  else
  {
    string logMsg = str_fmt("%s%s%s%s", loginName.c_str(), "添加解码器", data_.decoderName.c_str(), "失败");
    DECLOG_INFO(u8"电视墙模块",loginName.c_str(), data_decoderName.c_str(), u8"失败", logMsg.c_str(),u8"异常行为", "m", loginIP);
  }
  return;
}



bool CReddiMgr::GetLOginInfo(const int comm, string token, string &userName, string &loginIP)
{
  lock_guard<mutex> lock(m_Redismtu);
  try{
    bool res = false;
    redisReply *ret = NULL;
    string value;
    switch(comm)
    {
      case REDIS
    }
  }
}


void CDecoderManager::AddDEcoder(const DecoderApp::addDecoderStruct &data_, int &code, string &msg, string &token)
{
  UINT_T err_code = 1;
  if(map_Decoder_info.size() >= 10)
  {
    code = 0;
    msg = "超过解码器最大能力集";
    return;
  }
  if(data_.decoderName.empty()||!judgeDecoderName((char*)data_.decoderName.c_str())||data_.decoderName.size()>32)
  {
    code = 0;
    msg = u8"添加的解码器名称非法";
    return;
  }
  if(check_ip(data_.decoderIP.c_str()) != 0)
  {
    code = 0;
    msg = "解码器IP格式错误";
    return 0;
  }
  if(data_.decoderPort<1 || data_.decoderPort > 65535)
  {
    code = 0;
    msg = "解码器端口格式错误";
    return;
  }
  if(this->IsExistDecoderInMemory(data_.decoderName)||this->IsExistDecoderInMemorybyIP(data_.decoderIP))
  {
    code = 0;
    msg = "添加的解码器已存在";
    return;
  }
  DecoderStructInfo Decoder_custominfo;
  Decoder_custominfo.ID = CDBDecoder:QueryNextID();
  Decoder_custominfo.decoderName = data_.deocderName;
  Decoder_custominfo.decoderIP = data_.decoderIP;
  Decoder_custominfo.decoderProtocol = data_.deocderProtocol;
  Decoder_custominfo.decoderPort = data_.deocderPort;
  Decoder_custominfo.decoderUserName = data_.decoderUserName;

  string comparePassword;
  if(!DecryptDevVkek(comparePassword, data_.decoderPassword))
  {
    code = 0;
    msg = "解码器口令解码失败";
    return;
  }
  Decoder_custominfo.decoderPasswordd = comparePassword;
  addDecoderInMemory(Decoder_custominfo);
  if(!ConnectDecoder(Decoder_custominfo.ID, Decoder_custominfo.decoderIP, Decoder_custominfo.decoderPOrt, Decoder_custominfo.decoderUserName, Decoder_custominfo.decoderPassword))
  {
    code = 0;
    msg = "解码器不存在或在线添加失败";
    delDecoderInMemory(Decoder_custominfo.ID);
    return;
  }
  Decoder_custominfo.decoderPassword = data_.decoderPassword;
  if(!CDBDecoder::Insert(err_code, Decoder_custominfo))
  {
    code = 0;
    delDecoderInMemory(Decoder_custominfo.ID);
    msg = "写入数据库失败";
    return;
  }
  code = 1;
  msg = "成功";
  return;
}


bool CISAPIManaget::getDecoderCapability(const string ip, const int port, const string LoginName, DecoderApp::getSessionCapabilityStruct &sessionAbility)
{
  bool ret = false;
  string bckmsg = " ";
  do
  {
    string uri = str_fmt(sessionLogincapget, LoginName.c_str(), "e026a18b");
    string loginIP = ip;
    uint32_t loginport = port;
    std::string http_url = GEnHttpUrl(uri, loginIP, loginport);
    HttpHeader http_headers;
    http_headers.content_type_ = "application/json";
    HttpResponse http_rsp;
    string LoginNamePass = " ";
    ret = GetRequest(http_rsp, http_url, http_headers, LoginNamePass);
    if(!ret)
    {
      IVMS_LOG_ERROR("CISAPIManager::getDecoderCapability GetResquest error");
      break;
    }
    if(kHttpStatusCodeOK != http_rsp.rsp_code_)
    {
      IVMS_LOG_ERROR("User , kHttpStatusCodeOK%d", http_rsp.rsp_code_);
      ret = false;
      break;
    }
    ret = getSessionCapability(sessionAbility, http_rsp.rsp_data_, bckmsg);
  } while (false);
  return ret;
}







 

class HelloImp : public Decoder::DecoderServer
{
public:
  virtual ~HelloImp(){};
  virtual void initialize();
  virtual void destroy();
  virtual void getServerInfo(int &code, std::string &msg, tars::TarsCurrentPtr current);
}













