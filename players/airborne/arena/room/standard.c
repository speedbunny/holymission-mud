/* ************************************************************************
   This is a file in the arena. Do not make changes without commenting both
   at the top of this file and in the /players/airborne/arena/CHANGES.made
   file. This code is very intricate, and we need to know what is going on
   if we are to maintain it.  - Airborne and Blade
   ************************************************************************ */

/* ************************************************************************
   Changes:

   ************************************************************************ */

#define X 0
#define Y 0

#include "/players/airborne/arena/arena_define.h"
#include ARENA_FUNCTIONS
inherit ARENA_ROOM;

object master_obj;

long(){
  write("blah\n");
  if(this_object()->query_perimeter()) 
    write(this_object()->query_perimeter_desc());
}
