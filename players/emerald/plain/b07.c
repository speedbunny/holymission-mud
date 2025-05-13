inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="The waterfront";
  long_desc="The weeds thrown up by the waves are quite thick in this " +
            "segment of the beach.  They form deep, dense piles of green, " +
            "black, and brown which cling to each other and your feet as " +
            "you attempt to walk through them.  Rocks hidden underneath " +
            "the piles slip and turn under your feet, causing you to " +
            "stumble.\n";

  dest_dir=({"/players/emerald/plain/b09","north",
             "/players/emerald/plain/b05","south",
             "/players/emerald/plain/b06","west",
             "/players/emerald/plain/b08","northwest",
             "/players/emerald/plain/b04","southwest",
           });

  items=({"weeds","Various varieties of seaweed",
          "waves","Aquamarine waves which break upon the sand",
          "beach","A white sand beach littered with piles of seaweed",
          "piles","Jumbled masses of seaweed",
          "feet","Long flat appendages at the bottoms of your legs",
          "rocks","Igneous rocks formed by volcanic action",
        });

  ::reset();
  replace_program("/room/room");

}
