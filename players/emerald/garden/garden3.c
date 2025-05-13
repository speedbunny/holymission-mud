inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="Garden dead end";
  long_desc="This is a really peaceful place.  To the south is a wall and " +
            "to the east and north is a hedge.  There is a big oak tree " +
            "here which casts a shadow upon you.  You feel like you could " +
            "stay in the shade of this huge tree for quite awhile.\n";

  items=({"oak", "A big old oak grows here giving off a nice cool shadow",
          "wall","It is to the south",
           "tree","An oak tree",
          "hedge","It blocks any passage to the north",
          "shade","The shade provided by the oak tree",
          "shadow","It is the shadow of a tree",
        });

  dest_dir=({"/players/emerald/garden/garden2", "west",
           });

  clone_list=({
    1,1,"mole","obj/monster", ({
      "set_name","baby mole",
      "set_alias","mole",
      "set_short","baby mole",
      "set_long","This tiny mole searches blindly for its parents.\n",
      "set_race","rodent",
      "set_level",1,
      "set_al",30,
      "set_hp",30,
      "set_wc",1,
      "add_money",30,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");
}
