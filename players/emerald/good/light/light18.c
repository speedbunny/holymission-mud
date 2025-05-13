inherit "room/room";


void reset(int arg) {

  if(arg) return;

  set_light(1);

  long_desc="A beautiful white stag makes his home here. If you are lucky, " +
            "you might catch a glimpse of the stag eating some grass.\n";

  short_desc="The home of the stag";


  dest_dir=({"players/emerald/good/light/light16","south"
           });

  smell="The place has the scent of grass.";

  items=({"grass","Lush green grass",
        });

  clone_list=({
    1,1,"stag","obj/monster", ({
      "set_name","white stag",
      "set_alias","stag",
      "set_race","deer",
      "set_level",13,
      "set_hp",270,
      "set_al",700,
      "set_short","A beautiful white stag",
      "set_long","The stag is a proud and majestic animal. It looks like "
                 + "it can take care of itself.\n",
      "set_ac",7,
      "set_wc",16,
    }),
    -1,1,"antlers","obj/weapon", ({
      "set_name","antlers",
      "set_alias","horns",
      "set_short","A large set of deer antlers",
      "set_long","The antlers look sharp and could do some damage.\n",
      "set_class",14,
      "set_value",1100,
      "set_weight",2,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
