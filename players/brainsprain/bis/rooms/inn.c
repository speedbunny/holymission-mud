inherit "/players/brainsprain/misc/inn.c";
#include "/players/brainsprain/bis/bisdef.h"

int read (string str){
       if (str != "list"){
         write ("Read What?\n");
         return 1;
       }
       else {
         write (
                "Type 'rest' or 'sleep' in order to begin healing.\n"+
		"Type 'stand' or 'wake' to stop healing.\n"+
		"Warning: You will be very relaxed while resting.\n");
         return 1;
       }
     }

void reset(int arg) {
  ::reset();
  short_desc = "Towpath Inn";
  long_desc =
"This is the Towpath inn.  A swarthy man stands behind the counter and "+
"busily shuffles papers.  Behind his is a key rack containing keys to "+
"rooms.  You can come here to heal.  It will cost you though.  There is "+
"A convienent list telling how you can heal.\n";
  set_light(1);
  set_rate();
  set_cost(1);
  set_owner("Shop Keeper");
  dest_dir = ({
    br+"/tr-11","east",
  });
items = ({
    "papers","Several outstanding bills",
    "rack","A large key rack",
    "list","Try reading it",
  });
}
  void init (){
  ::init();
    add_action("cmd_hook","",1);
    add_action("read","read");
  }
