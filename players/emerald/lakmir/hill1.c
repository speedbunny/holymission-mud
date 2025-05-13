inherit "room/room";

reset(arg) {

  set_light(1);

  short_desc="The top of a rather high hill";
  long_desc="You have climbed to the top of a rather steep hill.  Nothing " +
            "grows here.  All the trees have been turned into blackened " +
            "stumps which dot the landscape.  Less hardy varieties of " +
            "vegetation have been completely eradicated from the hill.  The "+
            "bare, burnt ground is reminiscent of the lair of a dragon.\n";

  dest_dir=({"/players/emerald/lakmir/hillside1","down"
           });

  items=({"hill","This is the top of the hill",
          "trees","They are nothing but charred stumps",
          "stumps","The remnants of trees",
          "landscape","Rocky and charred",
          "vegetation","There isn't any",
          "ground","Hard, burnt earth",
          "lair","It could be the lair of a dragon",
        });

  clone_list=({
    1,1,"dragon","obj/monster", ({
      "set_name","red dragon",
      "set_alias","dragon",
      "set_short","A huge red dragon",
      "set_long","An enormously strong red dragon.\n",
      "set_race","dragon",
      "set_level",40,
      "set_al",-300,
      "set_wc",25,
      "set_size",5,
      "set_ac",15,
      "set_chance",30,
      "set_gender",2,
      "set_spell_dam",40,
      "set_spell_mess1","The dragon breathes fire!\n",
      "set_spell_mess2","The dragon breathes fire at you!\n",
    }),
    -1,1,"mail","obj/armour", ({
      "set_name","scalemail",
      "set_alias","mail",
      "set_type","armour",
      "set_ac",5,
      "set_short","Dragon scalemail",
      "set_long","It is made of the scales of a red dragon.\n",
      "set_value",2000,
      "set_weight",5,
      "set_size",5,
    }),
    -1,1,"diamond","obj/treasure", ({
      "set_id","diamond",
      "set_short","A big clear blue diamond",
      "set_long","A wonderfully huge diamond, worth quite a bit!\n",
      "set_value",500+random(1001),
      "set_weight",2,
    }),
  });
  
  ::reset();
  replace_program("/room/room");

}
