#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;

  set_light( 0 );
  short_desc = "In the second cellar floor of a black tower.";
  long_desc = "You have climbed to the second cellar of the black tower. "
    + "Rusty shackles in the wall indicate that this used to be the tower's "
    + "prison room. The ground is covered with soaking wet clay. A fragile "
    + "wooden ladder leads up through a hole in the ceiling.\n";
  dest_dir = ({
    ROOM_DIR + "vtower07", "up",
  });
  items=({
    "cellar", "This is the former prison. It looks like the last time it "
      + "has been used was not even that long ago",
    "shackles", "The thin layer of rust tries to hide the fact that these "
      + "are still strong shackles, ready to receive their guest",
    "prison", "A typical prison: dark, wet and smelly",
    "ground", "As you poke into the clay, you notice that the layer is only "
      + "about ten centimeters thick. Beneath it lies solid rock",
    "clay", "Dark brown, wet, sticky clay. Where have you seen it before..",
  });
}

void init() {
  ::init();
  add_action( "do_search", "search" );
}

int do_search( string str ) {
  if( member_array( str, 
    ({ "clay", "ground", "footsteps", "wall" }) ) == -1 ) return 0;
  switch( str ) {
    case "clay":
    case "ground":
      printf( "You notice some footsteps in the clay that do not "
        + "belong to your boots.\n" );
      items += ({ "footsteps", "They are from a good pair of shoes. In the "
        + "dark you can not see well where they lead" });
    break;
    case "footsteps":
      printf( "As you follow them carefully, they seem to disappear into " 
        + "the wall!\n" );
    break;
    case "wall":
      printf( "You notice a sliding panel in the north wall. If you push "
        + "it, you can enter into the space beyond.\n" );
      add_action( "do_push", "push" );
    break;
  }
  say( sprintf( "%s searches around for some clues.\n", TPSHORTN ), TP );
  return 1;
}

int do_push( string str ) {
  if( member_array( str, ({ "sliding panel", "panel", "wall" }) ) == -1 )
    return 0;
  printf( "As you push the sliding panel, it turns and sweeps you into "
    + "the space beyond.\n" );
  say( "A sudden gust of chilly air blows into your face.\n", TP );
  TP->move_player( "into the dark#" + ROOM_DIR + "vtower09" );
  return 1;
}

