inherit "/room/room";

#include "path.h"

void reset(int arg) {

     if (!arg) {
	     set_light(1);
	     short_desc = "A path in a very nice beach-village.";
	     long_desc =
             "You are standing on a small path in a beach-village.\n"+
	     "Heat radiates off the sand as you stand at the end of the path. The open "+
             "flaps to the beach hut to the south are blowing in the breeze. To your "+
	     "east stands a sheer faced cliff.\n";
	     dest_dir = ({
		     ROOM+"path3", "west",
                     ROOM+"ncliff", "east",
                     ROOM+"hut7", "south"
 	      });
	    items=({"cliff","A large but not unpassable stone cliff",
            "hut","A small beach hut use to escape the oppressive sun of the beach",
            "sand","White beach sand that seems to get in everything. The sand feels warm under your feet",
             });
             clone_list = ({
		     1, 1, "cart", OBJ+"cart", 0,
             });
	     }
	::reset(arg);
#if 0
        replace_program("/room/room");
#endif

     }

void init () {
  ::init();
//  add_action("do_read","read");
}

int do_read(string str) {
  if(str!="sign") {
	  return 0;
  }
  write("Soft Ice:\n"+
         "Available in various portions:\n"+
         "1. Very small portion :        20 coins \n"+
         "2. Small portion      :        40 coins \n"+
         "3. Big portion        :        60 coins \n"+
         "4. Very big portion   :        80 coins \n"+
         "5. Giant's portion    :       100 coins \n"+
         "Just type 'buy (num)' and the ice will be consumed at once.\n");
  return 1;
}
