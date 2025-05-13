inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The enterance hall to the Mos Eisley Cantina.";
  long_desc="You have entered a dark bar, crowded with many creatures "+
            "of various races.  You realize this must be the Mos Eisley "+
            "Cantina, and it is more vibrant than you ever imagined it to "+
            "be!  Music drifts over the loud chattering and laughter in here, "+
            "and everyone seems to be having a really good time.  In such "
            "a relaxed atmosphere it is easy to forget the desert outside. \n\n";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/8","south",
            "/players/redsexy/jedi/areas/desert/d59", "northwest",
           });

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There, are so many creatures in here, you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
         });

  ::reset(arg);
  replace_program("/room/room");

}

