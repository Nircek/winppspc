# QTPPSPC
###### Windows Pseudo PHP Server's Pseudo Client
### Example
```c++
#include <iostream>
#include "winppspc.h"

using namespace std;
using namespace GitHub::Nircek;
int main(int argc, char *argv[])
{
    winppspc pc("http://localhost","admin","admin");
    PPSReply rep=pc.push("everything");
    cout<<readPPSReplyType(rep.replyType)<<' '<<rep.reply<<'\n';
    rep=pc.refresh();
    cout<<readPPSReplyType(rep.replyType)<<' '<<rep.reply<<'\n';
    return 0;
}

```
