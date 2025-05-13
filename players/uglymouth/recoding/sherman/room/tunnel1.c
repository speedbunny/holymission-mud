#include <doorroom.h>
#include "../defs.h"

inherit DOOR_ROOM;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_light( 1 );
  short_desc = "At a dead end in a damp tunnel, dug out in the clay soil.";
  long_desc = "You find yourself at the dead end of a damp and muddy "
    + "tunnel. Not too long ago people must have dug this tunnel into the "
    + "clay soil and hardened its walls and ceiling to give them greater "
    + "strength. Now the walls are beginning to grow wild patches of "
    + "various moulds and slimes.\n";
  dest_dir = ({
    ROOM_DIR + "tunnel2", "east",
  });
  hidden_dir = ({
    ROOM_DIR + "entrance", "up",
  });
  items = ({
    "tunnel", 
      "A clay tunnel in the hills. It's in a reasonably well condition",
    "dead end", 
      "That's what it is... You'd better head back where you came from",
    "soil", "Dried dark brown clay gone humid again",
    "clay", "Just dirty, sticky clay, of the darkest brown you've ever seen",
    "walls", "Cold humid dark brown walls. Slimes have covered all "
      + "irregularities it may once have shown",
    "irregularities", 
      "You would have to search them underneath the slimy surface",
    "slimes", "Sickly yellow patches of slime are spread out over the walls",
    "moulds", "Pale green hairy moulds grow between the slimes",
    "ceiling", 
      "Somehow it has remained entirely free of any moulds or slimes",
    "trapdoor", "dummy door description",
  });
  smell = "The air is filled with the rotting smell the moulds and "
    + "slimes produce.\n";
}

void init() {
  ::init();
  add_action( "do_search", "search" );
}

void long( string str ) {
  if( !str ) return ::long();
  if( query_door_status( "trapdoor" ) == DOOR_CLOSED ) {
    if( str == "trapdoor" ) {
      printf( "You see nothing of interest.\n" );
      return;
    }
    return ::long( str );
  }
  switch( str ) {
    case "ceiling":
      printf( "In the ceiling an open trapdoor, leading up, lets in "
        + "some light.\n" );
    break;
    case "trapdoor":
      printf( "A well camouflaged trapdoor has slid away to reveal "
        + "a way up.\n" );
    break;
    default:
      return ::long( str );
    break;
  }
}

void set_door_status( string door_id, string how ) {
  ::set_door_status( door_id, how );
  how == DOOR_OPEN ? set_light( 1 ) : set_light( -1 );
}

int do_open( string str ) {
  return 0;
}

int do_close( string str ) {
  return 0;
}

int do_search( string str ) {
  string door_status;

  if( str != "ceiling" && str != "walls" && str != "irregularities" &&
      str != "slimes" && str != "surface" && str != "slimy surface" )
    return 0;
  if( str == "ceiling" ) {
    if( query_door_status( "trapdoor" ) == DOOR_OPEN )
      printf( "An open trapdoor in the ceiling, leading up, lets in "
        + "fresh air.\n" );
    else printf( "You feel the outlines of a square patch in "
      + "the ceiling.\n");
    return 1;
  }
  door_status = query_door_status( "trapdoor" );
  set_door_status( "trapdoor",
    door_status == DOOR_CLOSED ? DOOR_OPEN : DOOR_CLOSED );
  call_other( query_other_door( "trapdoor" ), "set_door_status", "trapdoor",
    door_status == DOOR_CLOSED ? DOOR_OPEN : DOOR_CLOSED );
  tell_room( query_other_door( "trapdoor" ),
    "Something rustles near the darkest bush.\n" );
  printf( "You press your hand through the disgusting layer of slimes "
    + "and start examining the clay behind it. Then your hand touches a strange "
    + "metal plate. You hear a grinding sound and suddenly %s",
    door_status == DOOR_OPEN ? "everything is dark again.\n" :
      "daylight falls in from above.\n" );
  say( sprintf( "%s disgustingly feels the slimes on the wall with "
    + "bare hands. You hear a grinding sound and suddenly %s",
    this_player()->query_short_name(),
    door_status == DOOR_OPEN ? "everything is dark again.\n" :
      "daylight falls in from above.\n" ), this_player() );
  return 1;
}
