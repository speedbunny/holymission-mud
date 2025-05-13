inherit "/obj/thing";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "bottle of holy water" );
  set_alias( "bottle" );
  set_alt_name( "holy water" );
  set_short( "A bottle of holy water" );
  set_long( "This is a fragile bottle of clear glass. It is filled with "
    + "holy water, blessed by a devout priest. It is rumoured to have "
    + "drastic effects on the undead, if you throw it at them.\n" );
  set_weight( 3 );
  set_value( 50 );
}

void init() {
  ::init();
  add_action( "do_drink", "drink" );
  add_action( "do_throw", "throw" );
}

int do_drink( string str ) {
  object curse;

  if( !id( str ) ) return 0;
  if( query_name() == "empty bottle" ) {
    notify_fail( "This bottle is empty...\n" );
    return 0;
  }
  printf( "You drink the whole bottle of holy water.\n" );
  say( sprintf( "%s drinks a whole bottle of holy water.\n" );
  set_name( "empty bottle" );
  set_alias( "bottle" );
  set_alt_name( 0 );
  set_short( "An empty bottle.\n" );
  set_long( "This is an empty bottle, made of clear glass.\n" );
  set_value( 5 );
  set_weight( 1 );
  this_player()->update_weight();
  if( curse = present( "vampire_curse", this_player() ) &&
      !random( 10 ) ) {
    printf( "Suddenly you feel the curse of vampirism being lifted "
      + "from you!\n" );
    say( sprintf( "%s suddenly seems to carry less of a burden.\n",
      this_player()->query_name() ), this_player() );
    curse->lift_curse();
    return 1;
  }
  printf( "It tastes just like ordinary water.\n" );
  return 1;
}

int do_throw( string str ) {
  string what, whom;
  object target;

  if( !str ) return 0;
  if( sscanf( str, "%s at %s", what, whom ) != 2 ) {
    notify_fail( "Throw what at whom?\n" );
    return 0;
  }
  if( !id( what ) ) {
    notify_fail( "You don't have that to throw.\n" );
    return 0;
  }
  if( !( target = present( whom, environment( this_player() ) ) ) ) {
    notify_fail( "You don't see anyone or anything by that name around.\n" );
    return 0;
  }
  what = lower_case( short() );
  printf( "You throw %s at %s.\n", what, target->query_short_name() );
  tell_object( target, sprintf( "%s throws %s at you. It hurts.\n",
    this_player()->query_short_name(), what ) );
  say( sprintf( "%s throws %s at %s.\n", this_player()->query_short_name(),
    what, target->query_short_name() ), ({ this_player(), target }) );
  if( query_name() == "empty bottle" ) {
    target->hit_player( 3 );
    if( !interactive( target ) ) {
      printf( "%s is offended by that throw and tries to attack.\n" );
      target->init_command( "kill " + this_player()->query_real_name() );
    }
    destruct( this_object() );
    return 1;
  }
  if( (string)target->query_race() != "undead" ) {
    tell_room( environment( this_player() ),
      sprintf( "%s gets soaking wet as the bottle hits %s and breaks.\n",
        target->query_short_name(), target->query_objective() ) );
    target->hit_player( 7 );
    if( !interactive( target ) ) {
      printf( "%s is offended by being and tries to attack.\n" );
      target->init_command( "kill " + this_player()->query_real_name() );
    }
    destruct( this_object() );
    return 1;
  }
  tell_room( environment( this_player() ), sprintf( "%s catches flame as "
    + "the holy water purifies this unholy entity.\n",
    target->query_short_name() ) );
  if( target->id( "vampire" ) target->hit_player( 100 );
  else target->hit_player( 25 );
  if( !interactive( target ) ) {
    printf( "%s is offended by being and tries to attack.\n" );
    target->init_command( "kill " + this_player()->query_real_name() );
  }
  destruct( this_object() );
  return 1;
}

