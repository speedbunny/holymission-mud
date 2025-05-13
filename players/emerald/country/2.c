inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A path in the countryside";

  long_desc="The track continues on through the countryside.  It continues" +
            " to the east for a while and returns to the west.\n";

  dest_dir=({"/players/emerald/country/3","east",
             "/players/emerald/country/1","west",
           });

  items=({"track","Deep ruts formed in the dirt by the passing of many wagons",
        });

  ::reset(arg);
   replace_program("/room/room");

}
