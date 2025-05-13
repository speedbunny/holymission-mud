/* 970915, Uglymouth: using /room/doorroom.c and replace_program() now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_light( 1 );
  short_desc = "Inside the mayor's house.";
  long_desc = "It appears that the oppulance of the mayor's house "
    + "outside is not what the mayor wants for his private quarters "
    + "as there is only a chair and a bed inside this single-roomed "
    + "house are a chair and a bed. A door leads back outside.\n";
  dest_dir = ({
    "players/kelly/rooms/vill/mayorsgarden", "west",
  });
  items = ({
    "chair", "A regular old chair. Does not look very comfortable",
    "bed", "Small feather mattress over hard planks",
    "door", "dummy door description",
  });
  property = ({ "no_clean_up" });
  replace_program( DOOR_ROOM );
}
