inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the secret orc chambers";

  long_desc="You are sneaking around in the dark and dangerous orc caves.  "+
            "The caves lead north and east.  The air is thick and smells "+
            "rather strange, a cloying and sickening smell which makes you "+
            "almost wretch.  Moss grows on the floor of the cave, and the "+
            "walls are spattered with blood.  A grunting noise comes from "+
            "the north.\n";

  items=({"ground","The ground is covered with moss",
          "caves","These caves are inhabited by nasty orcs",
          "air","It smells terrible",
          "moss","Evil-looking moss",
          "cave","The cave might be inhabited by an orc",
          "walls","The walls are made of stone",
          "blood","You see big spots of blood",
        });

  smell="The stench of death.";

  dest_dir=({"/players/emerald/island/room/caves/room/ci35","north",
             "/players/emerald/island/room/caves/room/ci33","east",
           });

  clone_list=({
    1,2,"troll","obj/monster",({
      "set_name","troll cave guard",
      "set_alt_name","guard",
      "set_short","troll cave guard",
      "set_race","troll",
      "set_long","The troll cave guard is enormously strong and towers about "+
                 "20 feet over your head.  The length of its body seems to "+
                 "be nothing but rippling muscles.\n",
      "set_gender",1,
      "set_aggressive",1,
      "set_level",30,
      "set_al",-1200,
      "add_money",500+random(50),
    }),
    -1,1,"club","obj/weapon",({
      "set_name","wooden club",
      "set_alias","club",
      "set_short","A spiked, wooden club",
      "set_long","A heavy, spiked wooden club.\n",
      "set_weight",2,
      "set_class",16,
      "set_type",1,
      "set_value",2000,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
