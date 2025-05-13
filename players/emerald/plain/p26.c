inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="Under the shadow of the mountains";
  long_desc="You have reached the northern edge of the plain.  The high " +
            "craggy peaks of the grey mountains rise up swiftly to the " +
            "north, forming an impenetrable barrier.  Across the waving " +
            "grass, to the south, lies the dark border of the dread " +
            "Ilkin Forest, whose ancient evil lies in the heart of every " +
            "tree and bush.  But for the moment, the summer sun shines " +
            "brightly in the deep blue sky, filling the world with its " +
            "warm glow.\n";

  dest_dir=({"/players/emerald/plain/p27","east",
             "/players/emerald/plain/p25","west",
             "/players/emerald/plain/p16","south",
             "/players/emerald/plain/p33","northwest",
             "/players/emerald/plain/p17","southeast",
             "/players/emerald/plain/p15","southwest",
           });

  items=({"plain","A vast open area of grassland",
          "peaks","High snow-capped mountain peaks",
          "mountains","Their sides angle sharply upwards",
          "grass","It ripens in the summer sunlight",
          "border","The meeting of plain and forest",
          "barrier","The mountains are unclimbable",
          "forest","Only those dark of spirit dare dwell there",
          "sun","Looking directly at the sun can cause retinal damage",
          "sky","It is an intense azure",
        });

  ::reset();
  replace_program("/room/room");

}
