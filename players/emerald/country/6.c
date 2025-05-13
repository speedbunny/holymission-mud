inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A path in the countryside";

  long_desc="The track in the dirt continues its endless journey through " +
            "the rich farmland.  You begin to wonder where it will end.\n";

  dest_dir=({"/players/emerald/country/7","east",
             "/players/emerald/country/3","west",
           });

  items=({"track","Old wagon ruts",
          "farmland","Beautiful fields of ripening grain",
        });


  ::reset(arg);
   replace_program("/room/room");

}
