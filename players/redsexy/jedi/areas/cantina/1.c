inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="In a dark corner of the Mos Eisley Cantina.";
  long_desc="You stand in a dark corner of the bar, soaking in the atmosphere, "+
            "losing yourself in the soulful music drifting over to where you "+
             "stand.  Quieter than the rest of the bar, this seems to be the "+
            "area where lovers enjoy each other's company. Couples sit here " +
            "whispering sweet nothings to each other. \n\n";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/2","east",
           });
  
  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There are so many creatures in here you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
          "atmosphere","You feel like you should just chill out here",
          "lovers","It seems to be the most romantic place in the bar",
          "couples","This area is ideal for lovers to sit in",
          "area","A cosy, romantic corner of the Mos Eisley cantina",
         });


clone_list=({
    1,2,"noghri","obj/monster", ({
      "set_name","noghri",
      "set_long","A grey skinned noghri.\n",
      "set_race","noghri",
      "set_level",35,
      "set_gender",1,
      "add_money",1000,
      "set_wc",17,
      "set_ac",15,
    }),
    -1,1,"dagger","obj/weapon", ({
      "set_name","dagger",
      "set_short","A jeweled dagger from the Maskai clan",
      "set_wc",4,
      "set_value",500,
      "set_weight",1,
    }),
    2,2,"whipid","obj/monster", ({
      "set_name","whipid",
      "set_race", "whipid",
      "set_long","A long-snouted whipid.\n",
      "set_level",20,
      "set_ac",10,
      "set_wc",8,
      "set_gender",2,
    }),

  });
  ::reset(arg);
   replace_program("/room/room");

}


