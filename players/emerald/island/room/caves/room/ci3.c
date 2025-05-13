inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the orc caves";

  long_desc="These are the training quarters for the orcs who inhabit "+
            "the caves.  There is evidence of their training equipment "+
            "scattered over the ground.  The familiar blood stains the "+
            "walls, bones lie on the ground, and the cave is filled with "+
            "a foul reek.\n";

  items=({"quarters","The orc warriors train here",
          "caves","The secret orc caves",
          "equipment","Hideous and heavy training equipment.  You shudder "+
                      "to look at it",
          "ground","It is littered with equipment and old bones",
          "blood","Dark stains of blood on the walls",
          "walls","Stone walls stained with blood",
          "bones","Old bones of forgotten adventurers",
          "cave","The stench makes you want to retch",
        });

  smell="A sickening reek lingers in the air.";

  dest_dir=({"/players/emerald/island/room/caves/room/ci2","west",
           });

  clone_list=({
    1,3,"warrior","obj/monster",({
      "set_name","orc warrior",
      "set_alt_name","warrior",
      "set_short","orc warrior",
      "set_race","orc",
      "set_long","A strong looking orc warrior.\n",
      "set_gender",1,
      "set_aggressive",1,
      "set_level",25,
      "set_al",-800,
      "add_money",300+random(50),
      "se_number_of_arms",2,
    }),
    -1,1,"axe","obj/weapon",({
      "set_name","war axe",
      "set_alias","axe",
      "set_short","A war axe",
      "set_long","A big iron axe, perfect for chopping off heads.\n",
      "set_weight",2,
      "set_class",16,
      "set_value",450,
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
    -1,1,"helmet","obj/armour",({
      "set_name","leather helmet",
      "set_short","A leather helmet",
      "set_alias","helmet",
      "set_long","A strong leather helmet.\n",
      "set_weight",1,
      "set_ac",1,
      "set_type","helmet",
      "set_value",120,
    }),
    -1,1,"boots","/players/emerald/island/room/caves/obj/boots",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
