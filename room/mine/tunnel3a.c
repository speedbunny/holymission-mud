inherit "room/room";
/* you need to inherit a base file where functions are declared */

int rope;  /* Let the file know that your using the VAR rope for a number */

reset( arg ) {
    if ( arg ) return;

    rope = 0;
    /* this means that is there are objects in room when a reset comes
    just ignore this room. If not update the room */

    short_desc="Tunnel."; /* If players uses brief mode */
    long_desc =
    "As you look around this tunnel you seea big hole in the floor and on\n\
the wall you can see some kind of iron ring. It seems you can walk\n\
right past the hole. The tunnel leads north and south from here.\n";

    /* Description when player does a look or enters room
    in verbose mode */

    dest_dir= ({
      "/room/mine/tunnel2","south",
      "/room/mine/tunnel4","north",
    });

    /* Directions are done in the format 
    Filename of room, direction to that filename */

    items= ({
      "ring","You see a sturdy ring with a rope tied to it",
      "hole","You see a deep dark hole. You may wanna climb down",
    });
}

init() {
    ::init();
    add_action("tie","tie");
    add_action("untie","untie");
    add_action("down","down");
    add_action("down","climb");
}
down() {
    if (!rope) {
	write("You would fall down the hole and possibly hurt yourself.\n");
	return 1;
    }
    this_player()->move_player("down#room/mine/tunnel8");
    return 1;
}

tie(str)
{
    if (( str=="rope to ring") ||( str=="rope on ring")) {
	write("You tie the rope onto the ring tightly");
	rope = 1;
	return 1;
    }
    write("Tie what where?\n");
    return 1;
}


untie(str) {
    if (str == "rope" || str=="rope from ring" ) {
	rope = 0;
	return 1;
    }
    return 0;
}

query_rope() {
    return rope;
}
