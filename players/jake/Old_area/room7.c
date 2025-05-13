/*Room description corrected by Silas*/
inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "room7";
  long_desc = 
        "This is an incredibly clean room.  It looks like it as if it has just been\n"
        "dusted. Everything is white in here.\n";
  dest_dir = ({ "players/jake/2halld", "east" });

replace_program("room/room");
}                            
