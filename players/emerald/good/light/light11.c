inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  long_desc="You have come to the place where a great mountain rises from "+
            "the earth. The mountain looks stunning in its majestic " +
            "beauty.  The mountain top is covered with glistening snow.  " +
            "To the east is an open prairie.  Beyond that stands a dark line "+
            "of trees.  To the west begin the woods.  The road continues "+
            "north over the foothills of the mountain.\n";

  short_desc="The base of the mountain";

  dest_dir=({"players/emerald/good/light/light14","north",
             "players/emerald/good/light/light3","south",
             "players/emerald/good/light/light12","east",
             "players/emerald/good/light/light13","west",
           });

  items=({"mountain","A really stupendous-looking mountain",
          "earth","The ground upon which you are standing",
          "foothills","The road leads over the foothills of the mountain",
          "top","It is covered in snow",
          "woods","They are rather thin",
          "prairie","An open area of grassland",
          "line","A tree line",
          "trees","They mark the beginning of the woods",
          "snow","Frozen water crystals",
          "road","The road leads north over the foothills of the mountain",
        });

  clone_list=({
    1,1,"goat","obj/monster", ({
      "set_name","billy goat",
      "set_alias", "billy",
      "set_race", "goat",
      "set_level", 7,
      "set_hp", 180,
      "set_al", 350,
      "set_short", "A young billy goat",
      "set_long","This goat is young, but still looks strong.\n",
      "set_ac", 5,
      "set_wc", 12,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
