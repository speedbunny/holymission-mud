inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="The sleeping chamber of the troll guards";

  long_desc="The sound of snoring and gurgling drowns out all else.  This "+
            "is obviously where the troll guards like to sleep.  A few "+
            "old curtains are strewn about for bedding, and the embers "+
            "of a dying campfire glow a weak red.\n";

  items=({"guards","Big hairy troll guards.  Try not to wake them up",
          "curtains","Old ragged curtains, used for bedding",
          "bedding","A few heaps of ragged curtains",
          "embers","The coals have little fire left in them",
          "campfire","It is dying down",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci43","east",
           });

  clone_list=({
    1,5,"troll","obj/monster",({
      "set_name","troll cave guard",
      "set_alt_name","guard",
      "set_short","troll cave guard",
      "set_race","troll",
      "set_long","The troll cave guard is enormously strong and towers about "+
                 "20 feet over your head.  The length of its body seems to "+
                 "be nothing but rippling muscles.\n",
      "set_gender",1,
      "set_aggressive",1,
      "set_level",30,
      "set_al",-1200,
      "add_money",500+random(50),
    }),
    -1,1,"club","obj/weapon",({
      "set_name","wooden club",
      "set_alias","club",
      "set_short","A spiked, wooden club",
      "set_long","A heavy, spiked wooden club.\n",
      "set_weight",2,
      "set_class",16,
      "set_type",1,
      "set_value",2000,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
