inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="A crowdeda of the Mos Eisley Cantina.";
  long_desc="The creatures here all impatiently bustling around, either to the bar "+
            "or from the bar, spilling drinks as they bump into each other. "+
            " The chattering here is loud, as old friends and acquaintances "+
            "bump into one another and exchange pleasantries.\n\n ";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/8","east",
             "/players/redsexy/jedi/areas/cantina/12","south",
             "/players/redsexy/jedi/areas/cantina/13","southeast",
           });

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There so many creatures in here you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "music","It sounds like a Jizz-wailer band, but you can't place who ",
          "desert","Forget about it!  RELAX....",
         });

clone_list=({
    1,1,"wookie","obj/monster", ({
      "set_name","wookie",
      "set_long","A large tough-looking wookie, carrying some drinks.\n",
      "set_race","wookie",
      "set_level",36,
      "set_gender",1,
      "add_money",1000,
      "set_wc",20,
      "set_ac",20,
    }),
    -1,1,"dagger","obj/weapon", ({
      "set_name","staff",
      "set_short","A long pointed hunting staff",
      "set_wc",7,
      "set_value",700,
      "set_weight",1,
    }),
    2,1,"kabe","obj/monster", ({
      "set_name","kabe",
      "set_race", "wonder",
      "set_long","Kabe is a small, green, giggly monster, and you cannot place "+
                 "which race she comes from However, she seems to have drunk "+
                 "too much juri juice!\n",
      "set_level",5,
      "set_ac",7,
      "set_wc",5,
      "set_gender",2,
      }),

  });

  ::reset(arg);
  replace_program("/room/room");

}
