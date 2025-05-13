/* 961119 Exos:  Added entrance to bard guild room */

inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="A large open plain";

    long_desc="A large open plain.\n";

    dest_dir=({
      "room/plane7", "north",
      "room/plane2", "east",
    });

    ::reset(arg);
}

init(arg) {
    ::init(arg);
    if(this_player()->query_real_guild()==6) {
	write("You notice a hidden Harper rune which reads: down .\n");
	add_action("_bard","down");
    }
    if(this_player()->query_immortal()) {
	write("The bard guild board room is DOWN from here.\n");
	add_action("_bard","down");
    }
}

_bard(arg) {
    if(arg) return 0;
    write("You enter the secret Harper room.\n");
  this_player()->move_player("mysteriously#players/turbo/guild/rooms/bard1");
    return 1;
}
