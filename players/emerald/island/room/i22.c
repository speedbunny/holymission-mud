#define TP this_player()
#define TPN TP->query_name()
inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="You are standing on a plateau near the top of the volcano.  "+
            "The air is very hot and the gas coming from the volcano "+
            "makes you nearly unconscious.  There are rather conspicuous "+
            "bushes to the northeast.  To the north is the entrance of a "+
            "large cave.  To the west, the path leads down to the foot "+
            "of the volcano.\n";

  items=({"path","A black stony path",
          "bushes","They are only about four feet high, and could be passed",
          "plateau","This is a plateau near the top of the volcano",
          "volcano","You are on a plateau near the top of a volcano",
          "air","It is quite hot and carries a foul reek",
          "entrance","It is a large entrance into a dark cave",
          "foot","The foot of the volcano is far below you",
        });

  dest_dir=({"/players/emerald/island/room/i23","east",
             "/players/emerald/island/room/i21","down",
             "/players/emerald/island/room/g1","north",
           });

  ::reset(arg);

}

void init() {
  ::init();
  add_action("_pass","pass");
  add_action("_pass","climb");
}


_pass( arg ) {
  if (arg!="bushes") {
    notify_fail("Pass what?\n");
    return 0;
  }
  write("You pass the bushes, a bit apprehensively.\n");
  TP->move_player("over the bushes#players/emerald/island/room/i24");
  return 1;
}
