/* 971011, Uglymouth: recoded yo use /room/doorroom.c now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

object spy;

void make_spy();

void reset( int arg ) {
  if( spy && !present( spy ) )
    spy->move_player( "caught by the secret police#"
      + file_name( this_object() ) );
  if( !spy ) make_spy();
  ::reset( arg );
  if( arg ) return;
  set_light(1);
  short_desc = "A barren cell";
  long_desc = "Shackles and chains cover the walls and ceiling. "
    + "This small room appears to be used by the Secret Police to "
    + "hold spies and dangerous criminals. A solid steel cell door "
    + "bars your way to freedom.\n";
  dest_dir = ({
    "players/padrone/secret_police/interrogation_room", "east",
  });
  items = ({
    "door", "Try cell door",
    "cell door", "dummy door description",
  });
}

void make_spy() {
  spy = clone_object("obj/monster");
  spy->set_name( "spy" );
  spy->set_alias( "enemy spy" );
  spy->set_short( "An enemy spy" );
  spy->set_long( "This is enemy spy has been arrested by the Secret Police. "
    + "His shifty, devious eyes dart about quickly.\n" );
  spy->set_level( 3 );
  spy->set_hp( 100 );
  spy->set_al( -300 );
  spy->set_male();      
  spy->set_spell_mess1( "As the spy kicks at his opponent, "
    + "you notice a tiny dagger in his boot tip." );
  spy->set_spell_mess2( "The spy kicks you with a dagger-tipped boot." );
  spy->set_chance( 20 );
  spy->set_spell_dam( 20 );
  spy->load_chat( 10, ({
    "The enemy spy glares at you.\n",
    "The enemy spy says nothing.\n",      
  }) );
  spy->set_match( this_object(), ({
    ({ "handle_say", 0 }),         // function
    ({ "says:", "tells you:" }),   // type
    ({ "", " " }),                 // match
  }) );
  move_object( spy, this_object() );
}

void handle_say( string str ) {
  string who, junk;
  object client;

  sscanf( str, "%s %s", who, junk );
  client = present( lower_case( who ), environment( spy ) );
  if( !client ) return;
  say( "The spy says: You lying dog!\n" );
  spy->attacked_by( client );
}

