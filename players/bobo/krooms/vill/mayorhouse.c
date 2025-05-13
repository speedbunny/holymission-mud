#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_light( 1 );
  short_desc = "Inside the mayor's house.";
  long_desc=
	"As you enter the house and look around all that you can see\n"+
	"are an old wooden floor, with a small table and a single chair\n"+
	"next to it. The only other thing is the room is a small beat up\n"+
	"bed that rests in the corner of the room. It is obvious that\n"+
	"the oppulence the mayor demonstrates in his public life is not\n"+
	"the way he handles his private affairs.\n";
  dest_dir = ({
	"/players/bobo/krooms/vill/mayorsgarden","west",
  });
  items = ({
	"chair","A regular old chair.  It doesn't look very comfortable",
	"bed","A small feather mattress over hard planks",
	"door","An ordinary looking wooden door",
  });
  property = ({ "no_clean_up" });
  replace_program( DOOR_ROOM );
}
