inherit "obj/weapon";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "staff of poisoning" );
  set_alias( "staff" );
  set_short( "A staff of poisoning");
  set_long( "This wicked, gnarled staff drips at its tips with drops of "
    + "some evil greenish fluid.\n" );
  set_class( 19 );
  set_weight( 2 );
  set_value( 3000 );
  set_hit_func( this_object() );
}

int weapon_hit( object ob ) {
  if( random( 100 ) < 25 ) {
    printf( "The staff hits your opponent.\n" );
    say( "The staff hits " + ob->query_name() + ".\n" );
    return 20;
  }
  if( random( 100 ) < 25 ) {
    tell_object( ob, "The staff of poison hits you and green drops of "
      + "fluid sip into your clothes. It burns like hell!\n" );
    ob->add_poison( 25 );
  }
  return 0;
}

int weapon_class() {
  if(environment() && environment()->id( "lich ") ) return 100;
  return ::weapon_class();
}

