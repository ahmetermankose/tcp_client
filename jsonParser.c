#include "jsonParser.h"

char* convertToJson(double total,double prev_day,int relay_stat){
    if (root != NULL)
    {
        cJSON_Delete(root);
    }

    root = cJSON_CreateObject();
   
    addTime();
    addConsumptions(total,prev_day);
    addRelayStatus(relay_stat);

    char *returnJsonDataCopy = NULL;
    char *mergedJsonData =  cJSON_PrintUnformatted(root);
    //printf("%s", mergedJsonData);
   
    int length = strlen(mergedJsonData);
    returnJsonDataCopy = (char *)malloc(length + 1);

    memcpy(returnJsonDataCopy, mergedJsonData, length + 1);

    cJSON_free(mergedJsonData);
    cJSON_Delete(root);

   return returnJsonDataCopy;

}

void addTime(void){
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    timer = time(NULL);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%d.%m.%Y %H:%M:%S", tm_info);
    //printf("%s\n",buffer);
    date = cJSON_CreateString(buffer);

    cJSON_AddItemToObject(root, "date", date);

}
void addConsumptions(double totalCons,double prevDayCons){
    
    consumptions = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "consumption", consumptions);
    cJSON_AddNumberToObject(consumptions, "total", totalCons);
    cJSON_AddNumberToObject(consumptions, "previous_day", prevDayCons);
}

void addRelayStatus(int relayStat){
    bool b_status = 0;

    //relay_status = cJSON_CreateObject();
    if (relayStat)
    {
        b_status = 1;
    }else{
        b_status = 0;
    }
    cJSON_AddBoolToObject(root,"relay_status",b_status);
}