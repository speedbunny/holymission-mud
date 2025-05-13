#include "../defs.h"

inherit "obj/thing";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "sign" );
  set_alias( "wooden sign" );
  set_short( "A wooden sign" );
  set_long( "The moulds have badly affected the sign itself. You could "
    + "easily tear it off the pole it is attached to and which is in a "
    + "reasonably good shape. You can barely make out the writing on the "
    + "sign, which must once have been written in bright red paint.\n" );
  set_weight( 10 );
  set_value( 0 );
}

void init() {
  ::init();
  add_action( "do_read", "read" );
  add_action( "do_tear", "tear" );
  add_action( "do_sharpen", "sharpen" );
}

int do_read( string str ) {
  if( str != "sign" ) {
    notify_fail( "What do you want to read?\n" );
    return 0;
  }
  if( query_name() != "sign" ) {
    notify_fail( "There is nothing on it to read.\n" );
    return 0;
  }
  printf( "Beware O ye that seeks to pass!\n"
    + "Know ye that the land beyond is burdened with a heavy curse.\n"
    + "The land is sealed to protect the outside world, and if ye fail,\n"
    + "know that the world will be protected from you as welle!\n"
    + "May thy gods have blessed thee, if ye tread yonder...\n" );
  return 1;
}

int do_tear( string str ) {
  if( str != "sign off pole" && str != "sign off the pole" &&
      str != "wooden sign off pole" && str != "wooden sogn off the pole" ) {
    notify_fail( "Tear what off what?\n" );
    return 0;
  }
  if( query_name() != "sign" ) return 0;
  set_name( "pole" );
  set_alias( "wooden pole" );
  set_short( "A wooden pole" );
  set_long( "A wooden pole that once used to carry a sign.\n"
    + "You wonder why you should carry such a piece of useless "
    + "wood around.\n" );
  printf( "The sign falls apart in tiny splinters as you tear "
    + "it off its pole.\n" );
  say( sprintf( "%s tears the sign off its pole.\n", TPSHORTN ), TP );
  return 1;
}

int do_sharpen( string str ) {
  string edge;

  if( query_name() != "pole" ) return 0;
  if( !str ) return 0;
  if( sscanf( str, "pole with %s", edge ) != 1 ) {
    notify_fail( "Sharpen what with what?\n" );
    return 0;
  }
  if( !present( edge, TP ) ) {
    notify_fail( "You don't have such an item.\n" );
    return 0;
  }
  if( member_array( edge, ({ "axe", "sword", "knife", "dagger", "dirk", 
      "cutlass", "halberd", "broken bottle", "shovel", }) ) == -1 ) {
    notify_fail( "The " + edge + " has not enough of en edge to it.\n" );
    return 0;
  }
  set_name( "stake" );
  set_alias( "wooden stake" );
  set_short( "A wooden stake" );
  set_long( "A wooden stake, cut from an old wooden pole. It's got an "
    + "irregular, but fairly sharp point. It's no good as a weapon, but "
    + "it would do as a peg. Maybe you can even think of other uses "
    + "for it.\n" );
  printf( "You sharpen the pole. It makes a fine stake now.\n" );
  say( sprintf( "%s cuts the end of a pole into a sharp point with %s %s.\n",
    TPSHORTN, TPPOS, edge ), TP );
  return 1;
}

int query_quest_item() { return 1; }
