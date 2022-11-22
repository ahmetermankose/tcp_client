#include "cJSON.h"
#include "cJSON_Utils.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
    int jsonOutputProduced = 0;
    int isJsonRootCreated = 0;
    cJSON *root = NULL;
    cJSON *date = NULL;
    cJSON *consumptions = NULL;
    cJSON *total = NULL;
    cJSON *previous_day = NULL;
    cJSON *relay_status = NULL;

char* convertToJson(double total,double prev_day,int relay_stat);
void addTime(void);
void addConsumptions(double totalCons,double prevDayCons);
void addRelayStatus(int relayStat);