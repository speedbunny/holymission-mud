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
// inherit ARENA_ROOM;

object master_obj;

void reset(arg){
  if(arg) return;
  ::reset(arg);

master_obj = find_object(AMASTER);

  set_light(0 + random(3));
  short_desc = "In the arena";
  long_desc = long();
  items = ({
    "wall", query_walldesc,
    "walls", query_walldesc,
    "floor", query_floordesc,
  });
  
return;
}

long(){
  write("blah\n");
  if(this_object()->query_perimeter()) then
     write(this_object()->query_perimeter_desc());
}
