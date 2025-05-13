inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The main seating area of the Mos Eisley Cantina";
  long_desc="The area here is laid out with tables and chairs where people can sit around "+
            "and enjoy an informal drink with one another.  Creaures sit around and chat "+
            "about life, the universe and everything, whilst the music of the band drifts "+
            "around you. \n\n ";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/11","west",
             "/players/redsexy/jedi/areas/cantina/7","north",
           });

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There are so many creatures in here you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
          "tables","Brown wooden tables",
          "chairs","Plain red cushioned chairs",
         });
   clone_list=({
    1,1,"gran","obj/monster", ({
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
      3,1,"bith","obj/monster", ({
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
