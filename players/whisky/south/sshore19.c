

/* sshore19.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "Earthy Trails lead into the forest to the north and south. The\n" +
	  "shore of Crescent Lake continues northeast and southeast.\n");
}

string *add_dirs()
{
   return ({
   PATH+"sforst30","north",
   PATH+"sforst31","south",
   PATH+"sshore20","northeast",
   PATH+"sshore18","southeast",
   });
}

