

/* sshore26 */

inherit "/room/south/shore";
#include "_defs.h"

string add_long() 
{
          return (
	  "An earthy trail leads into the forest to the north. The shore\n" +
	  "of Crescent Lake continues northeast and northwest. To the\n" +
	  "southeast, a 'stone bridge' used to cross over to the Isle of\n" +
          "the Magi.\n");
}

string *add_items()
{
   return ({
   "bridge","The bridge looks old, but still good enough to use", 
   "stone bridge","The bridge looks old, but still good enough to use", 
   });
}

string *add_dirs()
{
   return ({
   PATH+"sforst46","north",
   PATH+"sshore27","northeast",   
   PATH+"sshore25","northwest",   
   PATH+"sislnd1","southeast",
   });
}
