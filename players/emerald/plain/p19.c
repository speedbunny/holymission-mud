
inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="The edge of the plain";
  long_desc="You are standing in a large grassy plain under the shadow of " +
            "enormous grey mountains which tower above you to the north.  " +
            "South, across a short expanse of grassland, broods the dark " +
            "and dangerous Ilkin Forest.  Nothing can be seen in between " +
            "except the waving grass.\n";

  dest_dir=({"/players/emerald/plain/p20","east",
             "/players/emerald/plain/p10","south",
             "/players/emerald/plain/p18","west",
             "/players/emerald/plain/p28","northwest",
             "/players/emerald/plain/p11","southeast",
             "/players/emerald/plain/p09","southwest",
           });

  items=({"plain","A vast flat area of golden grassland",
          "mountains","High craggy mountains which are unclimbable",
          "grassland","It is filled with ripening grass",
          "forest","A haven for evil of all sorts",
          "grass","Long stems of golden grass, waving in the breeze",
        });

  ::reset();
  replace_program("/room/room");

}
