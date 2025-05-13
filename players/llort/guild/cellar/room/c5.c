/* 971010, Uglymouth: Recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

#include "../cellar.h"

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
  long_desc = "You are in the dark cellar of the Mages Tower. "
    + "It's cold and wet here. The smell of cheese is "
    + "now so strong, that you can feel some drops of "
    + "salive running down your mouth. There is a wooden "
    + "shelf on the western wall. The corridor leads through a door "
    + "to the east.\n";
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
  set_door_dependent( "door", "/players/llort/guild/cellar/room/c6" );
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

