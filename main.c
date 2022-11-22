#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double total_consumption = 0.000;
double prev_day_consumption = 0.000;
char* relay_status;

int startComm(void);
double getTotalConsumption(void);
double getPrevDayConsumption(void);
int getInternalRelayStatus(void);

char* convertToJson(double total,double prev_day,int relay_stat);

char* encryptJson(char *value);
int sendMessage(char* message);

char * encryptedJson;
char *message;
int main(int argc, char const *argv[])
{
    int ret = startComm();
    printf("ret init %d \n",ret);
    if (ret == 0)
    {
        total_consumption = getTotalConsumption();  
        printf("Total : %.3f \n",total_consumption);

        prev_day_consumption = getPrevDayConsumption();
        printf("Prev Day : %.3f \n",prev_day_consumption);

        int b_relay_status = getInternalRelayStatus();

        char* json_string = convertToJson(total_consumption,prev_day_consumption,b_relay_status);
        printf("\nJSON :%s\n",json_string);

        encryptedJson =encryptJson(json_string);
        int len = strlen(encryptedJson);
         
        message = (char *)malloc(len*(sizeof(char)));
        strncpy(message,encryptedJson,len);
        
        sendMessage(message);
    
    }else{
        printf("init fail : %d \n",ret);
    }
    
    return 0;
}