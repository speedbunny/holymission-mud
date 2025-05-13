inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="The waterline";
  long_desc="The surf swirls around your feet as the waves break upon the " +
            "beach, pulling the sand out from under them as the water " +
            "retreats back into the sea.  The deep blue sky overhead " +
            "seems to merge with the sea at the horizon.  Brightly " +
            "coloured pebbles roll against each other in the water, " +
            "polishing and rounding their surfaces continuously.\n";

  dest_dir=({"/players/emerald/plain/b05","north",
             "/players/emerald/plain/b01","south",
             "/players/emerald/plain/b02","west",
             "/players/emerald/plain/b04","northwest",
           });

  items=({"surf","Foamy salt water",
          "feet","The appendages which provide you with locomotion",
          "waves","Rolling aquamarine waves",
          "sand","Silica",
          "beach","A wide, clear beach",
          "water","Hydrogen and oxygen with a good measure of salts as well",
          "sea","A vast quantity of water",
          "sky","It is cloudless",
          "horizon","The border of the sea and sky",
          "pebbles","Small, smooth stones",
          "surfaces","The faces of the stones",
        });


  ::reset();
  replace_program("/room/room");

}
