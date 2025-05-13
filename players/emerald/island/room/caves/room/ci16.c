inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="Inside a storage room";

  long_desc="You have entered a small, dark hole in the eastern part "+
            "of the orc caves.  This room seems to be some sort of storage "+
            "area, possibly for the kitchen.  A small corridor leads to "+
            "the west.\n";

  items=({"hole","It's rather cramped in here and the ceiling is low",
          "part","The eastern part of the orc caves",
          "caves","The orc caves",
          "room","A storeroom",
          "area","A storeroom for the kitchen",
          "kitchen","The kitchen must be nearby",
          "corridor","It leads back to the west",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci15","west",
           });

  clone_list=({
    1,4,"apple","obj/food",({
      "set_name","apple",
      "set_short","a red apple",
      "set_long","It looks very big and tasty.\n",
      "set_value",2,
      "set_weight",1,
      "set_eater_mess","It's mildy tart.\n",
      "set_strength",5,
      "set_eating_mess"," eats an apple.\n",
    }),
    2,1,"warrior","obj/monster",({
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
    -2,1,"axe","obj/weapon",({
      "set_name","war axe",
      "set_alias","axe",
      "set_short","A war axe",
      "set_long","A big iron axe, perfect for chopping off heads.\n",
      "set_weight",2,
      "set_class",16,
      "set_value",450,
    }),
    -2,1,"jacket","obj/armour",({
      "set_name","dirty jacket",
      "set_alias","jacket",
      "set_short","A dirty leather jacket",
      "set_long","A dirty strong leather jacket.\n",
      "set_weight",2,
      "set_ac",3,
      "set_type","armour",
      "set_value",150,
    }),
    -2,1,"helmet","obj/armour",({
      "set_name","leather helmet",
      "set_short","A leather helmet",
      "set_alias","helmet",
      "set_long","A strong leather helmet.\n",
      "set_weight",1,
      "set_ac",1,
      "set_type","helmet",
      "set_value",120,
    }),
    -2,1,"boots","/players/emerald/island/room/caves/obj/boots",0,
    3,3,"cider","obj/keg",({
      "set_name","keg of cider",
      "set_alt_name","keg",
      "set_alias","cider",
      "set_short","keg of cider",
      "set_long","You see a small oak wooden keg of cider.\n",
      "set_value",200,
      "set_taps",20,
      "set_weight",2,
      "set_strength",5,
      "set_consumer_mess","You take a big tap from your keg.",
      "set_consuming_mess"," taps from a small keg.",
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
