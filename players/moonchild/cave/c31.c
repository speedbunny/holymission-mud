inherit "room/room";
 
void reset(int arg) {
  short_desc="A dimly lit cavern";
  long_desc=
    "You are in what appears to be the corner of a large, dimly lit "+
    "cavern. You feel a draught of warm air coming from the east.\n";
  dest_dir=({
    "players/moonchild/cave/c21", "north",
    "players/moonchild/cave/c32", "east"
  });
  clone_list=({
    1,1,"troll","obj/monster", ({
      "set_name","troll",
      "set_alias","guard",
      "set_alt_name","troll guard",
      "set_short","A massive troll guard is here",
      "set_level",34,
      "set_wc",10,
      "set_long","A massive troll guard stands here.\n",
      "set_aggressive",1,
      "set_al",-300,
      "set_gender",1,
    }),
    -1,1,"plate","obj/armour", ({
      "set_name","field plate",
      "set_type","armour",
      "set_alias","plate",
      "set_short","A massive field plate",
      "set_long","This field plate is a very good armour indeed.\n",
      "set_ac",4,
      "set_weight",6,
      "set_value",1500,
    }),
    -1,1,"gloves","obj/armour", ({
      "set_type","glove",
      "set_name","gloves",
      "set_short","Studded leather gloves",
      "set_alias","leather gloves",
      "set_long","A well-made pair of studded leather gloves.\n",
      "set_ac",1,
      "set_weight",2,
      "set_value",400,
    }),
    -1,1,"club","obj/weapon", ({
      "set_name","club",
      "set_short","A heavy trollish club",
      "set_long","This is a heavy bloodstained trollish club.\n",
      "set_class",13,
      "set_weight",7,
      "set_value",600,
    })
  });
 
  ::reset(arg);
  replace_program("/room/room");
}
