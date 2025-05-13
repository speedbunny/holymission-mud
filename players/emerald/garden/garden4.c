inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="Royal Garden";
  long_desc="You are on a path going east.  There is a hedge to the north " +
            "and south.  Left of the path, there are flowers in all colours "+
            "and bees trying to get their nectar.\n";

  items=({"flowers", "Bright yellow and red flowers swaying with the wind",
          "bees", "Big yellow and black bees fly around collecting nectar",
          "hedge","The golden hedge of the garden",
          "path","The garden path",
        });

  dest_dir=({"/players/emerald/garden/garden1", "west",
             "/players/emerald/garden/garden5", "east",
           });

  clone_list=({
    1,1,"bird","obj/monster", ({
      "set_name","nightingale",
      "set_race","bird",
      "set_level",1,
      "set_short","A grey nightingale",
      "set_long","The nightingale fills the garden with her song.\n",
      "add_money",50,
      "set_al",300,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
