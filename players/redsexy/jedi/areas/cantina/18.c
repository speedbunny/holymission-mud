inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The dressing rooms of the Mos Eisley Cantina";
  long_desc="These are the dressing rooms of the Mos Eisley Cantina. Visiting artists "+
            "come and change into their show gear here, and sit and enjoy refreshments after a  "+
            "gruelling days entertainment.  There is a rack here with clothes hangers and a  "+
            "large oak cupboard, stretching to the ceiling. \n\n  ";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/14","northeast",
           });

  items=({"bar","This is the Mos Eisley Cantina. and it is packed",
          "rebo","He prefers it if you call him Max",
          "snootles","She prefers it if you call her Sy",
          "mccool","He prefers it if you call him Droopy",
          "rack","A rack with clothes hanging from it",
          "hangers","Metal hangers swing from the rack",
          "ceiling","A wooden ceiling high above the room",
          "creatures","There are so many creatures in here you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
         });

 clone_list=({
    1,1,"max","obj/monster", ({
      "set_name","Max Rebo",
      "set_long","This is Max Rebo, from Evar Orbus Galactic Jizz-wailers.  \n"+
                 "It looks as if they are the support act for the evening.\n",
      "set_race","max",
      "set_level",7,
      "set_gender",1,
      "add_money",500,
      "set_wc",9,
      "set_ac",2,
     }),
      2,1,"sy","obj/monster", ({
      "set_name","Sy Snootles",
      "set_long","This is Sy Snootles, from Evar Orbus Galactic Jizz-wailers.\n "+
                 "It looks as if they are the support act for the evening.\n",
      "set_race","sy",
      "set_level",15,
      "set_gender",2,
      "set_wc",20,
      "set_ac",6,
     }),
      3,1,"droopy","obj/monster", ({
      "set_name","Droopy McCool",
      "set_race", "droopy",
      "set_long","This is Droopy McCool, from Evar Orbus Galactic Jizz-wailers. \n "+
                 "It looks as if they are the support act for the evening.\n",
      "set_level",13,
      "set_ac",5,
      "set_wc",16,
      "set_hp",4500,
      "set_gender",1,
      }), 
      4,1,"cupboard","/players/redsexy/jedi/areas/cantina/cupboard", 0,
  });

  ::reset();
  replace_program("/room/room");

}
