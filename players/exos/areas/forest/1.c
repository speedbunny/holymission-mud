inherit "room/room";

void reset(int arg) {
    if (!arg) {
	set_light(1);
	short_desc="In a deep forest";
	long_desc="\
Lost in a deep forest.\n";
	items=({ });
	dest_dir=({
	  "/players/exos/forest/edge3","west",
	  "/players/exos/forest/edge2","north",
	  "/players/exos/forest/edge1","northeast",
	  "/players/exos/forest/2","east",
	  "/players/exos/forest/7","southeast",
	  "/players/exos/forest/6","south",
	  "/players/exos/forest/5","southwest",
	});
    }
    replace_program("room/room");
    ::reset(arg);
}
