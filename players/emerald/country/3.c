inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A path in the countryside";

  long_desc="The smell from the flowers is really quite strong here.  The " +
            "ruts continue to the east and west.  To the north, you can see " +
            "an old, barely used path.\n";

  dest_dir=({"/players/emerald/country/4","north",
             "/players/emerald/country/6","east",
             "/players/emerald/country/2","west",
           });

  items=({"ruts","Deep ruts formed by the passing of many wagons",
          "path","A little trail leading off the the north that looks as " +
                 "if no one uses it anymore",
          "flowers","A blend of chicory, mullein, and wild carrots",
        });

  smell="A fragrant mix of the scents of various flowers";

  ::reset(arg);
   replace_program("/room/room");

}
