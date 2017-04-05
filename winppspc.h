#ifndef WINPPSPC_H
#define WINPPSPC_H
#include "wineasyhttpclient/wineasyhttpclient.hpp"
namespace GitHub {
    namespace Nircek {

        typedef enum PPSReplyType{
            good,paramerror,dberror,winineterror,error
        } PPSReplyType;
        QString readPPSReplyType(PPSReplyType);

        typedef struct PPSReply{
            PPSReplyType replyType;
            QString reply;

            PPSReply(PPSReplyType,QString);
            PPSReply(char, QString);
        private:
            void construct(PPSReplyType,QString);
        } PPSReply;

        class winppspc {
            QString host,user,pass;
            QObject *parent;
            PPSReply toReply(QString);
        public:
            winppspc(QString host, QString user, QString pass, QObject *parent=nullptr);
            ~winppspc();
            PPSReply refresh();
            PPSReply push(QString event);
        };
    }
}
#endif // winppspc_H
