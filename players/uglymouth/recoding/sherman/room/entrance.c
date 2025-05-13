/*
 * File:        /players/sherman/entrance.c
 * Last update: 970619 Uglymouth recoded this area (see also RECODE.DOC).
 */
#include <doorroom.h>
#include "../defs.h"

inherit DOOR_ROOM;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) {
    tell_room( this_object(),
      "You hear a muffled rustling sound in the bushes.\n" );
    return;
  }
  set_light( 1 );
  short_desc = "At a small hill.";
  long_desc = "You are at the top of a small hill. "
    + "You are surrounded by trees and bushes. The only way out seems "
    + "to be the path by which you entered. It's strangly quiet here!\n";
  dest_dir = ({
    "/room/south/sforst16", "west",
  });
  hidden_dir = ({
    ROOM_DIR + "tunnel1", "down",
  });
  items = ({
    "hill", "The hill is covered with small gnarled trees and bushes",
    "trees", "They have really grown into weird shapes",
    "path", "A narrow dirt path is leading west through the bushes",
    "top", "On the very top of the hill there are some dark brown bushes",
    "bushes", "They form a wild group of almost impenatrable vegetation, "
      + "but on the darkest bush some of the lower leaves seem damaged",
    "leaves", "Small brown leathery leaves. Some have been broken",
    "bush", "Which bush would that be, boss?",
    "darkest bush", "You notice a weathered rope tied around its trunk",
    "rope", 
      "A hemp rope that has seen better times. It's firmly tied to the bush",
    "weathered rope", 
      "A hemp rope that has seen better times. It's firmly tied to the bush",
    "trapdoor", "dummy door description",
    "hole", "You see nothing of interest",
  });

  set_door( "trapdoor" );
  set_door_direction( "trapdoor", "down" );
  set_door_reset( "trapdoor", ({
    "set_door_status", DOOR_CLOSED,
  }) );
  set_invisible_doors( ({ "trapdoor" }) );
  set_other_door( "trapdoor" );
}

void init() {
  ::init();
  add_action( "do_untie", "untie" );
  add_action( "do_pull", "pull" );
}

void long( string str ) {
  if( !str ) return ::long();
  if( query_door_status( "trapdoor" ) == DOOR_CLOSED ) {
    if( str == "trapdoor" ) {
      printf( "You see nothing of interest.\n" );
      return;
    }
    else return ::long( str );
  }
  switch( str ) {
    case "darkest bush":
      printf( "Next to its trunk you notice a trapdoor standing open.\n" );
    break;
    case "trapdoor":
      printf( "A camouflaged trapdoor now reveals a hole in the ground.\n" );
    break;
    case "rope":
    case "weathered rope":
      printf( "Obviously pulling the rope activated the mechanism that " 
        + "opens the trapdoor.\n" );
    break;
    case "hole":
      printf( "A dark hole leads down into a subterranean tunnel.\n" );
    break;
    default:
      return ::long( str );
    break;
  }
}

int do_open( string str ) {
  return 0;
}

int do_close( string str ) {
  return 0;
}

int do_untie( string str ) {
  string what, where;

  if( !str ) return 0;
  if( sscanf( str, "%s from %s", what, where ) != 2 ) {
    notify_fail( "Untie what from what?\n" );
    return 0;
  }
  if( what != "rope" && what != "weathered rope" ) {
    notify_fail( "That doesn't seem to be tied at all.\n" );
    return 0;
  }
  if( where != "bush" && where != "darkest bush" && where != "trunk" ) {
    notify_fail( "The rope doesn't seem to be attached to that.\n" );
    return 0;
  }
  printf( "You cannot quite reach the knot through the many sharp thorns.\n" );
  return 1;
}

int do_pull( string str ) {
  string door_status;

  if( str != "rope" && str != "weathered rope" ) {
    notify_fail( "You may just as well pull someone's nose...\n" );
    return 0;
  }
  door_status = query_door_status( "trapdoor" );
  set_door_status( "trapdoor",
    door_status == DOOR_CLOSED ? DOOR_OPEN : DOOR_CLOSED );
  call_other( query_other_door( "trapdoor" ), "set_door_status", "trapdoor",
    door_status == DOOR_CLOSED ? DOOR_OPEN : DOOR_CLOSED );
  tell_room( query_other_door( "trapdoor" ),
    "A grinding noise is heard from the ceiling.\n" );
  printf( "You pull firmly on the rope.\nYou hear some rustling in the bush.\n" );
  say( sprintf( "%s seems to be pulling at something in the bushes.\n"
    + "Maybe %s wants some bushes for in %s garden at home...\n", 
    TPSHORTN, TPPRN, TPPOS ), TP );
  return 1;
}
