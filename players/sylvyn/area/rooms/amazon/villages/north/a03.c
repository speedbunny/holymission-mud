inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"


void reset(int arg) {
::reset(arg);

  if(arg)return;

  set_light(1);

  short_desc="A Village";
  long_desc=
"You have entered what appears to be the central hub of the village. You\n" +
"notice that there are exits in every direction. There is a large fire pit\n" +
"in the center of this small area. Suddenly you notice that most of the\n" +
"villagers have gathered around you. Everything has become quiet. You have\n" +
"a strange feeling something bad is about to happen.\n" +
"\n";

     dest_dir=({
       PATH+TRIBE+"a09.c", "north",
       PATH+TRIBE+"a11.c", "northeast",
       PATH+TRIBE+"a04.c", "east",
       PATH+TRIBE+"a10.c", "southeast",
       PATH+TRIBE+"a08.c", "south",
       PATH+TRIBE+"a06.c", "southwest",
       PATH+TRIBE+"a02.c", "west",
       PATH+TRIBE+"a07.c", "northwest",
});

  items=({
   "pit", "A large blackened fire pit. You notice small wifts of smoke rising\n" +
"from the remains. You notice the remains look famailiar, almost human.\n",
  "hub", "It appears to be the central hub of the village.",

});

smell="It smells like smoke.",

replace_program("room/room");

}
