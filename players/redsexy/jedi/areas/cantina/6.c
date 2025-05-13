inherit "room/room";

object board;

reset (arg) {     
  if(arg) return;

  set_light(1);
  short_desc="A sideroom in the Mos Eisley Cantina.";
  long_desc="This sideroom is decorated with posters of bands who have played "+
            "here, forthcoming attractions, wanted notices and community announcements. "+
            "It obviously acts as some kind of tourist information centre and people "+
            "stand around and hang out, reading the notices and drinking their cocktails. \n\n ";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/2","northeast",
           });

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There are so many creatures in here you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
          "posters","Many posters advertise forthcoming events",
          "bands","The bands on the posters are the jazz greats, such as Max Rebo and "+
                  "the Whipid Rebites.",
          "attractions", "The attractions here seem to be the bands that are forthcoming",
          "notices","These notices advertise who's head has a price on it",
          "announcements","The announcements are numerous, but you note that the one "+
                          "in red points out that the bar stays open 24 hours a day!",

         });

        board=clone_object("/players/redsexy/jedi/areas/cantina/cantboard");
        transfer(board,this_object());
        
    ::reset(arg);
       
    }


