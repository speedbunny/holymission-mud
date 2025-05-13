
inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="Inside the orc kitchen";
  long_desc="You have entered a small, dark hole in the eastern part of "+
            "the orc caves.  A huge fire roars in the middle of the room, "+
            "evil looking knives glint on a table, and strange things "+
            "which appear vaguely edible are lying around.  The stench is "+
            "pretty powerful in here.\n";

  items=({"hole","This place is really nasty",
          "part","The eastern part of the orc caves",
          "caves","The secret orc caves",
          "fire","It is for cooking",
          "middle","The middle of the room contains a fire",
          "room","The kitchen, presumably",
          "kinves","Their edges are chipped and dull",
          "table","A long, bloody table",
          "things","They might have been alive, once",
        });

  smell="You think you want to gag.";
      
  dest_dir=({"/players/emerald/island/room/caves/room/ci15","east",
           });

  clone_list=({
    1,4,"boy","obj/monster",({
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
    2,1,"chef","obj/monster",({
      "set_name","orc chef",
      "set_alt_name","chef",
      "set_short","Orc chef de la cuisine",
      "set_race","orc",
      "set_long","The chef of the orcs.  You probably don't want to know "+
                "what he's been cooking.\n",
      "set_gender",1,
      "set_aggressive",1,
      "set_level",20,
      "set_al",-300,
      "add_money",3000+random(50),
      "set_number_of_arms",2,
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
    -2,1,"boots","/players/emerald/island/room/caves/obj/boots",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
