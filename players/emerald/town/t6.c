inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The main street in town";

  long_desc="The crowds are somewhat thinner here.  Better dressed " +
            "merchants are behind the stalls and booths, and their wares " +
            "appear to be of better quality.  The people in the crowds also " +
            "look to be of a higher class than simple peasants.  Bargaining " +
            "remains at a a calm level, due in part to the presence of a " +
            "policeman.\n";

  dest_dir=({"/players/emerald/town/t13","north",
            "/players/emerald/town/t7","east",
            "/players/emerald/town/t10","west",
            "/players/emerald/town/t5","south",
           });

  items=({"booths","Neatly arranged displays of quality items",
          "people","Humans, for the most part",
          "wares","The items for selling",
          "stalls","Shaded structures to keep the merchants out of the sun",
        });

  clone_list=({
    1,3,"merchant","obj/monster", ({
      "set_name","merchant",
      "set_long","A well-dressed purveyor of goods.\n",
      "set_race","human",
      "set_level",35,
      "set_gender",1,
      "add_money",1000,
      "set_wc",17,
      "set_ac",15,
    }),
    -1,1,"dagger","obj/weapon", ({
      "set_name","dagger",
      "set_short","A jeweled dagger",
      "set_wc",4,
      "set_value",500,
      "set_weight",1,
    }),
    2,2,"citizen","obj/monster", ({
      "set_name","citizen",
      "set_race", "human",
      "set_long","A respectable member of the townsfolk.\n",
      "set_level",35,
      "set_ac",13,
      "set_wc",12,
      "set_gender",1,
      "add_money",700,
    }),
    -2,1,"vest","obj/armour", ({
      "set_name","vest",
      "set_short","A leather vest",
      "set_ac",2,
      "set_class","armour",
      "set_weight",2,
      "set_value",100,
    }),
    3,1,"policeman","obj/monster", ({
      "set_name","policeman",
      "set_long","He is here to preserve the peace.\n",
      "set_race","human",
      "set_gender",1,
      "set_ac",15,
      "set_wc",16,
      "set_level",30,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
