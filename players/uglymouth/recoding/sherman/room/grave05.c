#include "../defs.h"

inherit GEN_GRAVE;

int dug;

void reset( int arg ) {
  ::reset( arg );
  dug = 0;

  if( arg ) return;
  short_desc = "At a clean grave with a white marble tomb stone.";
  long_desc = "To your surprise you find yourself standing next to a grave "
    + "that looks clean and well maintained, although there are no traces "
    + "of people having visited it recentl6y. A bright white marble tomb "
    + "stone stands at the head of the grave.\n";
  hidden_dir = ({
    ROOM_DIR + "cemetry4", "south",
  });
  no_obvious_msg = "The gravel path lies directly south of this grave.\n";
  items=({
    "grave", "A clean patch of loose soil. Purple violets are growing in "
      + "each corner",
    "violets", 
      "Small purple flowers with a yellow heart. They look common enough",
    "soil", "Although it's the same brown clay, it looks somewhat lighter "
      + "and dryer here",
    "tomb stone", "Under a gold inlaid pentagram pointing down you read "
      + "\"Sergej\". The 'R.I.P. and age have crudely been chiselled away "
      + "at a later time",
    "pentagram", "It's of pure gold and seems to radiate a little",
  });
  property = "Sergej";
}

int do_dig() {
  object obj;
  if( present( "ghost", TO ) ) {
    notify_fail( "The ghost won't let you disturb its grave.\n" );
    return 0;
  }
  if( dug == 2 ) return ::do_dig();  // ghost defeated and money found.
  if( dug == 1 ) {                   // ghost defeated, digging for treasure.
    obj = clone_object( "/obj/money" );
    obj->set_money( 1000 + random( 500 ) );
    move_object( obj, TO );
    printf( "As you dig deep into the dark clay, you notice something "
      + "glitter in the dirt.\n" );
    say( sprintf( "%s digs up some shiny little things from the grave.\n", 
      TPSHORTN ), TP );
    dug = 2;
    return 1;
  }
  obj = clone_object( "/obj/monster" );  // so much for Resquiescat In Pacem.
  obj->set_name( "ghost" );
  obj->set_short( "A ghost" );
  obj->set_long( "A pale white, somewhat transparent appearance of a young "
    + "man. It floats about ten centimeters above its grave. Its vague "
    + "facial features seem to express a mixture of horror, despair and "
    + "anger.\n" );
  obj->set_level( 18 );
  obj->set_race( "undead" );
  obj->set_hp( 700 );
  obj->set_al( -200 );
  obj->set_wc( 18 );
  obj->set_ac( 12 );
  obj->set_aggressive( 1 );
  obj->set_chance( 15 );
  obj->set_spell_mess1( 
    "Ghost reaches with its ethereal hand for the heart of its victim" );
  obj->set_spell_mess2( 
    "Ghost reaches with its ethereal hand for your heart, squeezing it." );
  obj->set_spell_dam( 25 );
  move_object( obj, this_object() );
  dug = 1;
  printf( "As you dig in the grave, a pale white shape rises up through "
    + "the earth!\n" );
  say( sprintf( "As %s digs in the grave, a pale white shape rises from "
    + "the grave.\n", TPSHORTN ), TP );
  return 1;
}
