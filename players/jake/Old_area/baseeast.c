inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "baseeast";
  long_desc = 
        "Ths is another of Jake's storage rooms.\n"
        "Nothing is in here. [yet]\n";
  dest_dir = ({ "players/jake/basea.c", "west" });

replace_program("room/room");
}

