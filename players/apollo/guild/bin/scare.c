
/*=====================================================================
	Scream (monster or player) --- Allows the player to scare
		whomever into stopping the battle.
======================================================================*/


int main( string str ) {

  object ob;

  ob = present( str, environment( this_player() ) );

  if( !ob ) {
	write( "Sorry, but " + capitalize(str) + " is not here to scare!\n" );
	return 1;
  }

  if(!(this_player()->query_level()-ob->query_level()+50) > random(100)) {
    write( capitalize(str) + " withstood your attempt.\n" );
    say( this_player()->query_name() + " tried to scare " +
	capitalize(str) + " into a small cowardly heap!\n" );
    tell_object( ob, this_player()->query_name() + " tried to scare " +
	"you into a cowardly heap of flesh, but you withstood!\n" );
    return 1;
  }

  ob->stop_fight();
  ob->stop_fight();
  ob->stop_hunter(1);
  ob->set_tame(this_player());

  this_player()->stop_fight();
  this_player()->stop_fight();
  this_player()->stop_hunter(1);

  say( this_player()->query_name() + " scared " + capitalize(str) + ".\n" );
  write( "You scared " + capitalize(str) + ".\n");
  tell_object( ob, this_player()->query_name() + " scared you!\n" );
  return 1;
}
