inherit "room/room";

void reset(int arg) {

  set_light(1);

  short_desc="A path through the forest";
  long_desc="This is a winding path which runs through the forest of the " +
            "Druid Lakmir.  To the east lies a blooming meadow.  A green " +
            "pasture can be seen to the south.  There appear to be some " +
            "shapes in the pasture, but from this distance you cannot see "+
            "what they are.\n";

  dest_dir=({"/players/emerald/lakmir/meadow2", "east",
             "/players/emerald/lakmir/pasture","south",
             "/players/emerald/lakmir/fork","north",
             "/players/emerald/lakmir/forest2","west",
           });
  
  items=({"path","A narrow, winding path",
          "forest","It is quite dangerous",
          "meadow","It is filled with flowers",
          "pasture","It is filled with dark green grass",
          "shapes","Some sort of animal, no doubt",
        });

  ::reset();
  replace_program("/room/room");

}
