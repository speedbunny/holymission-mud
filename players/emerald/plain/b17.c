inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="The beach";
  long_desc="The sand of the beach is slowly being engulfed by rocks which " +
            "migrated across the sand from the mountains to the west.  " +
            "They litter the beach in a haphazard fashion.  Seaweed has " +
            "become caught between and around them as the tide retreated " +
            "further into the sea.  Where the sand is visible, it is " +
            "riddled with the tracks of birds which have wandered across " +
            "the sand in search of tidbits of food.\n";

  dest_dir=({"/players/emerald/plain/b19","north",
             "/players/emerald/plain/b15","south",
             "/players/emerald/plain/b16","west",
             "/players/emerald/plain/b18","northwest",
             "/players/emerald/plain/b14","southwest",
           });

  items=({"sand","Large grains of sand",
          "beach","It is being subsumed beneath rocks",
          "rocks","Large chunks which have fallen off the mountains",
          "seaweed","Kelp and bladderwrack",
          "sea","A clear blue sea",
          "tracks","Bird footprints",
        });

  ::reset();
  replace_program("/room/room");

}
