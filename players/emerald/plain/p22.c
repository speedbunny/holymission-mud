
inherit "room/room";

reset(arg) {

  set_light(1);

  short_desc="The edge of the plains";

  long_desc="You are standing at the edge of a vast grassy plain.  " +
            "The vegetation is thinner here, and the ground is " +
            "quite sandy.  To the east, you hear the faint roar of " +
            "the sea.  South is the border of the dark Ilkin forest, " +
            "thick and impenetrable at this location.  North and west, " +
            "the mountains stand silent guard over the plain.  Above " +
            "you, a lone seabird shrieks its hunger.\n";

  dest_dir=({"/players/emerald/plain/p30","north",
             "/players/emerald/plain/d04","east",
             "/players/emerald/plain/p21","west",
             "/players/emerald/plain/d06","northeast",
             "/players/emerald/plain/p29","northwest",
             "/players/emerald/plain/p12","southwest",
           });

  items=({"plain","A large stretch of flat grassland",
          "vegetation","It grows sparsely here",
          "ground","Sand is visible in patches on the surface",
          "forest","It looms on the horizon like a sinister shadow",
          "mountains","Dark, sharp peaks cutting into the sky",
          "seabird","A small winged shape in the sky",
        });

  smell="There is a faint tinge of salt on the air.\n";

  clone_list=({
    1,1,"lizard","obj/monster", ({
      "set_name","lizard",
      "set_short","A small green lizard",
      "set_race","reptile",
      "set_long","A small green lizard looking for insects.\n",
      "set_level",8,
      "add_money",30,
    }),
  });

  ::reset();
  replace_program("room/room");

}
