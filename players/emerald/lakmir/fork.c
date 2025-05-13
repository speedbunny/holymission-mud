inherit "/room/room";

void reset(int arg) {

  set_light(1);

  short_desc="A fork in the path";
  long_desc="You have come to a fork in the path.  It continues to the " +
            "east, west, and south, while a dark forest begins to the " +
            "north.  There is a building at the side of the path.  It "+
            "appears to be a pub.  There is a wooden sign in front of you.\n";

  dest_dir=({"/players/emerald/lakmir/forest11","north",
             "/players/emerald/lakmir/path1","east",
             "/players/emerald/lakmir/path3","south",
             "/players/emerald/lakmir/path2","west",
             "/players/emerald/lakmir/rest","pub",
           });

  items=({"fork","The path divides here",
          "path","A track through the land of Druid Lakmir",
          "forest","It gives you chills",
          "building","A pub at the side of the path",
          "sign","You could read it",
          "pub","You could get something to eat there",
        });

  ::reset(arg);

}

void init() {
  ::init();
  add_action("_read", "read");
}

_read(str) {
  if (str =="sign") {
    write("            pub\n"
         +"cottage <- fork -> road\n"
         +"             I\n"
         +"          pasture\n");
    return 1;
  }
  if (str!="sign") {
    write("Read what?\n");
    return 1;
  }
}
