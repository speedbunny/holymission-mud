/*Room description corrected by Silas*/
inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "kbath";
  long_desc = 
        "This is Kirk's personal bathroom.\n"
        "It is a rather large bathroom, with a mirror on the north wall,\n"
        "and a shower against the east wall.\n"
        "the toilet sets against the north wall next to the sink.\n" 
        "A sink is under the mirror.\n"
        "This room is carpeted with a beautiful red carpet.\n";
  items = ({ "mirror", 
       "Upon gazing into the mirror, you see a very familiar face...your own!",
       "sink",
       "A beautiful white porcelain sink.",
       "toilet", "A mighty ferguson...Al Bundy would love it!" });
  dest_dir = ({ "players/jake/suite", "west" });

replace_program("room/room");
}


