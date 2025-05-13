inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="The sand dunes";
  long_desc="You are standing at the top of a range of sand dunes.  They " + 
            "extend north and south along the eastern border of the " +
            "grassy plain.  Far to the north, the high snow-capped peaks " +
            "of the grey mountains seem out of place in contrast to the " +
            "blazing heat of the dunes.  The dark Ilkin Forest grows " +
            "right up against the dunes to the southwest, its dark trees " +
            "growing in twisted, sinister closeness.  Another line of " +
            "dunes lies to the east, and beyond that, the blue water of " +
            "the sea.\n";

  dest_dir=({"/players/emerald/plain/d06","north",
             "/players/emerald/plain/d02","south",
             "/players/emerald/plain/d05","east",
             "/players/emerald/plain/p22","west",
             "/players/emerald/plain/d07","northeast",
             "/players/emerald/plain/p30","northwest",
             "/players/emerald/plain/d03","southeast",
           });

  items=({"range","A chain of sand dunes",
          "dunes","High mounds of white sand",
          "border","The boundary of the plain and the dunes",
          "plain","A vast flat area of grassland",
          "peaks","They are tipped with a blanket of white snow",
          "mountains","Enormous grey mountains with sheer sides",
          "forest","A refuge for evil and creatures of the dark side",
          "trees","Old elms and maples",
          "water","A combination of hydrogen and oxygen",
          "sea","It looks warm and inviting",
        });

  ::reset();
  replace_program("/room/room");

}
