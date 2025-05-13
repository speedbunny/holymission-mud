inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="Northern Gate";
  long_desc="This is the northern gate to the land of the druid Lakmir.  " +
            "To the east you see the rolling waves of a shallow bay.  The " +
            "sunlight sparkles on the water.  West leads into a dark " +
            "forest of ancient trees.  The road continues to the south.\n";

  dest_dir=({"room/shore/s16","north",
             "/players/emerald/lakmir/shore4","east",
             "/players/emerald/lakmir/bifurcation","south",
             "/players/emerald/lakmir/forest0","west"
           });

  items=({"waves","The small aquamarine waves of the bay",
          "gate","A small wooden gate leading to the land of the druid Lakmir",
          "bay","There are most certainly many kinds of fish in the bay",
          "sunlight","It dances on the rolling waves",
          "water","The main component of the bay",
          "road","The road continues along the shoreline",
          "forest","It looks dark and forbidding",
          "trees","Ancient oaks and beech",
         });

  ::reset();
  replace_program("/room/room");

}
