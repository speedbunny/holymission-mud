/*
 * Author : Uglymouth
 * Date   : 5-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="The village square";
  long_desc="You've arrived at the village square. Main street continues both east\n"
        + "and west from here.  To the south some bushes secure the peace of the\n"
        + "churchyard. North of the square stands 'The Thirsty Treant' pub.\n";
  dest_dir=({PATH+"pub","north",
        PATH+"street4", "east",
        PATH+"square2","west" });
  items=({
        "village square","A wide cobblestone square",
        "square","A wide cobblestone square",
	"main street","A well maintained dirt road, running east-west through the village",
	"bushes","A thornhedge surrounds the churchyard. There are some holes in it",
	"holes","Small holes in the thornhedge you can peek through",
	"pub","There seems to a lot enjoyment inside", });
}

void init() {
  ::init();
  add_action("peek_hedge","peek");
}
/* take a look at the churchyard */
peek_hedge(string str) {
  if(str!="through holes" && str!="holes") return 0;
  write("Through the little hole you catch a glimpse of the churchyard.\n"
    + "A small gravel path runs between ancient tombes. A bunch of fresh flowers\n"
    + "stands at the foot of each tomb. Some person is busy doing something between\n"
    + "the tombs, but you can't get a better look at it from here. \n"
    + "As you stand up again, you notice some people speaking shame of you. \n");
  say(this_player()->query_name() + " peeks shamelessly through the hedge of the churchyard.\n");
  return 1;
}
