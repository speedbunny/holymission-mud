#include "std.h"
 
int last_time;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

#undef EXTRA_MOVE1
#define EXTRA_MOVE1 \
    if (!this_player()->query_wizard()) { \
     write("That door can only be used by the one who built it.\n"); \
     write("You seem to be stuck here. Sorry.\n"); \
     return 1; \
    }
 
ONE_EXIT("players/kelly/workroom","east","Kelly's Storage room",
   "This is a special storage room from Kelly, normally it shouldn't be "+
   "possible\nto get here.\n",1)

extra_init() {
  add_action("query_time","time");
}

extra_reset(arg) {
  if (!arg) {
     if(find_call_out("clearroom")==-1)
       clearroom();	
  }
}

clearroom() {
object *ob;
int i;

  ob=all_inventory(this_object());
  for (i=0;i<sizeof(ob);i++)
    if (!(living(ob[i]) && !ob[i]->query_npc())) 
      destruct(ob[i]);

  last_time=time();
  call_out("clearroom",3600);
}
   

query_time() {
  int sec;
  sec=3600-time()+last_time;
  write("Room will be clear in "+sec+" seconds.\n");
  return sec;
}

