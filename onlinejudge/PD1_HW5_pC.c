#include <stdio.h>
#define ll long long int
#define range 1000000

ll time[range];
int main() {
    ll count , ans = 0;
    scanf("%lld" , &count);
    ll car_in[count] , car_out[count];
    for (ll i = 0; i < count; i++) {
        scanf("%lld %lld" , &car_in[i] , &car_out[i]);
        time[car_in[i]-1]++;
        time[car_out[i]-1]--;
    }
    count = 0;
    for (int i = 0; i < range; i++) {
        count += time[i];
        ans = (ans > count) ? ans : count;
    }
    printf("%lld" , ans);
    return 0;
}
