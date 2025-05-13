inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="The middle of grassy plain";
  long_desc="From the dark Ilkin Forest to the south, to high cold peaks " +
            "of the mountains to the north, the only thing in sight is a " +
            "sea of waving grass.  The gentle breeze can be seen moving " +
            "across the plain in waves, causing the grass to reflect " +
            "gold, then tan.  Circling high overhead, a small black speck " +
            "reminds you of the relationship between predator and prey.\n";

  dest_dir=({"/players/emerald/plain/p25","north",
             "/players/emerald/plain/p06","south",
             "/players/emerald/plain/p16","east",
             "/players/emerald/plain/p14","west",
             "/players/emerald/plain/p26","northeast",
             "/players/emerald/plain/p24","northwest",
             "/players/emerald/plain/p07","southeast",
             "/players/emerald/plain/p05","southwest",
           });

  items=({"forest","A dangerous and dark forest",
          "peaks","They are tipped with snow",
          "mountains","Cold and silent grey mountains",
          "sea","The plain reminds you of the endless expanse of the sea",
          "grass","It ripens in the sunlight",
          "waves","The grass bends as the wind brushes against it",
          "speck","Most likely a sharp-eyed hawk",
        });

  ::reset();
  replace_program("/room/room");

}
