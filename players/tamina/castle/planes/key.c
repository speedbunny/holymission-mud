/*  
   This is Elemental Tamina's Key for the Elemental Planes.
   It provides protection from Elements on all Planes...
*/

inherit "obj/thing";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  ::reset(arg);
  if (arg) return 0;

  set_name("Elemental Key");
  set_alias("key");
  set_short("Elemental Key");

}

string query_auto_load()
{
  return "/players/tamina/castle/planes/key:";
}

int get()
{
  return 1;
}

int drop()
{
  return 1;
}

int id(string str)
{
  return str == "silver necklace" || str == "necklace" ||  /* Air */
         str == "diamond ring" || str == "ring"  ||        /* Earth */
         str == "pipe" ||                                  /* Water */
         str == "ruby";                                    /* Fire */
}

