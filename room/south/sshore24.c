
/* sshore24.c */

inherit "/room/south/shore";
#include "_defs.h"


string add_long()
{
     return (
	  "An earthy trail leads into the forest to the east. The shore\n" +
	  "of the Crescent Lake continues southeast and west.\n");
}

string *add_dirs()
{
   return ({
   PATH+"sforst49","east",
   PATH+"sshore23","west",
   PATH+"sshore25","southeast",
   });
}

void get_objects()
{
   object rod;
   
   if (!present("rod",this_object()))
   {
       rod = clone_object("/obj/treasure");
       rod->set_name("fishing rod");
       rod->set_short("fishing rod");
       rod->set_alias("rod");
       rod->set_value(80);
       rod->set_weight(1);
       rod->set_long(
       "A long brown bambus stick with a long cord fixed to it.\n"+
       "On the one end of the cors is an imitation of a fly and\n"+
       "a big hook. It looks like you can 'fish' with it on the shore.\n");
       move_object(rod,this_object());
   }
}

   

