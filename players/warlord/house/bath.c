#define TPN this_player()->query_name()
inherit"room/room";
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="Powder room.\n";
    long_desc=
    "You are in the powder room.\n"+
    "To the north you can see a window with a nice view. On the east wall is\n"+
    "the toilet and sink. On the west wall is the shower.\n";
    items=({
      "window","From here you get a nice view of the backyard",
      "view","From here you get a nice view of the backyard",
      "toilet","You an ordinary toilet. Do you have to use it?",
      "sink","Here is where you can wash your hands and face",
      "shower","Here is where you can take a shower",
    });
    dest_dir=({
      "players/warlord/house/hallway","south",
    });
}
init() {
    ::init();
    add_action("flush","flush");
    add_action("wash","wash");
    add_action("take","take");
    add_action("use","use");
    add_action("dry","dry");
}
use(str) {
    if(!str) {
	write("What do you want to use?\n");
	return 1;
    }
    if((str=="the toilet") || (str=="toilet")) {
	write("You take off your pants and relieve yourself. Ahhh the feels good. Don't forget to flush the toilet and wash your hands.\n");
	say(this_player()->query_name()+" is going to the bathroom. Do you enjoy watching?\n");
	return 1;
    }
    else {
	write("You can't use the "+str+".\n");
	return 1;
    }
}
dry(str) {
    if(!str) {
	write("What do you want to dry.\n");
	return 1;
    }
    write("You dry your "+str+" well.\n");
    say(this_player()->query_name()+" dries their " +str+".\n");
    return 1;
}
take(str) {
    if(!str) {
	write("What do you want to take? A shower perhaps.\n");
	return 1;
    }
    if((str=="shower")||(str=="a shower")) {
	write(
	  "You undress yourself and turn on the water. You get into the shower\n"+
	  "and start washing yourself. You shampoo your hair good. You then\n"+
	  "rinse off your body good and get out of the tub. Maybe you should\n"+
	  "dry your body?\n");
	say(TPN+" takes a shower. Should you be watching?\n");
	return 1;
    }
    else {
	write("You can't take that. You can only take a shower here.\n");
	return 1;
    }}
flush(str) {
    if(!str) {
	write("What do you want to flush? The toilet perhaps?\n");
	return 1;
    }
    if ((str=="the toilet")||(str=="toilet")) {
	write("You flush the toilet. Good move don't want to stink up the bathroom.\n");
	say(TPN+" flushes the toilet. Were you watching the whole time?\n");
	return 1;
    }
    else {
	write("You can't flush that!\n");
	return 1;
    }
}
wash(str) {
    if(!str) {
	write("What do you want to wash? Your hands or face perhaps.\n");
	return 1;
    }
    if ((str=="face")||(str=="hands")) {
	write("You soap up a wash and start washing the dirt off your "+str+".\n"+
	  "You then rinse your "+str+" really well. Maybe you should dry your "+str+".\n");
	say(TPN+" washes their "+str+".\n");
	return 1;
    }
    else {
	write("You can't wash your "+str+". It won't reach the sink.\n");
	return 1;
    }}
