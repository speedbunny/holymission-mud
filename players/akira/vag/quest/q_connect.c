inherit "room/room";
#include "/players/nylakoorub/guild/defines.h"
#define AKIRA_START "/players/akira/vag/field"

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "The 4th";
    long_desc =
    "This is one of many parts of the '4th', which portals exits to\n"+
    "different realities, times, and universes.\n"+
    "\n";

    dest_dir = ({
      "/players/akira/vag/quest/crossroads",
      "east",
      "", "west",
    });


    items = ({
    });

}

void init() {
    add_action("move_east", "east");
    add_action("check_quest", "west");
}

move_east() {
    move_object(TP, "/players/akira/vag/quest/crossroads");
    command("look", TP);
    return 1;
}



check_quest() {
    object who;
    object pl_in_quest;
    who = (QINFO)->query_who_in_area();
    if(who == 0 ) {
	who = "";
    }
    if((QINFO)->query_lock() == 2 ) 
    {
	write("The Quest is locked!\n");
	return 1;
    }
    if(who == "" ||
      who == TP->QRN ) {
    } else {
	pl_in_quest = find_living(who);
	if(!pl_in_quest  ||
	  !environment(pl_in_quest)->query_property("vag_quest") ) {
           ("/players/akira/vag/quest/finish_room.c")->update_quest();
	    (QINFO)->set_lock(0);
	    (QINFO)->set_who_in_area("");
	} else {
	}
    }
    call_out("where_to_move_player", 2 );
    return 1;
}



where_to_move_player() {
    string room;
    if((QINFO)->query_lock() == 0 &&
      this_player()->query_quests("alt_real") ) {
        room = "/players/akira/vag/quest/norm_room";
    }
    if((QINFO)->query_lock() == 1 &&
      (QINFO)->query_who_in_area() != TP->QRN ) {
        room = "/players/akira/vag/quest/alt_lock_room";
    }
    if((QINFO)->query_lock() == 1 &&
      (QINFO)->query_who_in_area() == TP->QRN ) {
	room = AKIRA_START;
    }
    if((QINFO)->query_lock() == 0 &&
      !this_player()->query_quests("alt_real") ) {
        room = "/players/akira/vag/quest/alt_room";
	(QINFO)->set_lock(1);
	(QINFO)->set_who_in_area(TP->QRN);
    }
    move_object(TP, room);
    command("look", TP);
    return 1;
}

