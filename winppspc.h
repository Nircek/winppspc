#ifndef WINPPSPC_H
#define WINPPSPC_H
#include "wineasyhttpclient/wineasyhttpclient.hpp"
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
        private:
            void construct(PPSReplyType,std::string);
        } PPSReply;

        class winppspc {
            std::string host,user,pass;
            PPSReply toReply(std::string);
        public:
            winppspc(std::string host, std::string user, std::string pass);
            ~winppspc();
            PPSReply refresh();
            PPSReply push(std::string event);
        };
    }
}
#endif // winppspc_H
