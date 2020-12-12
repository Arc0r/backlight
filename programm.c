#include <stdio.h>
#include <time.h>
//dir /sys/class/leds/chromeos::kbd_backlight/brightness
// 0 = off
// 100 = on

int write(int n){
    FILE *keyboard;
    keyboard = fopen("/sys/class/leds/chromeos::kbd_backlight/brightness","w");
    fprintf(keyboard,"%d",n);
    fclose(keyboard);
    return n;
}
int get_time(){
    time_t now;
    struct tm *now_tm;
    int hour;

    now = time(NULL);
    now_tm = localtime(&now);
    hour = now_tm->tm_hour;
    return hour;
}
int main(){
    int hour;
    int brightness;
    int i=1;
    int t;
    while (i==1){
        hour = get_time();
        if (hour < 18 && hour > 6){
            brightness = 0;
            write(brightness);
        }else if (hour >= 18 || hour < 6){
            brightness = 60;
            write(brightness);
        }
        i++;
    }//endofwhile
    return 0;
}