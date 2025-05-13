inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A path in the countryside";

  long_desc="Your feet are following a dirt track which winds through " +
            "rolling countryside.  Wild flowers bloom in bright profusion.  " +
            "A soft breeze ruffles your hair and brings the scent of the " +
            "blooming flowers to your nostrils.\n";

  dest_dir=({"/players/emerald/country/1","north",
             "/players/figleaf/smurf/path2","east",
           });

  items=({"flowers","Wild flowers blooming in the field",
          "grasses","Long grass heads bending in the breeze",
          "track","A track in the ground",
          "fields","Fields of grain",
        });

  ::reset(arg);
   replace_program("/room/room");

}
