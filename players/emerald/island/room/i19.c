inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="You are almost at the top of the volcano.  The air is "+
            "unbearable hot and the gas emitted by the volcano almost "+
            "renders you unconscious.  It's hard to see through all the "+
            "dust, but you can hear a strange growling sound coming from "+
            "somewhere above you.\n";

  items=({"top","You are almost at the top of the volcano",
          "air","It is hot, foul, and full of dust",
          "volcano","A very active volcano",
          "gas","Noxious volcano gas",
          "dust","Flying ash particles from the volcano",
        });

  dest_dir=({"/players/emerald/island/room/i14", "down",
             "/players/emerald/island/room/i23", "north",
             "/players/emerald/island/room/i18", "up",
           });

  clone_list=({
    1,1,"minorva","/players/emerald/island/obj/minorva",0,
    -1,1,"tail","/players/emerald/island/obj/tail",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
