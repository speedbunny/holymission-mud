

/* sshore20.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "Earty trails lead into the forest to the north and west. The\n" +
	  "shore of the Crescent Lake continues northeast and southwest.\n");
}

string *add_dirs()
{
    return ({
    PATH+"sforst28","north",
    PATH+"sforst30","west",
    PATH+"sshore21","northeast",
    PATH+"sshore19","southwest",
    });
}

