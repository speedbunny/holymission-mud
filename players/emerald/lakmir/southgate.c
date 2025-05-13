inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="Southern Gate";
  long_desc="The road has reached the southern gate to the land of " +
            "the druid Lakmir. The rolling waves of the bay to the east " +
            "sparkle in the sunlight.  A blooming meadow is to the west.\n";

  dest_dir=({"/players/emerald/lakmir/road","north",
             "/players/emerald/lakmir/shore1","east",
             "room/shore/s17","south",
             "/players/emerald/lakmir/meadow1","west"
           });

  items=({"road","You are at the end of the road",
          "gate","A wooden and stone gate leading into the meadow",
          "waves","The are rather small",
          "bay","A good place to catch fish",
          "sunlight","It is quite warm",
          "meadown","It is filled with blooming flowers",
        });

  ::reset();
  replace_program("/room/room");

}
