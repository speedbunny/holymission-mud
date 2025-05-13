/* 
* Vagabond Omni
*
*
*/


#include "/players/nylakoorub/guild/obj/omni/define.h"

#define VERSION  5

int omnipower,omni_version_number;
int count;
int timezone;
int year,second,min,hour,date;
string day, month;
string tick_status;
string light_status;




mixed query_auto_load() {
    return "/players/nylakoorub/guild/obj/omni/lib/omni:"+
    omnipower+"#"+omni_version_number;
}

void init_arg(mixed arg) {
    sscanf(arg, "%d#%d",omnipower,omni_version_number);
}

int id(string str) {
    return str == item || str == "vagobject" ||
    str == "vag"+item ;
}




string short() {
    switch((int)environment()->query_level()) {
    case 1..5:
	return C("iron")+" "+C(item); break;
    case 6..10:
	return C("copper")+" "+C(item); break;
    case 11..14:
	return C("silver")+" "+C(item); break;
    case 15..19:
	return C("electrum")+" "+C(item); break;
    case 20..29:
	return C("gold")+" "+C(item); break;
    default:
	if(environment()->query_legend_level() < 1) {
	    return C("platinum")+" "+
	    C(item); break;
	} 
	else { return capitalize("orichalcum")+" "+
	    C(item); break;
	}
    }
}


void long(){ 
    write(
      "     The "+C(item)+" is a specially designed time piece.  It\n"+
      "was designed by the Elder Timelords of the 4th.  They crafted\n"+
      "it to harness unique powers of Time.  It is small enough to fit\n"+
      "in the palm of your hand.  Attach to it is a small chain to \n"+
      "prevent you from losing it.  Type 'Omni help' for more info.  \n"+
      "\n");
}


drop() { return 1; }
remove() { return 1; }
get() { return 1; }

query_max_omni() {
    return MAXOMNIPOWER;
}



add_omni(arg) {
    omnipower += arg;
    return 1;
}

minus_omni(arg) {
    omnipower -= arg;
    return 1;
}

set_omni_light(arg) {
    set_light(arg);
}

query_light_status() {
    return light_status;
}

set_light_status(arg) {
    light_status = arg;
}

set_tick(arg) {
    tick_status = arg;
}

query_tick() {
    return tick_status;
}

set_timezone(arg) {
    timezone = arg;
}

query_timezone() {
    return timezone;
}



void init() {
    if(!light_status) light_status = "off";
    if(!tick_status) tick_status = "on";
    if(omnipower > query_max_omni() ) {
	omnipower = this_object()->query_max_omni();
    }
    omni_version_number = VERSION;

    add_action("omni_filter", "omni");

    call_out("reset_timer", 0);
}

query_tick_status() {
    return tick_status;
}


omni_filter(arg) {
    (OMNI_CMDS +
      "filter.c")->omni_filter(arg);
    return 1;
}



reset_timer() {
    int timediff;
    sscanf(ctime(time()),
      "%s %s %d %d:%d:%d %d",
      day, month, date, hour, min, second, year);
    timediff = 60 - second;
    tell_object(environment(),
      "Setting Omni with Mud Time... Please wait.....\n");
    call_out("reset_done", timediff);
    return 1;
}


reset_done() {
    tell_object(environment(),
      "Done.\n");
    set_heart_beat(1);
    return 1;
}

void heart_beat() {
    string am_pm;
    int omnidiff;
    omnidiff = this_object()->query_max_omni() - omnipower;
    am_pm = "";
    sscanf(ctime(time()),
      "%s %s %d %d:%d:%d %d",
      day, month, date, hour, min, second, year);
    /* for debugging
    tell_object(environment(),
      hour+"h "+min+"m "+
      second+" "+omnidiff+
      "\n");
    */
    switch(hour) {
    case 00:
	am_pm = "AM";
	hour = 12;
	break;
    case 01..11:
	am_pm = "AM";
	break;
    case 12:
	am_pm = "PM";
	break;
    case 13..23:
	am_pm = "PM";
	hour = hour-12;
	break;
    default:
	am_pm = "N/A";
	break;
    }

    switch(second) {
    case 00: case 01:
	switch(min) {
	case 00:
	    if(omnidiff <= HOUR_BONUS ) {
		omnipower += omnidiff;
	    } else {
		omnipower += HOUR_BONUS;
	    }
	    tell_object(environment(),
	      "Your Omni strikes "+
	      hour+
	      " O'clock "+
	      am_pm+
	      ". BONG!"+
	      "\n");
	    break;
	case 15: case 30: case 45:
	    if(omnidiff <= BONUS ) {
		omnipower += omnidiff;
	    } else {
		omnipower += BONUS;
	    }
	    tell_object(environment(),
	      "Your Omni strikes "+
	      hour+":"+min+" "+
	      am_pm+
	      "\n");
	    break;
	default:
	    if(tick_status == "off" ) {
	    } else {
		tell_object(environment(),
		  "Tick!\n");
	    }
	    if(omnipower >= this_object()->query_max_omni() ) {
	    } else {
		omnipower += 1;
	    }
	    break;
	}
	break;
    default: break;
    }



}



query_ver_num() { return VERSION; }
query_omni() { return omnipower; }


