#define WIZ "/players/jake/"

inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "Lounge";
  long_desc ="You have entered the lounge.\n"
        "There are couches and chairs here.\n"
        "A carpet lies on the floor.\n";
  items = ({ "wall","A standard mud wall",
      "couch","A comfortable red couch",
      "chair","A wooden chair" });
  dest_dir = ({ WIZ+"hall","north",
     	WIZ+"astair","south" });
  clone_list = ({ 1, 2, "student", "players/jake/monster/student", 0, });

::reset();
replace_program("room/room");
}

