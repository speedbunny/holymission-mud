inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The edge of the mountains";
  long_desc="The sandy beach backs into the sheer grey cliffs of the " +
            "mountain range to the west.  Large chunks of rock litter " +
            "the sand.  Towards the back of the beach, large boulders " +
            "which have split off the cliffside have accumulated at the " +
            "base of the cliff.\n";

  dest_dir=({"/players/emerald/plain/b18","north",
             "/players/emerald/plain/b14","south",
             "/players/emerald/plain/b17","east",
             "/players/emerald/plain/b19","northeast",
             "/players/emerald/plain/b15","southeast",
             "/players/emerald/plain/d10","southwest",
           });

  items=({"beach","A white-sand beach",
          "cliffs","High, sheer cliffs",
          "mountain","Cold, silent mountains",
          "range","A range of mountains running north and south",
          "chunks","Big, rough-edged rocks",
          "rock","Large chunks of rock",
          "boulders","Huge sections of broken rock",
          "cliffside","High, sheer cliffs",
          "cliff","A high, sheer cliff",
        });

  clone_list=({
    1,1,"fly","obj/monster", ({
      "set_name","fly",
      "set_race","insect",
      "set_short","A black fly",
      "set_long","A huge black fly.\n",
      "set_level",8,
      "set_aggressive",1,
      "add_money",40,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
