inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A grassy plain",


  long_desc="This is the edge of a vast grassy plain.  It ends here at " +
            "northern edge of the Ilkin Forest.  To the north you see the " +
            "towering peaks of the mountains.  From somewhere around " +
            "you, hidden in the waving grass, the yip of a fox can be " +
            "heard.\n";

  dest_dir=({"/players/emerald/plain/p16","north",
             "/players/emerald/plain/p08","east",
             "/players/emerald/plain/p06","west",
             "/players/emerald/plain/p17","northeast",
             "/players/emerald/plain/p15","northwest",
           });

  items=({"plain","A flat area of grassland",
          "forest","The eerie and evil Ilkin Forest",
          "peaks","High snow-capped peaks",
          "mountains","Large mountains looming on the northern horizon",
          "grass","Long stems of golden grass",
        });

  ::reset();
  replace_program("/room/room");

}
