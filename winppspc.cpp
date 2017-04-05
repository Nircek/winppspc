#include "winppspc.h"
using namespace GitHub::Nircek;
winppspc::winppspc(std::string host, std::string user, std::string pass):
    host(host),user(user),pass(pass){

}

winppspc::~winppspc(){

}
std::string GitHub::Nircek::readPPSReplyType(PPSReplyType type){
    switch(type){
    case good:          return "good";
    case paramerror:    return "paramERR";
    case dberror:       return "dbERR";
    case winineterror:  return "wininetERR";
    case error:         return "unexceptedERR";
    }
    return "impossibleERR";
}

PPSReply::PPSReply(char c, std::string s):
    reply(s){
    switch(c){
    case '0':   construct(good,s);          break;
    case '-':   construct(paramerror,s);    break;
    case '+':   construct(dberror,s);       break;
    case '/':   construct(winineterror,s);  break;
    default:    construct(error,s);         break;
    }
}

PPSReply::PPSReply(PPSReplyType type, std::string s){
    construct(type,s);
}

void PPSReply::construct(PPSReplyType type, std::string s){
    replyType=type;
    reply=s;
}

PPSReply winppspc::refresh(){
    return toReply(wineasyhttpclient(host+"/refresh.php?user="+user+"&pass="+pass));
}
PPSReply winppspc::push(std::string event){
    return toReply(wineasyhttpclient(host+"/push.php?user="+user+"&pass="+pass+"&event="+event));
}
PPSReply winppspc::toReply(std::string s){
    return PPSReply(s.at(0),s.substr(1));
}
