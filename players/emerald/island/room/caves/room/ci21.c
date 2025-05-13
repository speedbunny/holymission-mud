inherit "/room/room";

void reset(int arg){
  if(arg) return;

  set_light(1);
  short_desc="The eastern orc caves";

  long_desc="You are sneaking through the secret orc caves.  The passage "+
            "leads north and south.  In the eastern wall there are tiny "+
            "holes which allow sunlight and the sounds of the sea to "+
            "enter the caves.  Strange noises come from the north.\n";

  items=({"caves","The secret orc caves",
          "passage","It leads further to the north and south",
          "wall","There are tiny holes in the eastern cave wall",
          "sunlight","Small beams of light penetrate the gloomy cave",
          "sea","You can hear its roaring from here",
        });
      
  dest_dir=({"/players/emerald/island/room/caves/room/ci22","north",
             "/players/emerald/island/room/caves/room/ci20","south",
           });

  clone_list=({
    1,1,"guard","obj/monster",({
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
  });

  ::reset(arg);
  replace_program("/room/room");

}
