inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="Mountain top";
  long_desc="You feel great!  You have climbed the mountain.  The view "+
            "from up here is magnificent!  FAR below you, you can "+
            "see the great tree of Silverthorne.  There appears to be " +
            "a cave entrance to the north.\n";

  items=({"tree", "The great tree looks TINY from up here",
          "view", "Quite splendid",
          "cave","Enter it to get a better look",
          "mountain","You're standing on top of it",
        });

  dest_dir=({"players/emerald/good/light/light6","north",
             "players/emerald/good/light/light14","down",
           });

  ::reset();
  replace_program("/room/room");

}
