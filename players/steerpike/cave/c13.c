inherit "room/room";
 
void reset(int arg) {
  short_desc="A dimly lit cavern";
  long_desc=
    "You are in what appears to be the corner of a large, dimly lit "+
    "cavern. You feel a draught of warm air coming from the west.\n";
  dest_dir=({
    "players/moonchild/cave/c23", "south",
    "players/moonchild/cave/c12", "west"
  });
  clone_list=({
    1,1,"troll","obj/monster", ({
      "set_name","troll",
      "set_alias","giant troll",
      "set_short","A giant troll stands here",
      "set_level",28,
      "set_wc",10,
      "set_long","A giant troll stands here. He looks like a ferocious "+
                 "creature.\n",
      "set_aggressive",1,
      "set_al",-250,
      "set_gender",1,
      "add_money",50+random(201),
    }),
    -1,1,"shield","obj/armour", ({
      "set_name","shield",
      "set_type","shield",
      "set_short","A well wrought shield",
      "set_long","This is a very well designed shield.\n",
      "set_ac",1,
      "set_weight",3,
      "set_value",750,
    }),
    -1,1,"boots","obj/armour", ({
      "set_type","boot",
      "set_name","boots",
      "set_short","Studded leather boots",
      "set_alias","leather boots",
      "set_long","A well-made pair of studded leather boots.\n",
      "set_ac",1,
      "set_weight",2,
      "set_value",400,
    }),
    -1,1,"sword","obj/weapon", ({
      "set_name","longsword",
      "set_alt_name","sword",
      "set_short","A trollish longsword",
      "set_long","This is a trollish longsword.\n",
      "set_class",13,
      "set_weight",7,
      "set_value",600,
    })
  });
 
  ::reset(arg);
  replace_program("/room/room");
}
