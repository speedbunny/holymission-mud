#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT add_action("read_blood","read");

#define WIZ "players/hardware/"
#define PATH WIZ+"safari/"

FOUR_EXIT(WIZ +"recreation","south",
	  PATH+"saf1", "north",
	  PATH+"saf2", "east",
	  PATH+"saf3", "west",
	  "Safari Guide Sation",
	"There is a station here with a sign reading 'Safari'.\n" +
	"There seems to be noone aroung and wilderness lies in\n" +
	"all directions except south. Only the very mangled corpse\n" +
	"of what appears to be once powerful adventur remains.\n" +
	"Something is written in dried blood on the stations side.\n" +
	"This might be important enough to read.\n",1)

read_blood(str) {

  if (str!="blood") return;

  write("The animals are out of control. I could not survive.\n" +
	"BEWARE OF THE WILDL...\n\n" +
	"The writing seems to fade off.\n");
  return 1;
}

