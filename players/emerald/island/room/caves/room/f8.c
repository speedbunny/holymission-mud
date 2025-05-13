inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In a dark mixed forest";
  long_desc="You are wandering through a dark mixed forest.  The air is "+
            "filled with sounds, not all of them pleasant.  A spring can "+
            "be heard off to the west.  Overhead, the branches creak and "+
            "groan, while the leaves rustle in disapproval.  A low rumble "+
            "in the background warns that the volcano is still active.\n";

  items=({"forest","It is dark and eerie in here",
          "air","The air is thick and stifling",
          "spring","It is somewhere to the west",
          "branches","The wind causes them to rub together",
          "leaves","They rustle a warning hiss",
          "volcano","You are on a volcanic island",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/f9","northwest",
             "/players/emerald/island/room/caves/room/f7","west",
             "/players/emerald/island/room/caves/room/f4","south",
             "/players/emerald/island/room/caves/room/f5","southeast",
           });

  clone_list=({
    1,3,"hunter","obj/monster",({
      "set_name","orc hunter",
      "set_alt_name","hunter",
      "set_short","An orc hunter",
      "set_race","orc",
      "set_long","A hungry orc hunting animals.\n",
      "set_gender",1+random(1),
      "set_aggressive",1,
      "set_level",11,
      "set_whimpy",10,
      "set_al",-400,
      "add_money",300+random(50),
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
  });

  ::reset(arg);
  replace_program("/room/room");

}
