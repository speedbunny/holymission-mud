/* walker/bridge.c -- control room for the walking castle */
/* Recode - Exos 961023 */

inherit "/room/room";

#include "walker.h"
#include "../../../obj/door.h"
object pilot;

id_stick(str) {
    return str == "joystick" || str == "stick" || str == "lever";
}

id_switch(str) {
    return str == "switch";
}

id_sign(str) {
    return str == "sign" || str == "small sign";
}

id_view(str) {
    return str == "view" || str == "the view";
}

id_windows(str) {
    return str == "windows" || str == "window";
}

id (str) {
    return id_stick(str) || id_switch(str) || id_sign(str) || id_view(str) || id_windows(str);
}

long(str) {

    if (set_light(0) == 0) {
	write("It is dark.\n");
	return;
    }

    if (id_stick(str)) {
	write("This is a big lever made of wood.\n" +
	  "It is fastened to the floor, and it looks like\n" +
	  "it could be moved in different directions.\n");
	return;
    }
    if (id_switch(str)) {
	write("This is a small switch that can be moved up and down.\n");
	if (call_other(CASTLE, "query_drawbridge_down"))
	    write("It is currently in position 'down'.\n");
	else
	    write("It is currently in position 'up'.\n");
	return;
    }
    if (id_sign(str)) {
	return read(str);
    }
    if (id_windows(str)) {
	write("The windows are big and very clear.\n" +
	  "They provide a good view of the castle's surroundings.\n");
	return;
    }
    if (id_view(str)) {
	object ob;
	int i;
	write("You look at the view through the windows.\n");
	say(this_player()->query_name() +
	  " looks at the view through the windows.\n");
	if (call_other(CASTLE, "query_airborne"))
	    write("You see nothing but clouds.\n");
	else {
	    write("    Looking through the windows you see:\n\n");
	    /* Moonchild 031192 */
	    ob=all_inventory(CASTLE->query_environment());
	    CASTLE->query_environment()->long();
	    for(i=0;i<sizeof(ob);i++) if(ob[i]->short())
		    write(ob[i]->short() + "\n");
#if 0
	    move_object(this_player(), call_other(CASTLE, "query_environment"));
	    this_player()->look(0);
	    move_object(this_player(), this_object());
#endif
	}
	return;
    }

    write("This is the bridge of the Walking Castle.\n" +
      "It is a room with big windows, built on top of the gatehouse.\n");
    if (call_other(CASTLE, "query_airborne"))
	write("Outside the windows you see nothing but clouds.\n");
    else {
	write("Outside the windows you see " +
	  call_other(CASTLE, "query_environment")->short() + ".\n");
	write("Maybe you should look at the view more carefully?\n");
    }
    write("A big wooden joystick in the floor can be moved in all directions,\n" +
      "and a small switch can be moved up and down.\n");
    write("You also notice a small brass sign on the wall.\n");
    write("    The only obvious exit is north.\n");
} /* long */

reset(flag) {
    if (!flag) {
	set_light(1);
	short_desc = "On the bridge of the walking castle";
	dest_dir = ({
	  "players/padrone/walker/walkway","north",
	});
	clone_list=({
	  1, 1, "pilot", "/players/padrone/monsters/pilot", 0,
	  2, 1, "pirate", "/players/padrone/monsters/very_ugly_pirate", 0,
	  2, 1, "pirate1", "/players/padrone/monsters/ugly_pirate", 0,
	  3, 1, "king", "/players/padrone/monsters/pirate_king", 0,
	  -2, 1, "knife", "/players/padrone/obj/knife", 0,
	  -2, 1, "helmet", "/players/padrone/obj/helmet", 0,
	  -3, 1, "cutlass", "/players/padrone/obj/cutlass", 0,
	  -3, 1, "chainmail", "/players/padrone/obj/chainmail", 0,
	  -3, 1, "helmet", "/players/padrone/obj/helmet", 0,
	});
    }
    ::reset(flag);
} /* reset */

init() {
    ::init();
    add_action("fcn_move", "move");
    add_action("flip", "flip");
    add_action("do_switch", "switch");
    add_action("read", "read");
} /* init */

fcn_move(str) {
    string what, where, player_name;
    int n;

    if(!str) return 0;
    if (this_player()->query_ghost()) { /* Moonchild 031192 */
	write("Your hands would move right through anything.\n");
	return 1;
    }

    if (id_stick(str) || id_switch(str)) {
	write("Yes, but in what direction?\n");
	return 1;
    }

    n = sscanf(str, "%s %s", what, where);
    player_name = this_player()->query_name();
    pilot=present("pilot",this_object());

    if (n == 2 && (id_stick(what) || id_switch(what))) {
	if (pilot && living(pilot)) {
	    write("You try to move the controls, but the pilot stands in the way.\n");	
	    say(player_name +
	      " tried to move the controls, but the pilot stands in the way.\n");
	    return 1;
	}
	if (what == "switch") {
	    if (where == "up" || where == "u") {
		say(player_name + " moved the small switch up.\n");
		write("You move the small switch down.\n");
		call_other(CASTLE, "set_drawbridge_down", 0);
	    }
	    else if (where == "down" || where == "d") {
		say(player_name + " moved the small switch down.\n");
		write("You move the small switch down.\n");
		call_other(CASTLE, "set_drawbridge_down", 1);
	    }
	    else
		write("What a strange direction.\n");
	    return 1;
	}

	if (where == "u") where = "up";
	if (where == "d") where = "down";
	if (where == "n") where = "north";
	if (where == "s") where = "south";
	if (where == "e") where = "east";
	if (where == "w") where = "west";
	if (where == "ne") where = "northeast";
	if (where == "nw") where = "northwest";
	if (where == "se") where = "southeast";
	if (where == "sw") where = "southwest";

	say(player_name + " moved the joystick " + where + ".\n");
	write("You move the joystick "+where+".\n");
	if (   where == "north" || where == "n"
	  || where == "south" || where == "s"
	  || where == "east" || where == "e"
	  || where == "west" || where == "w"
	  || where == "northeast" || where == "ne"
	  || where == "northwest" || where == "nw"
	  || where == "southeast" || where == "se"
	  || where == "southwest" || where == "sw"
	  || where == "out" || where == "in") { // out&in added steerpike.
	    call_other(CASTLE, "move_castle", where, 0); /* 0 = "not auto-moving" */
	}
	else if (where == "up") {
	    call_other(CASTLE, "set_airborne", 1);
	}
	else if (where == "down") {
	    call_other(CASTLE, "set_airborne", 0);
	}
	else
	    write("What a strange direction.\n");
	return 1;
    }
    else
	return 0;
} /* move */

flip(str) {
    if (str != "switch")
	return 0;
    if (call_other(CASTLE, "query_drawbridge_down"))
	return move("switch up");
    else
	return move("switch down");
} /* flip */

do_switch(str) {
    return move("switch " + str);
} /* do_switch */

read(str) {
    if (id_sign(str)) {
	say(this_player()->query_name() + " reads the small sign.\n");
	write("The small brass sign is nailed to the wall, and it says:\n");
	write("    Padrone's Walking Castle, version\n    " + WALKER_VERSION + ".\n");
	return 1;
    }
    else
	return 0;
} /* read */

pilot_is_alive() {
    pilot=present("pilot", this_object());
    return pilot && living(pilot);
}
