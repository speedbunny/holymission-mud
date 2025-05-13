inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="A grassy plain";
  long_desc="You find yourself standing in a vast, grassy plain.  The wind " +
            "bends the long stems of grass into waves which travel across " +
            "the landscape.  Incredibly immense grey mountains tower" +
            "over the plain to the north.  Their high craggy peaks are " +
            "capped with snow.  If you wish for safe passage through this " +
            "area, the enchanted path to the west will provide it.\n";

  dest_dir=({"/players/emerald/plain/p31","north",
             "/players/emerald/plain/p13","south",
             "/players/emerald/plain/p24","east",
             "/players/kryll/rooms/path/ep16","west",
             "/players/emerald/plain/p32","northeast",
             "/players/kryll/rooms/path/ep17","northwest",
             "/players/emerald/plain/p14","southeast",
             "/players/kryll/rooms/path/ep15","southwest",
           });

  items=({"plain","An immense open space of waving grass",
          "stems","They are turning golden in the sunlight",
          "path","The enchanted path",
          "landscape","Flat, mainly",
          "mountains","Impossibly high mountains which form the northern " +
                      "boundary",
          "waves","The wind passes across the grass in waves",
          "peaks","They are hidden underneath caps of snow",
          "snow","Formations of ice crystals massed together",
        });

  ::reset();
  replace_program("/room/room");

}
