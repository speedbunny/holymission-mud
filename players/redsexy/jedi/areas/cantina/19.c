inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="A credit booth at the Mos Eisley Cantina";
  long_desc="This credit booth is hidden in a dark corner of the Cantina, and a sly "+
            "looking Corellian sits behind the counter looking at you with amusement "+
            "in his eyes.  You guess that the operation is illegal, but note that you "+
            "can change your gold coins for credits here, the widely accepted form of "+ 
            "currency for gambling in Mos Eisley. \n\n  ";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/15","northeast",
             "/players/redsexy/jedi/areas/cantina/20","east",
           });

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There are so many creatures in here you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
          "booth","A small booth that has been set up in the corner",
          "credits","The widely accepted form of currency in the Mos Eisley Cantina",
          "corner","A dark corner of the cantina",
         });

clone_list=({   1, 1, "cashier", "/players/redsexy/jedi/monsters/cashier", 0,
              });

  ::reset();
  replace_program("/room/room");

}