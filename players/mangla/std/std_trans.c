#include "/players/mangla/defs.h"
#include "/obj/lw.h"

int time_in_trans,time_at_stop,flying,water;
int at_stop,STARTED;
string *room_list,long_desc,short_desc,alias;
string in_long,in_leave,out_leave,in_enter,out_enter;
object temp;
int roomno,no_rooms,passengers;

// prototypes
int _trans1();
int _trans2();

int no_clean_up() {
    return 1;
}

int id(string str) {
    return str==alias || str==short_desc;
}

set_short(string str) {
    if(!str) return 0;
    short_desc = str;
    return 1;
}

int set_alias(string str) {
    if(!str) {
        alias = short_desc;
        return 0;
    }
    alias = str;
    return 1;
}

int set_long(string str) {
    if(!str) return 0;
    long_desc = str;
    return 1;
}

int set_inside_long(string str) {
    if(!str) return 0;
    in_long = str;
    return 1;
}

int set_inside_enter(string str) {
    if(!str) return 0;
    in_enter = str;
    return 1;
}

int set_outside_enter(string str) {
    if(!str) return 0;
    out_enter = str;
    return 1;
}

int set_outside_leave(string str) {
    if(!str) return 0;
    out_leave = str;
    return 1;
}

int set_inside_leave(string str) {
    if(!str) return 0;
    in_leave = str;
    return 1;
}

string query_name() {
    return short_desc;
}

string short() {
    return short_desc;
}

int long() {
    if(ENV(TP) == TO) {
      if(at_stop) {
      printf("\n");
      printf("On the outside of the craft you can see:\n");
      ENV()->long();
      }
      printf("\n\nOn the inside you see:\n");
      if(in_long) writelw(in_long);
      else {
        printf("You can see around you a plush cabin.\n");
        printf("Rest a bit and enjoy the ride.\n");
      }
      printf("\n");
      return 1;
    }
    writelw(long_desc);
    return 1;
}

int set_rooms(int numb,string *rooms) {
    if(numb<2 || sizeof(rooms) != numb) return 0;
    room_list = rooms;
    no_rooms = numb;
    return numb;
}

int set_flying(int arg) {
    flying = arg;
    return flying;
}

int set_water(int arg) {
    water = arg;
    return water;
}

int trans_time(int arg) {
    if(!arg) return 0;
    time_in_trans = arg;
    return time_in_trans;
}

int stop_time(int arg) {
    if(!arg) return 0;
    time_at_stop = arg;
    return time_at_stop;
}

int _board(string str) {

    if((str==short_desc || str==alias) && at_stop) {
        printf("You climb aboard this ");
        if(flying) printf("vehicle of flight.\n");
        else if(water) printf("vessel of the water.\n");
        else printf("land bound carriage.\n");
        if(!TP->query_invis()) {
            if(in_enter) TELLR(TO,TP->NAME+" "+in_enter);
            else
            TELLR(TO,TP->NAME+" climbs aboard the "+short_desc+".\n");
            MOVE(TP,TO);
            if(out_enter) say(TP->NAME+" "+out_enter,TP,TO);
            else
            say(TP->NAME+" climbs aboard the "+short_desc+".\n",TP,TO);
        }
        else MOVE(TP,TO);
        passengers += 1;
    }
    return 1;
}

int _disembark() {

    if(!at_stop) {
        notify_fail("You may not disembark while in transit.\n");
        return 0;
    }
    else {
        if(!TP->query_invis()) {
            if(out_leave) say(TP->NAME+" "+out_leave,TO,TP);
            else
            say(TP->NAME+" disembarks from the "+short_desc+".\n",TO,TP);
            MOVE(TP,ENV(TO));
            if(in_leave) TELLR(TO,TP->NAME+" "+in_leave);
            else
            TELLR(TO,TP->NAME+" disembarks for adventure.\n");
        }
        MOVE(TP,ENV(TO));
        passengers -= 1;
        printf("You leave for more excellent adventures.\n");
    }
    return 1;
}

int query_passengers() {
    return passengers;   
}    

int _trans2() {
    at_stop = 1;
    TELLR(room_list[roomno],short_desc+" arrives.\n");
    MOVE(TO,room_list[roomno]);
    roomno++;
    if(roomno == no_rooms) roomno = 0;
    TELLR(TO,"We have arrived at "+ENV()->short()+".\n");
    call_out("_trans1",time_at_stop);
    return 1;
}

int _trans1() {
    at_stop = 0;
    temp = ENV();
    MOVE(TO,"room/troom");
    TELLR(TO,"Now departing for "+room_list[roomno]->short()+".\n");
    TELLR(temp,"The "+short_desc+" leaves for its next stop.\n");
    call_out("_trans2",time_in_trans);
    return 1;
}

reset(int arg) {

    if(arg) return;
    passengers = 0;
    at_stop = 1;
    roomno = 0;
    STARTED = 0;
/*
TELL(find_living("mangla"),"Time at stop is: "+time_at_stop+"\n");
TELL(find_living("mangla"),"Time in trans: "+time_in_trans+"\n");
*/
    return;
}

init() {
    add_action("_disembark","leave");
    add_action("_disembark","disembark");
    add_action("_disembark","dismount");
    add_action("_disembark","exit");
    add_action("_board","board");
    add_action("_board","mount");
    add_action("_board","enter");
    if(STARTED) return;
    if(find_call_out("_trans1") > -1) {
        remove_call_out("_trans1");
    }
    if(find_call_out("_trans2") > -1) {
        remove_call_out("_trans2");
    }
    call_out("_trans1",time_at_stop,0);
    STARTED = 1;
}

