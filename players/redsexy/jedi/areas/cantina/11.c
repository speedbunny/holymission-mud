inherit "/room/room";

reset (arg) {     
if(arg) return;
    
  set_light(1);
  short_desc="A dark corner of the Mos Eisley Cantina";
  long_desc="There seem to be a lot of seedy characters in this area is of the bar, and they "+
            "eye you with suspicion as you walk over.  You imagine they are discussing illegal "+
            "smuggling deals and trade offs. It is much darker here as the area is only lit with "+
            "candles. You feel like you have entered some kind of underworld. \n\n";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/12","east",
             "/players/redsexy/jedi/areas/cantina/16","south",
           });

  property = ({"has_fire"});

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There are so many creatures in here you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
          "characters","They seem to be making illicit pacts to kill one another!",
          "candles","The candles are burning brightly on the walls",     
        
         });

   clone_list=({
    1,4,"rodian","obj/monster", ({
      "set_name","rodian",
      "set_long","This rodian is sitting having a drink.\n",
      "set_race","wookie",
      "set_level",20,
      "set_gender",1,
      "add_money",300,
      "set_wc",30,
      "set_ac",11,
    }),
    -1,1,"stick","obj/weapon", ({
      "set_name","stick",
      "set_short","A sturdy, short bandying stick",
      "set_wc",4,
      "set_value",200,
      "set_weight",1,
    }),
      2,1,"muftak","obj/monster", ({
      "set_name","muftak",
      "set_race", "wonder",
      "set_long","Muftak is the most adorable monster you ever did see.  You cannot "+
                 "place the race he comes from, for he doesn't even know, but he stands "+
                 "over 8 foot tall, and is covered in matted brown fur.  He is Kabe's best "+
                 "friend and he seems to be looking for her...\n",
      "set_level",40,
      "set_ac",31,
      "set_wc",50,
      "set_hp",4500,
      "set_gender",1,
      }), 

  });
 ::reset(arg);
  }

void light_text(string str) {
    write("You hold the " + str +
          " into the candles on the cantina wall and light it.\n");
    say(this_player()->query_name() + " lights a " + str + ",\n" +
        "using the candles on the cantina wall.\n");
    return;
}
