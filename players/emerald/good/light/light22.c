inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  long_desc="The forest here is quite dense, with a corresponding lack of "+
            "sunlight.  The ground shows no sign of travel.  Off in the "+
            "distance you hear the sounds of forest creatures, but there " +
            "are no sounds that are close to you. The forest ground here is "+
            "bare of deadfall, and looks like it has been burnt.\n";

  short_desc="Forest";

  dest_dir=({"/players/emerald/good/light/light23","west",
             "/players/emerald/good/light/light19","east",
           });

  items=({"ground","The ground is barren and burnt here",
          "forest","It is thick and stifling",
        });

  ::reset();
  replace_program("/room/room");

}

