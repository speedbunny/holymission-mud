inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="A grassy plain";
  long_desc="The grassy plain begins here at the meeting of sand dunes " +
            "and mountains.  Though it cannot be seen, the faint roar of " +
            "the sea can be heard coming from the east.  To the west the " +
            "plain continues its grassy expansion.  Cold grey mountains " +
            "loom to the north, while across the plain, to the south, " +
            "lurks the dense Ilkin Forest.\n";

  dest_dir=({"/players/emerald/plain/d06","east",
             "/players/emerald/plain/p29","west",
             "/players/emerald/plain/p22","south",
             "/players/emerald/plain/d04","southeast",
             "/players/emerald/plain/p21","southwest",
           });

  items=({"plain","A vast expanse of grassland",
          "dunes","High piles of sand",
          "mountains","They form the northern boundary of the plain",
          "forest","A forest of great evil and danger",
        });

  ::reset();
  replace_program("/room/room");

}
