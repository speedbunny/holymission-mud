inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="In the sand dunes";
  long_desc="Bordered to the north by tall mountains whose peaks are " +
            "hidden beneath caps of snow, and a vast flat grassy plain " + 
            "which extends to the west, the dunes form a transitional zone " +
            "between the sea to the east and the land.  The range of dunes " +
            "runs north and south in a double line of sand mounds.  Sparse " +
            "vegetation grows in pockets between the dunes.\n";

  dest_dir=({"/players/emerald/plain/d08","north",
             "/players/emerald/plain/d04","south",
             "/players/emerald/plain/d07","east",
             "/players/emerald/plain/p30","west",
             "/players/emerald/plain/d09","northeast",
             "/players/emerald/plain/d05","southeast",
             "/players/emerald/plain/p22","southwest",
           });

  items=({"mountains","High, impenetrable mountains",
          "peaks","Their snowcaps reflect the brilliant summer sunlight",
          "snow","Crystalized water in mass quantities",
          "plain","The rippling grass flows to the west",
          "dunes","Large mounds of sand",
          "sea","A wide, clear blue sea",
          "land","Terra firma",
          "range","A line of sand dunes",
          "mounds","The sand is blown into small hills",
          "vegetation","A few hardy grasses and shrubs",
        });

  ::reset();
  replace_program("/room/room");

}
