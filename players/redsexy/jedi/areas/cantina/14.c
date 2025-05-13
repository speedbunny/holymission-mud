inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The dancefloor of the Mos Eisley Cantina";
  long_desc="The floor here is wooden and polished, and you realize this area is set aside "+
            "for those who want to dance to the wonderful music that the band is playing.  "+
            "Although you cannot see the stage from here, the music can be heard clearly, "+
            "and a little ball made of pieces of reflective glass spins around suspended from "+
            "the ceiling, providing a spectacular lighting effect. \n\n ";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/13","west",
             "/players/redsexy/jedi/areas/cantina/18","southwest",
           });

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There are so many creatures in here you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
          "ceiling","The ceiling has a mirrorball suspended from it",
          "floor","The floor shines, and it is quite slippery!",
          "stage","You cannot see it from here, but you can here the music",
          "ball","It is some kind of mirrored-ball, fixed to the ceiling",
         });
  clone_list=({
    1,1,"gambish","obj/monster", ({
      "set_name","gambish",
      "set_long","The gambish is tap dancing to the music.\n",
      "set_race","gambish",
      "set_level",10,
      "set_gender",1,
      "add_money",400,
      "set_wc",12,
      "set_ac",3,
      "set_hp",230,
     }),
      2,1,"twilek","obj/monster", ({
      "set_name","twilek",
      "set_long","A twileki dancer dancing to the music.\n",
      "set_race","twilek",
      "set_level",15,
      "set_gender",2,
      "set_wc",20,
      "set_ac",6,
     }),
  });


  ::reset();
  replace_program("/room/room");

}
