inherit "room/room";
#include "../harbour.h"


reset (int arg)
{ ::reset(arg);
  if(arg) return 0;

  set_light(1);
  short_desc="Local town habour.",
  long_desc="Local town harbour.\n"+
	"You are standing on the road leading through the eastern harbour.\n"+
	"The sea is particulary rough today and only the brave or the foolish\n"+
	"should make the journey to one of the many destinations and there are\n"+
	"many. Some fisherman are repairing their nets, and people sitting around\n"+
	"the piers drinking ale.  Some of them are sailors, some dock workers, and\n"+
	"a few are Captains. You hear the voice of a very old sailor trying to sell\n"+
	"tickets.\n";

  items=({
	"sailor","You hear his sharp voice : \"Tickets, who wanna buy tickets ?\"",
	"wave","They are really small ones",
	"waves","They are really small ones",
	"wind","HUI ! What a strong boe",
	"boats","You see some people sitting on the bottom and waving"
         });

   smell="The air is a bit salty in here";

    dest_dir=({
	ROOM + "road004","east",
        ROOM + "road0-1","northwest",
		});

       CO("sign");
}
