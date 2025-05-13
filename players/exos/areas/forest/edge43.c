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
	  "/players/exos/forest/edge42","southeast",
	  "/players/exos/forest/edge44","north",
	  "/players/exos/forest/67","south",
	  "/players/exos/forest/66","southwest",
	  "/players/exos/forest/57","west",
	  "/players/exos/forest/49","northwest",
	});
    }
    replace_program("room/room");
    ::reset(arg);
}
