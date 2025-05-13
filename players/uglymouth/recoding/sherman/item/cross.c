#define STD_LONG "This is a small cross made of pure silver. Delicate "\
  "lines are engraved along its sides to give it a simple yet beautiful "\
  "decoration. It feels like a symbol of great devotion, like a "\
  "holy symbol really. At the back is a pin, so you can wear it as "\
  "a broche."

inherit "/obj/armour";

int drain_level;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "silver cross" );
  set_alias( "cross" );
  set_short( "A silver cross" );
  set_long( STD_LONG + "\n" );
  set_weight( 1 );
  set_value( 250 );
  drain_level = 0;
}

int query_quest_item() {
  return 1;
}

int query_drain_level() {
  return drain_level;
}

void drain_evil() {
#ifndef DEBUG
  if( !previous_object()->id( "count_sasha_coffin" ) ) return;
#endif
  if( drain_level < 3 ) drain_level++;
  switch( drain_level ) {
    case 1:
      set_long( STD_LONG + "The top of the cross has turned dull black. "
        + "It feels a little more powerful now as well.\n" );
    break;
    case2:
      set_long( STD_LONG + "The top and the left arm of the cross have "
        + "turned dull black. You feel a definite presence of power in "
        + "the cross now.\n" );
    break;
    case 3:
      set_long( STD_LONG + "The top and both arms of the cross have turned "
        + "dull black. It feels like it holds a strong power now.\n" );
    break;
  }
}

