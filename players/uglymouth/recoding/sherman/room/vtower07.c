#include "../defs.h"

inherit "room/room";

status *chest_open;

void reset( int arg ) {
  clone_list = ({
    1, 1, "andrevitch the vampire", MON_DIR + "andrevit", 0,
    1, 1, "natanya the child vampire", MON_DIR + "natanya", 0,
  });
  chest_open = ({ 0, 0 });
  ::reset( arg );
  if( arg ) return;

  set_light( 0 );
  short_desc = "In the cellar floor of a black tower.";
  long_desc = "You have ended up in the cellar of the black tower. This room "
    + "once served as the kitchen. A big fireplace has been built into the "
    + "northeast part of the wall. Apart from a big barrel and two stone "
    + "chests built into the wall, the room is empty. A spiraling flight of "
    + "stairs leads up.\n";
  dest_dir = ({
    ROOM_DIR + "vtower02", "up",
  });
  hidden_dir = ({
    ROOM_DIR + "vtower08", "down",
  });
  items=({
    "cellar", "The cellar used to be a gathering place for the servants",
    "kitchen", "The kettle in the fireplace reminds of its former function",
    "fireplace", "Underneath a thick layer of soot you notice it's made of "
      + "black marble",
    "kettle", "A copper kettle. It turned green long ago",
    "wall", "The underground wall forms the foundation of the tower",
    "barrel", "It is filled to the rim with some lukewarm dark red fluid",
    "fluid", "Urgh! You are looking at about a hundred liters of blood",
    "chests", "Choose the left chest or the right chest",
    "chest", "Choose the left chest or the right chest",
    "left chest", "dummy left chest description",
    "right chest", "dummy right chest description",
    "tower", "You are inside it",
    "stairs", "A wide, spiralling flight of stairs made of black stones. "
      + "In the little light they cast long shadows",
    "shadows", "The jagged shadows of the stairs darken towards the edges "
      + "of the room. The darkest shadows are in the corners",
    "edges", "Your light reveals nothing of interst",
    "darkest shadows", "As you bring over your light source you notice "
      + "a small ladder leading down through a hole in the ground",
  });
}

void init() {
  ::init();
  add_action( "do_open", "open" );
  add_action( "do_close", "close" );
}

void long( string str ) {
  int i;

  if( !str ) return ::long();
  if( str != "left chest" && str != "right chest" ) return ::long( str );
  i = member_array( explode( str, " " )[0], ({ "left", "right" }) );
  if( !chest_open[i] ) {
    printf( "A simple wooden chest. It probable used to contain the wood "
      + "for the fireplace. It is closed.\n" );
    return;
  }
  i ? printf( "As you look into the chest your eyes cannot focus in the "
      + "darkness they perceive. You notice the top rungs of a ladder "
      + "leading down through this bottomless chest.\n" ) :
    printf( "A simple wooden chest. It probably used to contain the wood "
      + "for the fireplace. With its lid open you look upon the remains of "
      + "the industrious work of a family of wood worms.\n" );
}

int move( string str ) {
  if( !str ) str = query_verb();
  if( str == "down" ) {
    if( !chest_open[1] ) return 0;
    if( present( "vampire" ) ) {
      printf( "Your path is blocked by %s.\n",
        present( "vampire" )->short() );
      return 1;
    }
  }
  return ::move( str );
}

int do_open( string str ) {
  if( str != "chest" && str != "left chest" && str != "right chest" ) {
    notify_fail( "Open what?\n" );
    return 0;
  }
  switch( str ) {
    case "chest":
      notify_fail( "Open the left chest or the right chest?\n" );
    return 0;
    case "left chest":
      if( chest_open[0] ) {
        notify_fail( "The left chest already is open.\n" );
        return 0;
      }
      chest_open[0] = 1;
      printf( "You open the left chest.\n" );
      say( sprintf( "%s opens the left chest.\n", this_player()->query_name() ) );
    return 1;
    case "right chest":
      if( chest_open[1] ) {
        notify_fail( "The right chest already is open.\n" );
        return 0;
      }
      chest_open[1] = 1;
      printf( "You open the right chest.\n" );
      say( sprintf( "%s opens the right chest.\n", this_player()->query_name() ) );
    return 1;
  }
}

int do_close( string str ) {
  if( str != "chest" && str != "left chest" && str != "right chest" ) {
    notify_fail( "Close what?\n" );
    return 0;
  }
  switch( str ) {
    case "chest":
      notify_fail( "Close the left chest or the right chest?\n" );
    return 0;
    case "left chest":
      if( !chest_open[0] ) {
        notify_fail( "The left chest already is closed.\n" );
        return 0;
      }
      chest_open[0] = 0;
      printf( "You close the left chest.\n" );
      say( sprintf( "%s closes the left chest.\n", this_player()->query_name() ) );
    return 1;
    case "right chest":
      if( !chest_open[1] ) {
        notify_fail( "The right chest already is closed.\n" );
        return 0;
      }
      chest_open[1] = 0;
      printf( "You close the right chest.\n" );
      say( sprintf( "%s closes the right chest.\n", this_player()->query_name() ) );
    return 1;
  }
}
