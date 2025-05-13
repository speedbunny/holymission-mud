inherit "obj/armour";
#include "/players/gareth/define.h"

void reset(int flag) {
     ::reset(flag);
     if (flag == 0) {

         set_name("ring of Hermes");
         set_alias("ring");
         set_short("ring of Hermes");
         set_long( "You see a platinum ring, it appears to be vibrating\n"+
                   "on it's own.\n");
         set_type("ring");
         set_ac(0);
         set_weight(1);
         set_value(10000);
         modify_stat(1,3);
      }
}


int wear_fun(object pl) {
     object shad;

     if (pl->ring_shad()) return 1;
     shad = CO(WEP+"ring_shad");
     shad->SS(TP,0,"ring_shad");
     write("You feel the need for speed.\n");
     return 1;
}

int remove_fun(object pl) {
         if (pl->ring_shad())
          destruct(pl->ring_object());
   return 1;
}

