#include <wininet.h>
//ADD wininet TO LINKER
#include <sstream>
/*/Please remove the star on left but dont remove namespaces*/namespace GitHub{namespace Nircek{
//  /*/comment*/something();
//  change to
//  //comment*/something();

std::string wineasyhttpclient(std::string url){
    //  https://github.com/Nircek/wineasyhttpclient
    //inspired by joske's program found in http://www.dreamincode.net/forums/topic/101532-download-file-from-url/

    HINTERNET hIurl, hInet;
    std::string ret;
    std::stringstream ss;
    const size_t BUF_SIZE=0x400;
    unsigned char buf[BUF_SIZE];
    unsigned long readed;
    goto l;
    err:
    ss<<'/'<<GetLastError();
    ret=ss.str();
    goto eret;
    l:
    if(InternetAttemptConnect(0)!=ERROR_SUCCESS)goto err;
    if((hInet = InternetOpen("downloader",INTERNET_OPEN_TYPE_DIRECT,NULL,NULL,0))==NULL)goto err;
    if((hIurl = InternetOpenUrl(hInet,url.c_str(),NULL,0,INTERNET_FLAG_NO_CACHE_WRITE,0))==NULL)goto err;
    do
    {
        if(!InternetReadFile(hIurl,&buf,BUF_SIZE,&readed))goto err;
        ret.append((const char*) buf, readed);
    }while(readed);
    eret:
    InternetCloseHandle(hIurl);
    InternetCloseHandle(hInet);
    return ret;
}

/*/*/}}


