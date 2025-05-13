inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "halla";
  long_desc = 
        "You have entered another stretch of the hall.\n"
        "In this hall, however, you see a very fat, mean, and\n"
        "ugly hall monitor.\n";
  dest_dir = ({ "players/jake/floor3.c","west",
       	"players/jake/jhall.c","south",
        "players/jake/hallk.c", "north",
        "players/jake/newroom.c", "east" });
  clone_list = ({ 1, 1, "hogatha", "players/jake/monster/hogatha", 0 });

::reset();
replace_program("room/room");
}

