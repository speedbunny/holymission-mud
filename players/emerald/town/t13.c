inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The main street in town";

  long_desc="The crowds are small here, and you can see the reason " +
            "why.  The battlements of a large castle are visible to the " +
            "north, and soldiers of the king are roaming the streets in " +
            "addition to the regular policemen.  Still, the merchants " +
            "are actively selling to the townspeople.\n";

  dest_dir=({"/players/emerald/town/t14","north",
             "/players/emerald/town/t6","south",
           });

  items=({"battlements","The only visible part of the castle from here",
          "castle","The seat of power in this kingdom",
          "soldiers","Paid swordsmen of the king",
          "crowds","Groups of people arguing over prices",
        });

  clone_list=({
    1,2,"merchant","obj/monster", ({
      "set_name","merchant",
      "set_long","A well-dressed purveyor of goods.\n",
      "set_race","human",
      "set_level",35,
      "set_gender",1,
      "add_money",1000,
      "set_wc",17,
      "set_ac",15,
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
    -1,1,"dagger","obj/weapon", ({
      "set_name","dagger",
      "set_short","A jeweled dagger",
      "set_wc",4,
      "set_value",500,
      "set_weight",1,
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
    4,2,"guard","/players/emerald/castle/monsters/castleguard",0,
    -4,1,"broadsword","/players/emerald/castle/weapons/bsword",0,
    -4,1,"chainmail","/players/emerald/castle/armours/chain",0,
  });
  ::reset(arg);
   replace_program("/room/room");

}
