inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "basej";
  long_desc = 
        "You are now in the basement.\n"
        "It is very gloomy down here.\n"
        "You see many cobwebs above, and a few rats on the floor.\n";
  items = ({ "cobwebs", "The cobwebs stick the the ceiling above you",
	"ceiling", "It is filled with cobwebs" });
  dest_dir = ({ "players/jake/spiderroom.c","east",
       	"players/jake/basea.c","south",
        "players/jake/westbase.c","west",
        "players/jake/staire.c","north" });
  clone_list = ({ 1, 3, "rat", "players/jake/monster/rat", 0 });

::reset();
replace_program("room/room");
}
