inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A path in the countryside";

  long_desc="You are walking on a dirt track through a countryside of " +
            "open fields.  Flowers and grass wave in the light breeze.  " +
            "Sunlight streams down on your face.  You find it a pleasant " +
            "day to be outside.\n";

  dest_dir=({"/players/emerald/country/2","east",
             "/players/emerald/country/entry","south",
           });

  items=({"flowers","Wild flowers blooming in the field",
          "grasses","Long grass heads bending in the breeze",
          "track","A track in the ground",
          "fields","Fields of grain",
        });

  ::reset(arg);
   replace_program("/room/room");

}
