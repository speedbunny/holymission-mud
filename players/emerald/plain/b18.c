inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A rocky beach";

  long_desc="You are clambering around on rocks at the base of the cliff " +
            "which flanks the beach.  The cliff is dotted with the nests " +
            "of birds which have made their homes in the small ledges " +
            "and crevices of the cliffside.  The birds fly back and forth " +
            "to the sea in search of fish and molluscs.  The rocks at your " +
            "feet are littered with the cracked and empty shells of their " +
            "meals.\n";

  dest_dir=({"/players/emerald/plain/b19","east",
             "/players/emerald/plain/b16","south",
             "/players/emerald/plain/b20","northeast",
             "/players/emerald/plain/b17","southeast",
           });

  items=({"rocks","Large chunks of granite and basalt",
          "cliff","A mostly sheer cliff rising hundreds of feet above you",
          "beach","The area between the sea and the land",
          "nests","Flimsy affairs of grasses and twigs",
          "birds","Various species of seabirds",
          "ledges","Flat horizontal surfaces on the face of the cliff",
          "crevices","Spaces in the rocky planes of the cliffside",
          "cliffside","A wall of rock towering above the beach",
          "sea","The long waves break against the rocks",
          "fish","Gilled animals which like to swim",
          "molluscs","Shell-protected soft-bodied creatures",
          "shells","The former housing of the molluscs",
        });

  clone_list=({
    1,1,"seagull","obj/monster", ({
      "set_name","seagull",
      "set_race","bird",
      "set_alias","gull",
      "set_level",10,
      "set_wc",10,
      "set_short","A grey and white seagull",
      "add_money",45,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
