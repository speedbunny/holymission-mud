inherit "room/room";

void reset(int arg) {
  if(arg)
    return;
  set_light(1);
  short_desc="Forest";
  long_desc="You are in part of a dimly lit forest - tall trees loom all around you.\n" +
	  "Trails lead north and east, and a path leads south towards a dark castle.\n";
  dest_dir=({ "room/south/sforst37", "north",
	"room/south/sforst44", "east",
	"players/patience/smilequest/guardroom", "south" });
  replace_program("room/room");
}
inherit "room/room";

void reset(int arg) {
  if(arg)
    return;
  set_light(1);
  short_desc="Forest";
  long_desc="You are in part of a dimly lit forest - tall trees loom all around you.\n" +
	  "Trails lead north and east, and a path leads south towards a dark castle.\n";
  dest_dir=({ "room/south/sforst37", "north",
	"room/south/sforst44", "east",
	"players/patience/smilequest/guardroom", "south" });
  replace_program("room/room");
}
