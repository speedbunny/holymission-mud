inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="A gaming area in the Mos Eisley Cantina.";
  long_desc="This area of the cantina seems to be set aside for illegal "+
            "gambling and games. There is a mandalesk table set up in the corner "+
            "and you'd quite fancy a game if you could ever figure out how to "+
            "play! This room is full of smoke, from the pipes and cigars of the "+
            "rich creatures who play here, so you don't feel like hanging around "+
            "for too long. \n\n ";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/10","north",
             "/players/redsexy/jedi/areas/cantina/19","southwest",
           });

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There are so many creatures in here you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
         });

  clone_list=({  1, 1, "table", "/players/redsexy/jedi/objects/mandalesk", 0,
               });

  ::reset();
  replace_program("/room/room");

}

