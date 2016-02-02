#include <stdio.h>
#include <string>
using namespace std;

int main(){
    int d, m;
    scanf("%d %d", &d, &m);
    d -= 1;
    m -= 1;
    string days[7] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
    int months[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    printf("%s", days[(months[m]+d)%7].c_str());
}
