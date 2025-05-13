inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {
::reset(arg); 

  if(arg) return;
  set_light(1);
short_desc="A Village";
long_desc=
"You have entered a small village. You notice small huts to your left\n" +
"and right as you walk down what seems to be the central path through\n" +
"the village. You can hear the sounds of small children playing off in\n" +
"the distance. A small dog stops quickly to consider you, then quickly\n" +
"runs into one of the huts.\n" +
"\n";

dest_dir=({
    PATH+TRIBE+"a02.c", "east",
    PATH+NORTH+"a103.c", "out",
});
items=({
  "path", "You see a well worn dirt path",
  "dog", "You see a small brown dog in front of you wagging its tail",
  "hut", "You notice that the hut is made of deer skin and is big enough to hold\n" +
"a small family.\n",
});

smell="All of the dust in the air causes you to sneeze violently.";

replace_program ("room/room");
}
