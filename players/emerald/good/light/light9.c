inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  long_desc="You have entered a small ravine. The ravine looks like it " +
            "was made by the water of a river long since vanished.  The " +
            "ravine walls are dry and steep.\n";

  short_desc="Small ravine";

  dest_dir=({"/players/emerald/good/light/light15","south",
             "/players/emerald/good/light/light3","west"
           });

  items=({"walls","The river walls are way too steep to climb here",
          "wall","The wall is too steep to climb",
          "ravine","An old, dry river bed",
        });
    
  ::reset();
  replace_program("/room/room");

}

