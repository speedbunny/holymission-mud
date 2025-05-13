#define WARLORD this_player()

inherit "room/room";
inherit "/players/warlord/dev/util";
int shield;

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "work";
    no_castle_flag = 0;
    long_desc = 
    "This is Warlord's workroom. Do you belong here?\n";
    dest_dir = 
    ({
      "/room/church", "church",
      "/players/kitty/workroom", "kit",
    });
}
init() {
    ::init();
    add_action("set_shield", "shield");
    add_action("time_fct","time");
    check();
}
set_shield(str) {
    if(this_player()->query_real_name() != "warlord") {return;}
    if(!str) {
	write("Shield is currently set to "+shield+".\n");
	return 1;
    }
    if(str == "on") {
	write("You set the shield on.\n");
	say("You feel a warm feeling surround the room.\n");
	shield = 1;
	return 1;
    }
    if(str == "off") {
	write("You snaps your fingers and the shield shut off.\n");
	say("The bright globe surrounding the room disappears.\n");
	shield = 0;
	return 1;
    }
    write("Set shield to what?\n");
    return 1;
}
check() {
    if(shield && this_player()->query_name() != "warlord") {
	write("Your failed to attempt to break into Warlord's workroom!\n");
	say(this_player()->query_name()+" tries to enter but is kicked out.\n");
	move_object(this_player(), "/room/void");
    }
    return 1;
}

int time_fct(){
    int time_is;
int year, day, hour, minute, sec;
    time_is=time();
    write("Time is: "+time_is+"\n");
    return 1;
}
