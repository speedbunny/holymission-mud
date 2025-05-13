inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="The back of the beach";
  long_desc="Dunes flank the beach to the west, while to the east it " + 
            "extends into the breaking waves of the sea.  The sand here is " +
            "quite dry, the last high tide having occurred several hours " +
            "ago.  The only reminders of the passing of the tide are the " +
            "shells and other debris which the water deposited upon the " +
            "sand.\n";

  dest_dir=({"/players/emerald/plain/b06","north",
             "/players/emerald/plain/b02","south",
             "/players/emerald/plain/b05","east",
             "/players/emerald/plain/d01","west",
             "/players/emerald/plain/b07","northeast",
             "/players/emerald/plain/d03","northwest",
             "/players/emerald/plain/b03","southeast",
           });

  items=({"dunes","Mounds of wind-blown sand",
          "beach","A wide beach leading to a blue sea",
          "waves","White-capped waves which break upon the sand",
          "sea","A clear blue sea",
          "sand","Large-grained particles of sand",
          "shells","The former homes of sea creatures",
          "debris","Pebbles, weeds, shells, and woods which the water " +
                   "left behind",
          "water","Genuine rehydrated water",
        });

  ::reset();
  replace_program("/room/room");

}
