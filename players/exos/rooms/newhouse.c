inherit "room/room";
#include "lw.h"
#include "defs.h"
int tabloc,ropefound,find;
object clomb,wire;

reset(arg) {
    ::reset(arg);
    if(!arg) {
	short_desc="Inside house";
	long_desc="You're inside a small, wooden house. The interior is also made "
	+ "of wood. You can see a chair, a mat and a table"
	+ "@@extralong@@.\n";
	smell="Of course, the whole place smells of old wood.";
	set_light(1);
	dest_dir=({
	  "players/kelly/rooms/violens","west",
	});
	items=({"chair","It seems to be nailed to the floor",
	  "table","@@table@@",
	  "mat","@@mat@@",
	  "rope","@@rope@@",
	  "opening","@@opening@@",
	  "ceiling","It is also made of wood",
	  "nails","The only thing made of iron around, I guess",
	  "wood","Generally oak",
	  "interior","Well, the wood will protect you from the rain..",
	  "house","You wouldn't want to live here"});
    }
    switch(ropefound) {
    case 1: 
	ropefound=0;
	break;
    case 2:
	TLRM(TO,"The opening in the ceiling slams shut.\n");
	ropefound=0;
	break;
    }
    find=0;
}

extralong() {
    if(ropefound==2) return ". There is a strange opening in the ceiling";
    return "";
}

table() {
    if(!tabloc) {
	return "The table is standing on the mat in the middle of the room. It "
	+ "used to be nailed to the floor, but the nails are gone"+climbon();
    }
    return "The table is standing against the wall"+climbon();
}

static climbon() {
    if((clomb)&&(present(clomb,this_object()))) {
	return ". "+clomb->query_name()+" is standing on the table";
    }
    return "";
}

mat() {
    if(!tabloc) return "The table is standing on the mat. The mat is partly "
	+ "nailed to the floor";
    return "The mat is lying in the middle of the room. The mat is partly "
    + "nailed to the floor";
}

rope() {
    if(!ropefound) return "There is no rope here";
    return "You seem to be able to pull it";
}

opening() {
    if(ropefound!=2) return "There is no opening here";
    return "It's too dark to look inside";
}

init() {
    ::init();
    add_action("move_it","move");
    add_action("move_it","push");
    add_action("search_it","search");
    add_action("pull_it","pull");
    add_action("climb_it","climb");
    add_action("west_it","west");
    add_action("get_it","get");
    add_action("get_it","take");
    add_action("lift_it","lift");
    add_action("tie_it","tie");
    add_action("tie_it","use");
    add_action("enter_it","enter");
    add_action("tie_it","up");
}

enter_it(str) {
    if((!str)||(str!="opening")) {
	FAIL("Enter what?\n");
	return 0;
    }
    if(ropefound!=2) {
	FAIL("Enter what?\n");
	return 0;
    }
    ME("You can't enter the opening because it is too small.\n");
    say(TPN+" tries to reach up and enter the opening, but fails.\n");
    return 1;
}

tie_it(str) {
    FAIL("I think you're thinking along the wrong lines...\n");
    return 0;
}

lift_it(str) {
    if((!str)||(str!="mat")) {
	FAIL("Lift what?\n");
	return 0;
    }
    if(!tabloc) {
	ME("But there is a table standing on it!\n");
	return 1;
    }
    say(TPN+" lifts the mat.\n");
    ME("You notice a thin rope lying under it.\n");
    if(!ropefound) ropefound=1;
    return 1;
}

get_it(str) {
    if(!str) {
	FAIL("Take what?\n");
	return 0;
    }
    if(str=="mat") {
	FAIL("You can't take that, its partially nailed to the floor.\n");
	return 0;
    }
    if(str=="rope") {
	if(!ropefound) {
	    FAIL("Take what?\n");
	    return 0;
	}
	FAIL("You can't take that, because it is attached to something.\n");
	return 0;
    }
    if(str!="table") {
	FAIL("You can't take that, because it is too heavy.\n");
	return 0;
    }
}

climb_it(str) {
    if(!str) {
	FAIL("Climb what?\n");
	return 0;
    }
    if((str=="off")||(str=="down")) {
	if(this_player()!=clomb) {
	    FAIL("But you are not standing on the table.\n");
	    return 0;
	}
	clomb=0;
	ME("You climb down again.\n");
	say(TPN+" climbs down again.\n");
	return 1;
    }
    if(str=="rope") {
	if(ropefound) {
	    ME("But the rope is lying on the floor!\n");
	    say(TPN+" fails to climb the rope.\n");
	    return 1;
	}
    } 
    if(str!="table") {
	FAIL("Climb what?\n");
	return 0;
    }
    if(clomb && HERE(clomb,TO)) {
	FAIL("Someone is already standing on the table.\n");
	return 0;
    }
    clomb=TP;
    ME("You climb on the table.\n");
    say(TPN+" climbs on the table.\n");
    return 1;
}

west_it() {
    if(TP==clomb) {
	ME("You have to climb off the table before you can go west.\n");
	return 1;
    }
}

move_it(str) {
    if(!str) {
	FAIL("Move what?\n");
	return 0;
    }
    if(str=="mat") {
	ME("It is partially nailed to the floor, you cannot move it.\n");
	say(TPN+" tries to move the mat, but it is partially nailed to the floor.\n");
	return 1;
    }
    if(str=="rope") {
	ME("You move the rope a little.\n");
	say(TPN+" moves a rope a little.\n");
	return 1;
    }
    if(str!="table") {
	FAIL("Move what?\n");
	return 0;
    }
    if(this_player()==clomb) {
	notify_fail("You can't move the table while you're standing on it!\n");
	return 0;
    }
    if((clomb)&&(present(clomb,this_object()))) {
	notify_fail("Someone is standing on the table!\n");
	return 0;
    }
    if(tabloc) {
	write("You push the table to the middle of the room.\n");
	say(TPN+" pushes the table to the middle of the room.\n");
	tabloc=0;
	return 1;
    }
    write("You push the table to the wall.\n");
    say(TPN+" pushes the table to the wall.\n");
    tabloc=1;
    return 1;
}

search_it(str) {
    if(!str) return;
    if(str=="chair") {
	if(wire) return;
	wire=clone_object("obj/weapon");
	wire->set_name("wire");
	wire->set_short("A short wire");
	wire->set_long("Very ineffective when used as weapon. Made of copper.\n");
	wire->set_weight(1);
	wire->set_class(1);
	wire->set_value(25);
	move_object(wire,this_object());
	write("You search the chair and a piece of wire falls to the ground.\n");
	say(TPN+" searches a chair.\n");
	return 1;
    }
    if(str=="opening") {
	if(ropefound!=2) return;
	if(TP->QSZ<4) {
	    if(TP!=clomb) {
		write("You're too small to reach the opening!\n");
		say(TPN+" tries to reach for the opening, but is too small.\n");
		return 1;
	    }
	    if(tabloc) {
		write(lw("Even though you're on the table, you still can't reach the "
		    + "opening, because the table is standing against the wall.\n"));
		say(lw(this_player()->query_name()+" makes a very dangerous move on "
		    + "the table, and almost falls off.\n"));
		return 1;
	    }
	    say(this_player()->query_name()+" searches the hole in the ceiling.\n");
	    find_treasure();
	    return 1;
	}
	if(wire) {
	    if((present(wire,this_player()))&&(wire->query_wielded())) {
		say(lw(this_player()->query_name()
		    + " searches the hole in the ceiling with a wire.\n"));
		find_treasure();
		return 1;
	    }
	}
	write("Your hands are too big to reach inside the opening!\n");
	return 1;
    }
    if(str!="mat") return;
    if(!tabloc) {
	write("But there is a table standing on it!\n");
	say(lw(this_player()->query_name()+" tries to search the mat, but is "
	    + "hindered by the table standing on it.\n"));
	return 1;
    }
    say(this_player()->query_name()+" searches the mat.\n");
    write("Something seems to be lying under it. Maybe you should lift it.\n");
    return 1;
}

find_treasure() {
    object treasure;

    if(find) {
	write("You search the hole in the ceiling, but you find nothing...\n");
	return;
    }
    find=1;
    if(present("locket",this_player())) {
	write("You search and find some coins...\n");
	this_player()->add_money(50+random(50));
	return;
    }
    write("You search and you find a locket!\n");
    treasure=clone_object("players/exos/objects/locket");
    transfer(treasure,this_player());
    /* secret_xp(); Tatsuo 3-19-95:  secret_xp removed from obj dir */
    return;
}

pull_it(str) {
    if((!str)||(str!="rope")) {
	notify_fail("Pull what?\n");
	return 0;
    }
    if(!ropefound) {
	notify_fail("There is no rope here.\n");
	return 0;
    }
    if(ropefound!=1) {
	write("You pull the rope but nothing happens.\n");
	say(this_player()->query_name()+" pulls a rope but nothing happens.\n");
	return 1;
    }
    write("You pull the rope and a secret opening opens in the ceiling.\n");
    say(lw(this_player()->query_name()
	+ " pulls some rope and a secret opening opens in the ceiling.\n"));
    ropefound=2;
    return 1;
}







