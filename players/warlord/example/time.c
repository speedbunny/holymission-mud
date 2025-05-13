#include "/players/warlord/time.h"
#include "/players/warlord/math.h"


mapping  mWorldData();
int      iQueryMinutes(int iTimeData);
int      iQueryDay(int iTimeData);
string   sQueryDayName(int iTimeData);
int      iQueryHour(int iTimeData);
int      iQueryYear(int iTimeData);
int      iQueryMonth(int iTimeData);
string   sQueryMonthName(int iTimeData);
int      iQueryNow();
int      iQueryWeek(int iTimeData);
string   sQueryTimeOfDay();
void     vNextChange();
void     vConfigureDay();

private static string   _TimeOfDay;
private static mapping  _mWorldData;

mapping mWorldData() {
    int temps, iDays, x, morn, even, tmp, hour, min;
    mapping ret;

    if((iDays= ((iQueryMonth(temps = time())*20) + iQueryDay(temps))) ==
      LONGEST_DAY)
	return (["sunrise":({4,0}),"morning":({5,0}),"sunset":({18,0}),
	  "twilight":({17,0}) ]);
    else if(iDays == SHORTEST_DAY)
	return (["sunrise":({6,0}),"morning":({7,0}),"sunset":({16,0}),
	  "twilight":({15,0}) ]);
    else if(iDays > LONGEST_DAY) x = iDays-LONGEST_DAY;
    else x = iDays;
    tmp = 2*to_int(percent(x, LONGEST_DAY));
    if(iDays > LONGEST_DAY) {
	morn = 400+tmp;
	even = 1800-tmp;
    }
    else {
	morn = 600-tmp;
	even = 1600+tmp;
    }
    hour = to_int(("0"+morn)[0..1]);
    min = (to_int(("0"+morn)[2..3])*60)/100;
    ret = ([]);
    ret["sunrise"] = ({ hour, min });
    ret["morning"] = ({ hour+1, min });
    hour = to_int((even+"")[0..1]);
    min = (to_int((even+"")[2..3])*60)/100;
    ret["sunset"] = ({ hour, min });
    ret["twilight"] = ({ hour-1, min });
    return ret;
}
int iQueryMinutes(int iTimeData) {
    if (!iTimeData) iTimeData=time();
    return CURRENT_MINUTE(iTimeData);
}

int iQueryDay(int iTimeData) {
    if(!iTimeData) iTimeData = time();
    return CURRENT_DAY(iTimeData)+1;
}

/*
string sQueryDayName(int iTimeData){
  if(!iTimeData) iTimeData=time();
  iTimeData = ctime(iTimeData);
  while(iTimeData>sizeof(DAYS)) iTimeData = to_int(iTimeData/sizeof(DAYS));
  return DAYS[iTimeData-1];
}
*/

int iQueryHour(int iTimeData) {
    if(!iTimeData) iTimeData = time();
    return CURRENT_HOUR(iTimeData);
}
int iQueryMonth( int iTimeData ) {
    if(!iTimeData) iTimeData=time();
    return CURRENT_MONTH(iTimeData)+1;
}
int iQueryYear( int iTimeData ) {
    if(!iTimeData) iTimeData=time();
    return CURRENT_YEAR(iTimeData)+1;
}
string sQueryMonthName(int iTimeData) {
    if(!iTimeData) iTimeData = time();
    return MONTHS[(CURRENT_MONTH(iTimeData))];
}

int iQueryNow() { return NOW(time()); }

int iQueryWeek(int iTimeData) {
    if(!iTimeData) iTimeData= time();
    return CURRENT_WEEK(iTimeData)+1;
}
string sQueryTimeOfDay() { return _TimeOfDay; }

int *iQuerySunrise() { return _mWorldData["sunrise"]; }

int *iQuerySunset() { return _mWorldData["sunset"]; }


void vConfigureDay() {
    int iTime, iTimeData, y;

    _mWorldData = mWorldData();
    y = iQueryMinutes(iTime = time());
    if((iTimeData=iQueryHour(iTime)) < _mWorldData["sunrise"][0]) _TimeOfDay = "night";
    else if(iTimeData==_mWorldData["sunrise"][0]) {
	if(y < _mWorldData["sunrise"][1]) _TimeOfDay = "night";
	else _TimeOfDay = "dawn";
    }
    else if(iTimeData < _mWorldData["morning"][0]) _TimeOfDay = "dawn";
    else if(iTimeData == _mWorldData["morning"][0]) {
	if(y < _mWorldData["morning"][1]) _TimeOfDay = "dawn";
	else _TimeOfDay = "day";
    }
    else if(iTimeData < _mWorldData["twilight"][0]) _TimeOfDay = "day";
    else if(iTimeData == _mWorldData["twilight"][0]) {
	if(y < _mWorldData["twilight"][1]) _TimeOfDay = "day";
	else _TimeOfDay = "twilight";
    }
    else if(iTimeData < _mWorldData["sunset"][0]) _TimeOfDay = "twilight";
    else if(iTimeData == _mWorldData["sunset"][0]) {
	if(y < _mWorldData["sunrise"][1]) _TimeOfDay = "night";
	else _TimeOfDay = "dawn";
    }
    else if(iTimeData < _mWorldData["morning"][0]) _TimeOfDay = "dawn";
    else if(iTimeData == _mWorldData["morning"][0]) {
	if(y < _mWorldData["morning"][1]) _TimeOfDay = "dawn";
	else _TimeOfDay = "day";
    }
    else if(iTimeData < _mWorldData["twilight"][0]) _TimeOfDay = "day";
    else if(iTimeData == _mWorldData["twilight"][0]) {
	if(y < _mWorldData["twilight"][1]) _TimeOfDay = "day";
	else _TimeOfDay = "twilight";
    }
    else if(iTimeData < _mWorldData["sunset"][0]) _TimeOfDay = "twilight";
    else if(iTimeData == _mWorldData["sunset"][0]) {
	if(y < _mWorldData["sunset"][1]) _TimeOfDay = "twilight";
	else _TimeOfDay = "night";
    }
    else _TimeOfDay = "night";
    vNextChange();
}
void vNextChange() {
    int now, next, tot;
    string str;

    now = iQueryHour(time())*60 + iQueryMinutes(time());
    switch(_TimeOfDay) {
    case "night":
	str = "sunrise";
	break;
    case "dawn":
	str = "morning";
	break;
    case "day":
	str = "twilight";
	break;
    case "twilight":
	str = "sunset";
	break;
    }
    next = (60*_mWorldData[str][0]) + _mWorldData[str][1];
    if(next > now) tot = next-now;
    else {
	now = (1200)-now;
	tot = next + now;
    }
}
