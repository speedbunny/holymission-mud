inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the orc caves";

  long_desc="This is the sleeping hall of the orcs.  Thick wool curtains "+
            "hang in the corners, and various articles of pilfered "+
            "clothing are heaped up in piles on the floor.  The stuffiness "+
            "of the room and the reek of unwashed, sweaty bodies is almost "+
            "more than your nose can tolerate.\n";

  items=({"curtains","The curtains are made of wool",
          "hall","The sleeping quarters of the orcs",
          "orcs","Orcs sleep here, and boy does the place stink",
          "corners","Curtains cover the corners",
          "articles","Tidbits of clothing from the orcs' victims",
          "clothing","Mostly old, flithy rags",
          "piles","Heaps of moldering clothing",
          "floor","It is covered in old clothes and orc bodies",
          "room","It's close and stuffy in here",
          "bodies","Flithy, wretched orc bodies",
          "nose","Your nose is highly offended by the stench in here",
        });

  smell="It's unbearably horrid in here.";

  dest_dir=({"/players/emerald/island/room/caves/room/ci12","north",
             "/players/emerald/island/room/caves/room/ci7","east",
           });

  clone_list=({
    1,2,"shaman","/players/emerald/island/room/caves/obj/shaman",0,
    -1,1,"mace","/players/emerald/island/room/caves/obj/mace",0,
    -1,1,"robe","obj/armour",({
      "set_name","black robe",
      "set_alias","robe",
      "set_short","A black robe",
      "set_long","A long, black robe.\n",
      "set_weight",1,
      "set_ac",1,
      "set_type","cloak",
      "set_value",75,
    }),
    2,2,"peasant","obj/monster",({
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
    -2,1,"dagger","obj/weapon",({
      "set_name","stone dagger",
      "set_alias","dagger",
      "set_long","A small dagger made of obsidian.\n",
      "set_weight",1,
      "set_short","An obsidian dagger",
      "set_class",8,
      "set_type",1,
      "set_value",60,
    }),
    3,2,"warrior","obj/monster",({
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
    -3,1,"axe","obj/weapon",({
      "set_name","war axe",
      "set_alias","axe",
      "set_short","A war axe",
      "set_long","A big iron axe, perfect for chopping off heads.\n",
      "set_weight",2,
      "set_class",16,
      "set_value",450,
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
    -3,1,"helmet","obj/armour",({
      "set_name","leather helmet",
      "set_short","A leather helmet",
      "set_alias","helmet",
      "set_long","A strong leather helmet.\n",
      "set_weight",1,
      "set_ac",1,
      "set_type","helmet",
      "set_value",120,
    }),
    -3,1,"boots","/players/emerald/island/room/caves/obj/boots",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
