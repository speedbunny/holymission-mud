inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the orc caves";

  long_desc="The signs of death and suffering are scattered around the "+
            "cave.  Blood stains the walls, bones lie on the ground, and "+
            "and overall stench of death fills the air.  Off to the "+
            "east you can hear a murmuring voice, like someone praying.\n";

  items=({"signs","Bones, blood, the usual signs of death",
          "cave","A foul place inhabited by orcs",
          "blood","Splotches of blood on the walls",
          "walls","Old stone walls splattered with blood",
          "bones","There used to be flesh attached to those bones",
          "ground","The floor of the cave",
          "air","Stuffy cave air",
        });

  smell="The scent of death never leaves these caves.";

  dest_dir=({"/players/emerald/island/room/caves/room/ci10","east",       
             "/players/emerald/island/room/caves/room/ci7","southwest",
           });

  clone_list=({
    1,2,"peasant","obj/monster",({
      "set_name","orc peasant",
      "set_alt_name","peasant",
      "set_short","An orc peasant",
      "set_race","orc",
      "set_long","A harmless looking orc.\n",
      "set_gender",1+random(1),
      "set_aggressive",1,
      "set_level",3,
      "set_whimpy",20,
      "set_al",-100,
      "add_money",150+random(50),
    }),
    -1,1,"dagger","obj/weapon",({
      "set_name","stone dagger",
      "set_alias","dagger",
      "set_long","A small dagger made of obsidian.\n",
      "set_weight",1,
      "set_short","An obsidian dagger",
      "set_class",8,
      "set_type",1,
      "set_value",60,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
