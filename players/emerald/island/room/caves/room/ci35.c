inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the secret orc chambers";

  long_desc="You are sneaking cautiously through the dark, secret orc "+
            "caves.  To the north, the corridor leads into a huge stone "+
            "hallway.  A few monoliths can be seen to the north, with "+
            "a few shadows moving around behind them.\n";


  items=({"caves","They are dark and fraught with danger",
          "corridor","It leads north and south",
          "hallway","It is built of stone",
          "monoliths","Huge, hulking blocks of stone",
          "shadows","They move about in groups of two",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci36","north",
             "/players/emerald/island/room/caves/room/ci34","south",
           });

  ::reset(arg);
  replace_program("/room/room");

}
