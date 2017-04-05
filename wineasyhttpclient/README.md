# WinEasyHTTPClient
Easy to use function wineasyhttpclient(std::string url).
When a [WinINet](https://msdn.microsoft.com/library/windows/desktop/aa383630(v=vs.85).aspx) error occures, returns '/' and [WinINet error](https://support.microsoft.com/en-us/help/193625/info-wininet-error-codes-12001-through-12156). For example: "/12003".
## Example
```c++
#include <iostream>
#include "wineasyhttpclient.hpp"
using namespace std;
using namespace GitHub::Nircek;
int main()
{
    cout<<wineasyhttpclient("https://github.com/Nircek/")<<'\n'<<'\n';
    return 0;
}
```
