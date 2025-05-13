inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the orc caves";

  long_desc="You are wandering through the orc caves.  Strange noises come "+
            "from the east.  The sight and stench of death is all around "+
            "you.  Bones litter the floor, blood is splashed on the walls, "+
            "and the reek of decay fills the air.\n";

  items=({"caves","These caves are inhabited by orcs",
          "bones","Old and some not-so-old bones on the floor",
          "blood","Fresh red and old, dark blood stains",
          "walls","Stone walls splashed with blood",
          "air","It stinks of death",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci1","south",
             "/players/emerald/island/room/caves/room/ci4","north",
             "/players/emerald/island/room/caves/room/ci3","east",
           });

  smell="It reeks of death in these caves.";

  clone_list=({
    1,2,"guard","obj/monster",({
      "set_name","orc guard",
      "set_alt_name","guard",
      "set_short","An orc guard",
      "set_race","orc",
      "set_long","An orc guard protecting the cave.\n",
      "set_gender",1+random(1),
      "set_aggressive",1,
      "set_level",15,
      "set_al",-800,
      "add_money",800+random(50),
      "set_number_of_arms",2,
    }),
    -1,1,"axe","obj/weapon",({
      "set_name","axe",
      "set_long","A big steel axe for chopping wood.\n",
      "set_short","A steel axe",
      "set_weight",3,
      "set_class",13,
      "set_value",1500,
    }),
    -1,1,"jacket","obj/armour",({
      "set_name","dirty jacket",
      "set_alias","jacket",
      "set_short","A dirty leather jacket",
      "set_long","A dirty strong leather jacket.\n",
      "set_weight",2,
      "set_ac",3,
      "set_type","armour",
      "set_value",150,
    }),
    2,1,"shaman","/players/emerald/island/room/caves/obj/shaman",0,
    -2,1,"mace","/players/emerald/island/room/caves/obj/mace",0,
    -2,1,"robe","obj/armour",({
      "set_name","black robe",
      "set_alias","robe",
      "set_short","A black robe",
      "set_long","A long, black robe.\n",
      "set_weight",1,
      "set_ac",1,
      "set_type","cloak",
      "set_value",75,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
