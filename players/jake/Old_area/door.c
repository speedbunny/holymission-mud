#include "std.h"
#include "/obj/door.h"

object obj_1, obj_2;  /* MAKE_DOORS macro. */
object key, keri;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg){
   if(!arg){
        if(!keri){
           keri=clone_object("players/jake/monster/keri");
move_object(keri,this_object());
MAKE_KEY(key,"small","metal");
           move_object(key,keri);
	  }
MAKE_DOORS("players/jake/door","west","players/jake/office2","east","small","metal","RD office.\n",1,1,1);

	return;
   }
	obj_1->set_closed(1);
	obj_1->set_locked(1);
	obj_1->set_both_status(1);

   if(!keri){
        keri=clone_object("players/jake/keri");
move_object(keri,this_object());
MAKE_KEY(key,"small","metal");
move_object(key,keri);
     }
}
ONE_EXIT("players/jake/eastroom","east",
"This is the RA office",
"Keri the RA is on duty here.\n",1)
