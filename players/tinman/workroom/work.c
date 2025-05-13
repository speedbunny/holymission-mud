inherit "/room/room";

#include "/players/tinman/workroom/defs.h"

int blocklevel, lightlevel, prooflevel;
object master;

allowed(arg) {
    return arg == "tinman" || "lan";
}
banned(arg) {
    return arg == "nobody";
}

reset(arg) {
    if(arg) return;
    set_light(1);
    lightlevel = 1;
    short_desc = "Tinman's Workroom";
    long_desc =
    "	This is the anime creation room of Tinman.  There is a big.\n" +
    "black leather couch in the middle of the room, a 60 inch TV in\n" +
    "front of the couch, state-of-the-art video equipments, and a huge \n" +
    "library of anime videos lining the walls of the room.  There is a few\n" +
    "rented videos from the video store 'Gokuraku'on the floor in front of\n" +
    "the couch.  There is a drawing and inking table on the left side of the\n" +
    "room.  This is also the headquarter of the anime club 'NEO GOKURAKU Z\n" +
    "There's a list near the doorway of the members and a large papercut\n" +
    "out of Genma Panda.\n";
    no_obvious_msg = "    Upon the north wall is a small sign.\n";

    items = ({
      "TV","huge Magnavox 60 inch, full stereo TV",
      "couch", "a black leather couch.....WHAT!!! a soda spill!!\n" +
      "alright who did it!!",
      "floor","shiny clean...don't dirty it",
      "videos","Video Girl Ai and Video Girl Len: it reads",
      "equipments","Vcr's,Laserdisc player, Mixer, and LOTs more",
      "walls","filled with anime video...Ranma,DBZ,Orange Road, BGC,etc",
      "table","a well made drawing table..It seems Tinman has begun" +
      "a drawing....of a girl in a bathing suit..(Pervert!)",
      "list","so far it contains:  Colossus (co-president)" +
      "Tsubaki (co-president)" +
      " Tinman (vice president)" +
      " William (if he ever plays)" +
      " Blaarg (bouncer)" +
      " Yakumo",
      "papercut-out","Genma!!!!!!",
      "sign", "An important-looking black sign. Read it",
    });
}

init() {
    ::init();
    add_action("go", "go");
    add_action("read", "read");
	add_action("change","change");
    add_action("block", "block");
    add_action("expel", "expel");
    add_action("bring", "bring");
    add_action("dimmer", "dimmer");
    add_action("invisible", "invis");
    add_action("dest_shad", "rshad");
    add_action("test_no","test");
    master = find_player("tinman");
    notify_me();
    filter();
    if(this_player()->query_real_name() != "colossus" ||
      this_player()->query_real_name() != "tinman")
	this_player()->vis();
}

go(arg) {
    string des;
    string str;
    switch(arg) {
    case "church":
	des = "/room/church";
	str = "the Church";
	break;
    case "monks":
	des = "/players/whisky/guild/room/c10";
	str = "the Monks Guild";
	break;
    case "sadness":
	des = "/room/south/sforst45";
	str = "the Castle of Sadness";
	break;
    case "post":
	des = "/room/post";
	str = "the Post Office";
	break;
    case "rasta":
	des = "/room/shore/p02";
	str = "Rasta City";
	break;
    case "walker":
	des = "/players/padrone/walker/ladder_room";
	str = "the Walking Castle";
	break;
    case "mom":
	des = "/players/moonchild/haunter/moor42";
	str = "the Mountains of Madness";
	break;
    case "area":
	des = "/players/tinman/area/rooms/entry";
	str = "Tian-Chui";
	break;
    case "treasury":
	des = "/players/tinman/rooms/l";
	str = "Tinman's Treasury";
	break;
    case "purgatory":
	des = "/room/purgatory";
	str = "Purgatory";
	break;
    case "guild":
	des = "/room/adv_guild";
	str = "Adventurer's Guild";
	break;
    case "ranma":
	des = "/players/blaarg/area/rooms/entry";
	str = "Ranma";
	break;
    case "blaarg":
	des = "/players/blaarg/workroom";
	str = "Blaarg's Workroom";
	break;
     case "hellfire":
	des = "/players/airborne/temple/fountain.c";
	str = "Fountain of Hellfire";
	break;
      case "plant":
	des = "/players/matt/newworld/forestb/rooms/b21.c";
	str = "Room of planting";
	break;
    default:
	des = "nowheresville";
    }
    if(des == "nowheresville") {
	write("Go where?\n");
	return 1;
    }
    write("You go to " + str + ".\n");
    TP->MOVEP("to " + str + "#" + des);
    return 1;
}

test_no(arg) {

if(!arg) 
	return notify_fail("YOu need an argument.\n\r");
printf("sdaf");
}
read(arg) {
    if(arg == "sign") {
	write("    From Tinman's Workroom you can instantly teleport to any\n");
	write("of several locations throughout the World. Currently these\n");
	write("locations are:\n\n");
	write("      church........The Main Church\n");
	write("      monks.........The Monks Guild\n");
	write("      post..........The Post Office\n");
	write("      purgatory.....Purgatory\n");
	write("      sadness.......The Castle of Sadness\n");
	write("      rasta.........Rasta City\n");
	write("      walker........Padrone's Walking Castle\n");
	write("      treasury......Tinman's Treasury\n");
	write("      mom...........The Mountains of Madness\n");
	write("      area..........Tian-Chui\n");
	write("      guild.........Adventurer's Guild\n");
	write("      ranma.........Ranma\n");
	write("      blaarg........Blaarg's Workroom\n");
	write("    To go to any location, just type 'go <location>'.\n");
	say(TP->NAME + " reads the sign.\n");
	return 1;
    }
}

change(arg) {
	int guild;
	if(!allowed(TP->RNAME)) return;
	  if(!arg) {
	write("Please enter a valid number.\n\r");
	return 1;
	}
	if(!sscanf(arg, "%d", guild)) {
	write("Change what?\n");
	return 1;
	}
	this_player()->set_guild(guild);
	return 1;
}
block(arg) {
    int level;
    if(!allowed(TP->RNAME)) return;
    if(!arg) {
	write("Currently, level " + blocklevel +
	  " and below are blocked out.\n");
	return 1;
    }
    if(!sscanf(arg, "%d", level)) {
	write("Block what?\n");
	return 1;
    }
    else if(level >= 0 && level <= 1000) {
	write("Now players level " + arg + " and below are blocked out.\n");
	say(TP->NAME + " sets the block level to " + arg + ".\n");
	blocklevel = level;
	return 1;
    }
    write("Block what?\n");
    return 1;
}

expel(arg) {
    object target;
    target = present(arg);
    if(!allowed(TP->RNAME)) return;
    if(target) {
	write("You expel " + target->NAME + " from the Workroom.\n");
	TELL(target, "\nYou are expelled from Tinman's Workroom!\n\n");
	MOVE(target, "/room/church");
	say(target->NAME + " is expelled from Tinman's Workroom.\n");
	return 1;
    }
    write("Expel whom?\n");
    return 1;
}

bring(arg) {
    object target, troom;
    target = find_player(arg);
    if(!allowed(TP->RNAME)) return;
    if(target) {
	troom = environment(target);
	write("You bring " + target->NAME + " into your Workroom.\n");
	say(TP->NAME + " brings " + target->NAME +
	  " into the Workroom.\n");
	TELL(target, "You are teleported to Tinman's Workroom.\n");
	MOVE(target, TO);
	TELLR(troom, target->NAME + " vanishes.\n");
	return 1;
    }
    write("Bring whom?\n");
    return 1;
}

dimmer(arg) {
    int brightness;
    if(!allowed(TP->RNAME)) return;
    if(arg) {
	if(sscanf(arg, "%d", brightness)) {
	    if(brightness != lightlevel) {
		set_light(brightness - lightlevel);
		write("You set the light level to " + brightness + ".\n");
		say(TP->NAME + " adjusts the dimmer.\n");
		if(brightness < lightlevel) say("The Workroom gets darker.\n");
		else say("The Workroom gets brighter.\n");
		lightlevel = brightness;
		return 1;
	    }
	    write("The light is already set to " + lightlevel + ".\n");
	    return 1;
	}
    }
    write("The current light level is " + lightlevel + ".\n");
    return 1;
}

invisible() {
    if(TP->RNAME != "tinman") {
	write("You cannot hide from Tinman in his very own Workroom!\n");
	return 1;
    }
}

dest_shad() {
    object shad;
    if(!allowed(TP->RNAME)) return;
    shad = shadow(TP, 0);
    if(shad) {
	destruct(shad);
	write("Shadow destructed.\n");
	return 1;
    }
    write("No shadow detected.\n");
    return 1;
}

notify_me() {
    if(!interactive(TP) || (TP->RNAME == "tinman")) return 1;
    if(master)
	TELL(master, CAP(TP->RNAME) + " has entered your Workroom.\n");
    return 1;
}

filter() {
    if(TP->LEVEL <= blocklevel &&
      this_player()->query_real_name() != "tinman" &&
      this_player()->query_real_name() != "colossus"){
	write("\nGenma the Panda throws you out of Tinman's Workroom!\n\n");
	TP->MOVEP("unintentionally to the Church#room/church");
	if(master) 
	    TELL(master, TP->NAME + " tried to enter your Workroom.\n");
	return 1;
    }
}
