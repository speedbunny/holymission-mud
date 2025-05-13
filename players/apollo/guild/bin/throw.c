/* command:     throw
 * syntax:      throw <object> at <living>
 * function:    throw an object at a living for damage
 */

int main( string str ) {
  string ob_name, mon_name;
  object next_throw, tmp;

  next_throw = (object)present( "guildsoul", this_player() )->query_next_throw();
  if( next_throw ) {
    printf( "You're too fasciniated watching your previous throw.\n" );
    return 1;
  }
  if( !str ) {
    notify_fail( "Throw what?\n" );
    return 0;
  }
  if( sscanf( str, "%s at %s", ob_name, mon_name ) !=2 ) {
    if( !( tmp = (object)this_player()->query_attack() ) ||
        !present( tmp, environment( this_player() ) ) ) {
      notify_fail( "Throw what?\n" );
      return 0;
    }
    ob_name=str;
  }
  else {
    tmp = present( mon_name, environment( this_player() ) );
    if( !tmp || !living( tmp ) ) {
      notify_fail( "Throw the " + ob_name + " at what?\n" );
      return 0;
    }
  }
  if( environment( this_player() )->query_property( "no_fight" ) ) {
    notify_fail( "It probably wouldn't be an idea to do that here.\n" );
    return 0;
  }
  if( !(next_throw = present( ob_name, this_player() ) ) ) {
    switch(ob_name[0..0]) {
      case "a":
      case "e":
      case "i":
      case "o":
      case "u":
      case "y":
        notify_fail( "You don't have an " + ob_name + " to throw!\n" );
      break;
      default:
        notify_fail( "You don't have a " + ob_name + " to throw!\n" );
      break;
    }
    next_throw=0;
    return 0;
  }
  if( transfer( next_throw, environment( this_player() ) ) ) {
    notify_fail( "You can't throw that!\n" );
    next_throw=0;
    return 0;
  }
  transfer( next_throw, this_player() );
  present( "guildsoul", this_player() )->set_next_throw( next_throw, tmp );
  return 1;
}
