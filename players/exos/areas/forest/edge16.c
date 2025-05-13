inherit "room/room";

void reset(int arg) {
    if (!arg) {
	set_light(1);
	short_desc="At the edge of a great forest";
	long_desc="\
To the south is a large forest that spreads out as far as you can see.\n\
The trees are very old, and the undergrowth is quite dense.  You do not see a\n\
way into the forest from here.\n";
	items=({ });
	dest_dir=({
	  "/players/exos/forest/edge15","northwest",
	  "/players/exos/forest/edge17","southeast",
	  "/players/exos/forest/79","north",
	  "/players/exos/forest/80","northeast",
	  "/players/exos/forest/93","east",
	});
    }
    replace_program("room/room");
    ::reset(arg);
}
