inherit "room/room";
#include "/players/nylakoorub/guild/defines.h"

/* This the room were Emit talks to you after defeating Thanos...  */



reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc = "the 4th";
    long_desc =
    "You have entered another part the 4th, all seems ok....\n"+
    "\n"+
    "\n"+
    "\n";

    dest_dir = ({
      "/players/nylakoorub/4th/q_connect", "east",
    });

    property = ({ "vag_quest", "no_teleport" });


    call_out("start_questend", 3);

}


void init() {
    add_action("reset_quest", "east");
}


start_questend() {
    write("You start to wake up, but you don't know were you \n"+
      "are now..... so, you open your eyes and look around.\n");
    call_out("look_around", 2);
    return 1;
}

look_around() {
    command("look", TP);
    call_out("pre_emit1", 3);
    return 1;
}

pre_emit1() {
    write("You start womdering if reality has gone back to normal.\n");
    call_out("pre_emit2", 3);
    return 1;
}

pre_emit2() {
    write("A portal opens in front of you and a figure slowly \n"+
      "emerges from it and the portal closes behind him.\n");
    call_out("emit_reappears", 3);
    return 1;
}



emit_reappears() {
    write("It is Emit Ecaps, and he is alright.\n");
    move_object(
      clone_object("/players/nylakoorub/guild/obj/npc/emit"),
      this_object());
    call_out("emit_speak1", 5);
    return 1;
}


emit_speak1() {
    write(
      "Emit says: "+
      "Ah.. "+
      capitalize(TP->QRN)+
      " you have done it, you have destoryed Thanos \n"+
      "and saved this reality, including my life.\n");
    call_out("emit_speak2", 5);
    return 1;
}

emit_speak2() {
    write(
      "Emit says: "+
      "Once you have smashed the clock, its power over the alternate reality \n"+
      "was also destoryed too.\n");
    call_out("emit_speak3", 5);
    return 1;
}


emit_speak3() {
    write("Emit says: "+
      "Your deeds for saving the 4th from Thanos, \n"+
      "will not be forgetten.\n");
    call_out("emit_speak4", 2);
    return 1;
}

emit_speak4() {
    write("Emit says: "+
      "I must say farewell, My Friend... \n"+
      "I will see in time!\n");
    call_out("emit_leaves", 2);
    return 1;
}

emit_leaves() {
    write("Emit vanishes again to travel the lanes of "+
      "Time and Space.\n");
    destruct(present("emit", this_object()));
    if(this_player()->query_immortal()) {
    } else {
	this_player()->set_quest("alt_real");
    }
    return 1;
}


reset_quest() {
    if(!this_player()->query_quests("alt_quest")) {
	return 1;
    } else {
	(QINFO)->set_lock(0);
	(QINFO)->set_who_in_area("");
	move_object(TP,
	  "/players/nylakoorub/4th/q_connect");
	command("look", TP);
	call_out("update_quest", 1);
	return 1;
    }
}


update_quest() {
    string *dir;
    string path;
    int i,j;
    object master;
    path = "/players/akira/vag/";
    dir = get_dir(path+".");
    j = sizeof(dir);
    for(i=0;i<j;i++) {
	if(master = find_object(path+dir[i])) {
	    destruct(master);
	}
    }
    destruct(find_object("/players/nylakoorub/4th/"+
	"quest/finish_room"));

    return 1;
}






