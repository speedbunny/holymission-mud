inherit "room/room";

void reset(int arg) {
    if (!arg) {
	set_light(1);
	short_desc="In a deep forest";
	long_desc="\
Lost in a deep forest.\n";
	items=({ });
	dest_dir=({
	  "/players/exos/forest/1","west",
	  "/players/exos/forest/edge2","northwest",
	  "/players/exos/forest/edge1","north",
	  "/players/exos/forest/edge54","northeast",
	  "/players/exos/forest/3","east",
	  "/players/exos/forest/8","southeast",
	  "/players/exos/forest/7","south",
	  "/players/exos/forest/6","southwest",
	});
    }
    replace_program("room/room");
    ::reset(arg);
}
