inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="A crowded area of the Mos Eisley Cantina.";
  long_desc="This part of the bar is jam packed with creatures, all dancing and tapping "+
            "their feet to the music that fills the room.  The band is on top form tonight "+
            "and even you take a moment to listen to them.  The stage is to the southwest,  "+
            "and you begin to wonder if you can fight through the crowds to take an even "+
            "closer look at who is playing. \n\n ";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/7","northwest",
             "/players/redsexy/jedi/areas/cantina/17","southwest",
             "/players/redsexy/jedi/areas/cantina/14","east",
           });

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There are so many creatures in here you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "band","It's a Jizz-wailer band, but you cannot see them from here",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
          "stage","Lots of creatures swarm around the stage",
         });
  clone_list=({
    1,1,"ferrerr","obj/monster", ({
      "set_name","ferrerr",
      "set_long","This wrinkled ferrerr is humming along to the music.\n",
      "set_race","ferrerr",
      "set_level",23,
      "set_gender",1,
      "add_money",400,
      "set_wc",33,
      "set_ac",14,
      "set_hp",1950,
     }),
      2,4,"twilek","obj/monster", ({
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
