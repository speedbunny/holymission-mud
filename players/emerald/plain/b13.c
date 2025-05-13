inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="The shoreline";
  long_desc="The sun beats down upon you mercilessly.  Shimmering waves " +
            "of heat rise from the hot sand.  The light bleaches the " +
            "colour from the shells and pebbles which litter the beach.  " +
            "Only the cool blue of the sea to the east retains its depth " +
            "of colour.  The snow-capped mountains to the west remind you " +
            "that the heat will not last forever, and winter will return.\n";

  dest_dir=({"/players/emerald/plain/b15","north",
             "/players/emerald/plain/b11","south",
             "/players/emerald/plain/b12","west",
             "/players/emerald/plain/b14","northwest",
             "/players/emerald/plain/b10","southwest",
           });

  items=({"sun","Gazing directly into the sun will damage your retinas",
          "waves","Floating waves of heat",
          "sand","Coarse grains of sand",
          "shells","Accretions of calcium carbonate",
          "pebbles","Their edges have been rounded by the pounding surf",
          "sea","A vast, clear blue sea",
          "mountains","They rise high to the west",
        });

  ::reset();
  replace_program("/room/room");

}

