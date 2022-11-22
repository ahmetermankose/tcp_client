#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "libmeter.h"
enum weekDays
{
    SUNDAY = 0,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
};

char* monday	= "2.8.0";
char* tuesday	= "2.8.1";
char* wednesday	= "2.8.2";
char* thursday	= "2.8.3";
char* friday	= "2.8.4";
char* saturday	= "2.8.5";
char* sunday	= "2.8.6";

char* internal_relay_status ="1.9.0";
char get_buff[100];
char* obis_total_consumption = "readout";
char* obis_prev_day_consumption; 


int startComm(void);
double getTotalConsumption(void);
double getPrevDayConsumption(void);
int getInternalRelayStatus(void);
double getValueFromArr(void);