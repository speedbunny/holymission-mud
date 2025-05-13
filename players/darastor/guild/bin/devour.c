/* command:     devour
 * syntax:      devour corpse
 * function:    heal by eating corpse
 */

int main( string str ) {
  int heal;
  object ob;

  if( str != "corpse" ) {
    notify_fail( "What do you want to devour?!?\n" );
    return 0;
  }
  if( !( ob = present( "corpse", environment( this_player() ) ) ) )
    ob = present( "corpse", this_player() );
  if( !ob ) {
    notify_fail( "There isn't a corpse to devour!\n" );
    return 0;
  }

  heal = (int)ob->query_weight() * 3;
  if( this_player()->eat_food( heal / 6 ) ) {
    this_player()->heal_self( heal / 2 + random( heal ) );
    printf( "You devour the corpse in one gulp.\n" );
    say( sprintf( "%s devours the corpse in one gulp, spilling blood and "
      + "entrails everywhere. You feel quite disgusted at the frankly "
      + "rather grisly sight.\n", this_player()->query_name() ) );
    destruct( ob );
    call_out( "burp", 4 + random( 10 ), this_player() );
  }
  return 1;
}

void burp( object player ) {
  tell_object( player, "You burp rudely.\n" );
  lsay( "burps", "rudely.\n", player, player );
}

