inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="The armoury and weaponry";

  long_desc="This is the armoury and weaponry of the orc caves.  It is "+
            "utterly dark down here.  Weapons and armours are strewn about "+
            "the floor, waiting to be polished.  Racks line the walls, "+
            "holding more equipment, waiting to be used.\n";

  items=({"armoury","Armour is stored here",
          "weaponry","Weapons are stored here",
          "caves","The secret orc caves",
          "weapons","Morningstars, daggers, axes, the usualy stuff",
          "armours","Jackets, helmets, and the like",
          "floor","It is covered in equipment",
          "racks","They are filled with gleaming weapons and armours",
          "walls","Racks line the walls",
          "equipment","Weapons and armours",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci22","up",
           });

  clone_list=({
    1,1,"boy","obj/monster",({
      "set_name","orc boy",
      "set_alt_name","boy",
      "set_short","A busy orc boy",
      "set_race","orc",
      "set_long","An orc kitchen helper.\n",
      "set_gender",1,
      "set_aggressive",1,
      "set_level",5,
      "set_al",-100,
      "add_money",80+random(50),
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
    3,2,"guard","obj/monster",({
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
    -3,1,"axe","obj/weapon",({
      "set_name","axe",
      "set_long","A big steel axe for chopping wood.\n",
      "set_short","A steel axe",
      "set_weight",3,
      "set_class",13,
      "set_value",1500,
    }),
    -3,1,"jacket","obj/armour",({
      "set_name","dirty jacket",
      "set_alias","jacket",
      "set_short","A dirty leather jacket",
      "set_long","A dirty strong leather jacket.\n",
      "set_weight",2,
      "set_ac",3,
      "set_type","armour",
      "set_value",150,
    }),
    4,2,"warrior","obj/monster",({
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
      "set_number_of_arms",2,
    }),
    -4,1,"axe","obj/weapon",({
      "set_name","war axe",
      "set_alias","axe",
      "set_short","A war axe",
      "set_long","A big iron axe, perfect for chopping off heads.\n",
      "set_weight",2,
      "set_class",16,
      "set_value",450,
    }),
    -4,1,"jacket","obj/armour",({
      "set_name","dirty jacket",
      "set_alias","jacket",
      "set_short","A dirty leather jacket",
      "set_long","A dirty strong leather jacket.\n",
      "set_weight",2,
      "set_ac",3,
      "set_type","armour",
      "set_value",150,
    }),
    -4,1,"helmet","obj/armour",({
      "set_name","leather helmet",
      "set_short","A leather helmet",
      "set_alias","helmet",
      "set_long","A strong leather helmet.\n",
      "set_weight",1,
      "set_ac",1,
      "set_type","helmet",
      "set_value",120,
    }),
    -4,1,"boots","/players/emerald/island/room/caves/obj/boots",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
