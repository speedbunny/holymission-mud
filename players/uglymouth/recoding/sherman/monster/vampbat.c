#include "../defs.h"

inherit "obj/monster";

void reset( int arg ) {
  ::reset(arg);
  if (arg) return;

  set_name( "vampire bat" );
  set_alias( "bat" );
  set_short( "A vampire bat" );
  set_long( "This creature of the night looks like the big cousin of the "
    + "common bat. With its improved sonar and two prolonged corned teeth "
    + "they make quite formidable opponents, specially if they manage to "
    + "dive out of the air like a surprise bombardment.\n" );
  set_level( 5 );
  set_race( "bat" );
  set_al( -20 );
  set_ac( 3 );
  set_wc( 7 );
  set_aggressive( 1 );
  set_chance( 33 );
  set_spell_mess1( "Bat holds on to his victim and drains some blood" );
  set_spell_mess2( "Bat holds on to you and drains some blood" );
  set_spell_dam( 15 );
}
