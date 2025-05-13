inherit "/room/room";
void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="The eastern orc caves";

  long_desc="You are wandering about the secret orc caves.  A dark "+
            "stairway leads down into a dark place, while the corridor "+
            "continues to the north and south.  Tiny holes in the eastern "+
            "cave wall allows sunlight into the gloom, as well as the "+
            "songs of birds and the sea.\n";

  items=({"caves","The secret orc caves",
          "stairway","You shiver to think what might be down there",
          "place","It's dark at the bottom of the stairs",
          "corridor","It leads north and south",
          "holes","Little holes in the cave wall let in light and air",
          "sunlight","Miniature beams of sunlight",
          "wall","It has rows of tiny holes",
          "birds","They seem to be quite happy and singing merrily",
          "sea","You can hear the roar of the waves on the sand",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci24","north",
             "/players/emerald/island/room/caves/room/ci21","south",
             "/players/emerald/island/room/caves/room/ci23","down",
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
