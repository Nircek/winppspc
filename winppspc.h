#ifndef WINPPSPC_H
#define WINPPSPC_H
#include "wineasyhttpclient/wineasyhttpclient.hpp"
#include <iostream>
namespace GitHub {
    namespace Nircek {

        typedef enum PPSReplyType{
            good,paramerror,dberror,winineterror,error
        } PPSReplyType;
        std::string readPPSReplyType(PPSReplyType);

        typedef struct PPSReply{
            PPSReplyType replyType;
            std::string reply;

            PPSReply(PPSReplyType,std::string);
            PPSReply(char, std::string);
            PPSReply();
        private:
            void construct(PPSReplyType,std::string);
        } PPSReply;
        PPSReply readerror(PPSReply);

        class winppspc {
            std::string host,user,pass;
            PPSReply toReply(std::string);
        public:
            winppspc();
            winppspc(std::string host);
            winppspc(std::string host, std::string user, std::string pass);
            ~winppspc();
            PPSReply refresh();
            PPSReply push(std::string event);
            PPSReply uregister(std::string user,std::string pass);
        };
    }
}
#endif // winppspc_H
