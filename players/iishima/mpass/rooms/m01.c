inherit "room/room";
#include "/players/iishima/mp.h"

void reset(int arg)
{
 set_light(1);
 short_desc="A small forest";
 long_desc =
"This section of the forest is very dark.  You can barely see in front of\n"+
"yourself. The forest floor is covered with rocks, dirt, and twigs.  The\n"+
"trees around you slowly sway from side to side and the wind gently blows.\n"+
"You hear sounds of animals walking though the forest searching for food.\n\n";
  dest_dir=({
           });

  property = ({
             });
  items = ({
"trees","The trees are dark and slowly sway back and forth in the wind",
"dirt","The dirt is very cold. You think you can see bear tracks",
"rocks","There white rocks and pebbles everywhere",
"twigs","These twigs fell from the many trees around",
"tracks","These tracks were probably made by a bear",
"floor","The forest floor is made of dirt, twigs, and rocks",
});
    ::reset(arg);
    replace_program("room/room");
}
