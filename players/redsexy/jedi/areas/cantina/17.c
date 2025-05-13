inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The stage of the Mos Eisley Cantina";
  long_desc="You are now right in front of the stage of the Mos Eisley cantina, watching the band "+
            "perform and feeling extremely mellow.  It seems to be The Dan Lo-ging Jizzwailers, "+
            "and you watch the show in awe, wishing you were as musical as these geniuses.   "+
            "The crowd around you clap enthusiastically at the end of every number, and you "+
            "feel like you could watch the show forever.\n\n ";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/13","northeast",
           });

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There are so many creatures in here you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
          "stage","A wooden stage, shaped in a semi-circle",
          "jizwailers","They are out of your reach on the stage",
          "band","The Dan Lo-ging Jizzwailers are the best jizzwailer band around",
          "show","The Dan Lo-ging Jizzwailers are playing here",
          "crowd","There are a whole bunch of creatures jam packed in here",
          "number","You can't quite name this particular tune...",
         });

 clone_list=({
    1,3,"gran","obj/monster", ({
      "set_name","gran",
      "set_long","A smooth orange skinned gran.\n",
      "set_race","gran",
      "set_level",7,
      "set_gender",1,
      "add_money",50,
      "set_wc",9,
      "set_ac",2,
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
      3,2,"bith","obj/monster", ({
      "set_name","bith",
      "set_race", "bith",
      "set_long","A tall headed bith, with an enormous mouth!\n",
      "set_level",13,
      "set_ac",5,
      "set_wc",16,
      "set_hp",4500,
      "set_gender",1,
      }), 
  });

  ::reset();
  replace_program("/room/room");

}