/* 971010, Uglymouth: Recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

#include "/players/saffrin/area/tower/quest/cellar.h"

object ob;
int i;

void reset( int arg ) {
  clone_list = ({
    1, 1, "big rat", MONST + "big_rat", 0,
  });
  ::reset( arg );
  if( arg ) return;
  set_light( 0 );
  short_desc = "In a cellar";
  long_desc = "You are in the dark and musty cellar of the Mage Tower.  "
    + "The walls make it cold in here and you hear the sound of dripping "
    + "water.  The smell of cheese meets your nose, making your mouth water.  "
    +"There is a small wooden shelf hanging along the west wall.  "
    +"There is a wooden cellar door to the east.\n";
  dest_dir = ({
    ROOM + "c6", "east",
  });
  items = ({
    "vault","An old oak-wooden vault",
    "shelf","A brown wooden shelf",
    "wall","A grey stone wall",
    "walls","Grey stone walls",
    "bottom","A dark stone bottom",
    "door", "door dummy description",
  });
  set_door( "door" );
  set_door_dependent( "door", ROOM+"c6");
} 

void init() {
  ::init();
  add_action( "do_search", "search" );
}

int do_search( string str ) {
  object ob,cheese;

  ob=present( "rat", this_object() );
  if( str != "shelf" || str != "in shelf" ) return 0;
  printf( "You found a piece of cheese.\n" );
  cheese = clone_object( OBJ+"cheese" );
  if( transfer( cheese, this_player() ) ) {
    printf( "You are carrying too much.\n" );
    destruct( cheese );
    return 1;
  }
  if( ob ) {
    this_player()->attacked_by(ob);
    return 1;
  }
  return 1;
}

