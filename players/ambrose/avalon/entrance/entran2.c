inherit "room/room";

reset(arg) {
  if (arg) return;
     set_light(1);

     short_desc="A mountain path";

     long_desc="The path stops in front of a tunnel mouth which gapes darkly"
              +" before you.\n"
               "On either side of the entrance stands the statues of two "
              +"knights.  They\n"
               "are wearing traditional full armor and have their swords "
              +"pointed impaled\n"
               "on the ground before them.\n";
     dest_dir=({"players/ambrose/avalon/entrance/entran1","down",
                "players/ambrose/avalon/entrance/entran3","east"});

    items=({"tunnel","Seems to be real dark",
            "statues","They seem to be likeness to Knights of the Round Table",
            "path","Goes down and extends into the dark tunnel",});
     }
