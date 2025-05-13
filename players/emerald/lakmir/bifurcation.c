inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);
  smell="The air smells salty here";

  short_desc = "bifurcation";
  long_desc="You have arrived at a bifurcation in the road which leads " +
            "south along the ocean shore.  A shallow bay lies to the " +
            "east.  There is a sign which points to the west.\n";

  dest_dir=({"/players/emerald/lakmir/northgate","north",
             "/players/emerald/lakmir/shore3","east",
             "/players/emerald/lakmir/road","south",
             "/players/emerald/lakmir/path1","west"
           });

  items=({"shore","Behind the shore is a shallow bay",
           "ocean shore","Behind the shore is a shallow bay",
           "bay","Looks like it might be a good place to catch fish",
           "ocean","The ocean is very shallow in the bay",
            "sign","You could read it",
          "bifurcation","The road continous to the north and the south " +
                        "while a path leads to the west",
          "road","The road continues to the north and south",
        });

  ::reset(arg);

}

void init() {
  ::init();
  add_action("_read", "read");
}

_read(str) {

  if(str!="sign") {
    write("Read what?\n");
    return 0;
  }

  if(str =="sign") {
    write("          northern gate\n"
         +"               I \n"
         +"cottage <- bifurcation\n"
         +"               I\n"
         +"             road\n"
         +"               I\n"
         +"          southern gate\n");
    return 1;
  }

}
