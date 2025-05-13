inherit "/players/whisky/obj/std_bank";
#include "/players/whisky/genesis/sys/break_string.h"
#define BS(x) break_string(x+"\n",68)
void reset(int flag) {
   ::reset(flag);
   if(flag == 0) {
       set_light(1);
       short_desc = "Yaromashi's bank ";
      long_desc=
         "You in a small room next to the bar of Yoshihiro.  In front\n"+
         "of you is a huge brown desk where 'Yaromashi', a red robed\n"+
         "ninja is sitting, counting and calculating money. A small\n"+
         "sign is hanging on the wall and a big note on the desk reads:\n"+
         "Yaromashi's Bank.\n";
      items=({
         "bottom","The bottom is made of brown earth",
         "desk","It's an oak-wooden desk",
         "sign","There is something written on it",
         "yaromashi","You see a noble looking monk sitting behind the desk",
         "wall","They are made of spruce wooden lathes",
         "walls","They are made of spruce wooden lathes",
         "lathes","Spruce wooden lathes"
         });
         clerk = "Yaromashi";
         taxes = 1;
         save_file = "/players/tatsuo/ezo/broker";
        dest_dir=({  "/players/tatsuo/ezo/bar","east",  });
        ::daily_taxes();
      }
  }
