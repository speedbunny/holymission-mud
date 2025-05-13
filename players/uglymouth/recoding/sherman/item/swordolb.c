inherit "obj/weapon";

int charged;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "sword of life blood" );
  set_alias( "sword" );
  set_alt_name( "vampirecountsashyaslayer" );
  set_short( "The Sword of Life Blood" );
  set_long( "This sword is made of mirror-polished dull red steel. Its hilt "
    + "is carved from bone in the shape of a simple cross. At the very tip "
    + "you see the rune '<V'. A small hole is drilled right below it.\n" );
  set_class( 3 );
  set_weight( 15 );
  set_value( 10000 );
  set_hit_func( this_object() );
}

void init() {
  ::init();
  add_action( "do_cut", "cut" );
}

int weapon_hit( object target ) {
  if( target->id( "vampire" ) && (string)target->query_race() == "undead" &&
    charged ) return 51 + random( 100 );
  printf( "You feel that currently this sword is pretty useless in your "
    + "hands. Somehow you get the idea it needs to be charged first.\n" );
  return 0;
}

status query_quest_item() {
  return 1;
}

int do_cut( string str ) {
  if( str != "myself" && str != "myself with sword" &&
      str != "myself with sword of life blood" ) {
    notify_fail( "Cut whom with what?\n" );
    return 0;
  }
  if( (int)this_player()->query_max_hp() < 50 ) {
    notify_fail( "You would kill yourself if you'd do that!\n" );
    return 0;
  }
  if( (int)this_player()->query_hp() <= 50 ) {
    notify_fail( "You would kill yourself if you'd do that!\n" );
    return 0;
  }
  this_player()->hit_player( 40, 7 );
  set_long( "This sword is made of mirror-polished dull red steel. Its hilt "
    + "is carved from bone in the shape of a simple cross. At the very tip "
    + "you see the rune '<V'. In the small hole drilled right below it "
    + "lies a sparkling drop of blood.\n" );
  charged = 1;
  call_out( "decharge", 1800 );
  printf( "As you cut yourself with the sword, you feel a huge amount "
    + "of blood being drained from you all in one go. The wound is healed "
    + "immediately, but you feel exhausted afterwards.\n" );
  say( sprintf( "%s cuts %sself with the Sword of Life Blood.\n",
    this_player()->query_name(), this_player()->query_objective() ) );
  return 1;
}

void decharge() {
  printf( "Suddenly the drop of blood drops out of its hole in the Sword "
    + "of Life Blood. The blade feels heavy and useless again.\n" );
  charged = 0;
  set_long( "This sword is made of mirror-polished dull red steel. Its hilt "
    + "is carved from bone in the shape of a simple cross. At the very tip "
    + "you see the rune '<V'. A small hole is drilled right below it.\n" );
}

