inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="The blacksmith's";
  long_desc="The ringing of hammer on metal fills your ears.  Sparks " +
            "fly from the red hot metal as it is pounded into shape by the " +
            "strong arm of the blacksmith.  Judging from the items you see " +
            "in the shop, the smith must do exceptional work.  Everything " +
            "from nails, hinges, and horseshoes, to swords and knives looks " +
            "to be of the highest quality.\n";

  dest_dir=({"/players/emerald/town/t19","north",
           });
  items=({"metal","A piece of glowing metal, hot from the forge",
          "nails","Large wrought nails",
          "horseshoes","Foot gear for equines",
          "swords","Long pointy objects",
          "knives","Short pointy objects",
          "hinges","Useful for opening doors",
        });

  clone_list=({
    1,1,"smith","obj/monster", ({
      "set_name","blacksmith",
      "set_alias","smith",
      "set_race","human",
      "set_gender",1,
      "set_short","A strong armed blacksmith",
      "set_long","The incredibly strong town blacksmith.\n",
      "set_al",900,
      "set_level",75,
      "set_wc",23,
      "set_ac",12,
      "add_money",6000,
    }),
  });

  ::reset(arg);
   replace_program("/room/room");

}
