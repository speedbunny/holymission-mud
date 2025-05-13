inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A grassy plain";
  long_desc="You are standing at the southern edge of a range of high " +
            "grey mountains.  Extending southwards are the rippling grasses "+
            "of a vast plain.  The thick Ilkin Forest begins at the " +
            "southern boundary of the plain.  Only the bright blue sky " +
            "is overhead.  The beauty of the day is spoiled by a foul " +
            "reek coming from a clump of grass.\n";

  dest_dir=({"/players/emerald/plain/p21","east",
             "/players/emerald/plain/p19","west",
             "/players/emerald/plain/p11","south",
             "/players/emerald/plain/p29","northeast",
             "/players/emerald/plain/p12","southeast",
             "/players/emerald/plain/p10","southwest",
           });

  items=({"range","A line of tall mountains forming the northern boundary",
          "mountains","They tower above you and are unclimbable",
          "grasses","A variety of different types of grass",
          "plain","A vast flat expanse of grassland",
          "forest","The evil and dangerous Ilkin Forest",
          "sky","There is not even a trace of a cloud in it",
          "clump","A small clump of grass, half-concealing a rotting carcass",
        });

  smell="It is the terrible stench of carrion.\n";

  clone_list=({
    1,1,"vulture","obj/monster", ({
      "set_name","vulture",
      "set_race","bird",
      "set_short","A hungry vulture",
      "set_long","A hungry vulture tearing away at a rotting carcass.\n",
      "set_level",15,
      "set_aggressive",1,
      "add_money",120,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
