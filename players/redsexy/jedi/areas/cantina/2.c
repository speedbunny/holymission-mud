inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="A booth in the Mos Eisley Cantina.";
  long_desc="You have entered one of the booths in the Mos Eisley cantina, "+
            "typically set out for a crowd of friends to sit together in "+
            "seclusion from the rest of the mayhem in the place.  It is much "+
            "quieter in here and you feel as if you don't have a care in the world. \n\n ";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/8","southeast",
             "/players/redsexy/jedi/areas/cantina/1","west",
             "/players/redsexy/jedi/areas/cantina/6","southwest",
           });

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There are so many creatures in here you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
          "booth","The booth is deocrated in red, probably to hide the bloodstains",
          "mayhem","Lots of chatter and loud music make this place seem chaotic!"
         });

 clone_list=({
    1,10,"snips","obj/monster", ({
      "set_name","snip",
      "set_long","A small, skinny socialite snip.\n",
      "set_race","snip",
      "set_level",1,
      "set_gender",1,
      "set_aggressive",1,
      "set_wc",30,
      "set_ac",0,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}

