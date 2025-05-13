/* Changed by Ethereal Cashimor, 230293, Room/room and no Rambo's
 * 970913, Uglymouth: Recoded to use /room/doorroom.c and updated code.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

object rambo1, rambo2, rambo3;

void throw_out_players();
void make_rambo( int nr );

void reset( int arg ) {
  int i;

  ::reset( arg );
  throw_out_players();
  for( i = 1; i <= 3; i++ ) make_rambo( i );
  if( arg ) return;
  set_light( 1 );
  short_desc = "Archer room in the treasury";
  long_desc = "This is the Castle's treasury. Over the years, many of the "
    + "riches of the world have been collected here. In his youth the "
    + "Wizard travelled the world and collected numerous fantastic " 
    + "and valuable items, and since he retired from his adventuring "
    + "and settled down in this comfortable castle, consultation fees "
    + "and royalties have contributed even more to his fortune. The "
    + "treasure is stored in the vault, north of this room. ";
  hidden_dir = ({
    "players/padrone/tower/treasury", "north",
    "players/padrone/tower/hall", "south",
  });
  items = ({
    "treasury", "The smell of great treasures is near",
    "vault", "It's to the north",
    "door", "dummy door description",
  });
  smell="You smell gold!";
}

status rambo_block() {
  status blocked;

  blocked = 0;
  if( rambo1 && present( rambo1, this_object() ) ) {
    write( "Archer I bars the way.\n" );
    blocked = 1;
  }
  if( rambo2 && present( rambo2, this_object() ) ) {
    write( "Archer II bars the way.\n" );
    blocked = 1;
  }
  if( rambo3 && present( rambo3, this_object() ) ) {
    write( "Archer III bars the way.\n" );
    blocked = 1;
  }
  return blocked;
}

status move( string str ) {
  if( !str ) str = query_verb();
  if( str != "north" ) return ::move( str );
  if( rambo_block() ) return 1;
  return ::move( str );
}

void throw_out_players() {
  object obj, this_obj;

  obj = first_inventory( this_object() );
  while( obj ) {
    this_obj = obj;
    obj = next_inventory(obj);
    if( !living( this_obj ) || this_obj->query_npc() ) continue;
    tell_object( this_obj, "Suddenly, you have a feeling of disorientation.\n" );
    this_obj->move_player( "out#players/padrone/tower/hall" );
  }
}

void make_rambo( int nr ) {
  object rambo, item;
  string roman;

  switch( nr ) {
    case 1:
      if( rambo1 ) return;
      roman = "I";
      rambo1 = rambo = clone_object( "obj/monster" );
    break;
    case 2:
      roman = "II";
      rambo2 = rambo = clone_object( "obj/monster" );
    break;
    case 3:
      roman = "III";
      rambo3 = rambo = clone_object( "obj/monster" );
      transfer( clone_object( "players/padrone/obj/immunity" ), rambo );
      item = clone_object( "obj/thing" );
      item->set_name( "maximum-security key" );
      item->set_alias( "key" );
      item->set_alt_name( "vaultdoor" );
      item->set_short( "A maximum-security key" );
      item->set_long( "This is a maximum-security key. "
        + "You wonder where it fits...\n" );
      item->set_value( 10 );
      transfer( item, rambo );
    break;
    default: return;  /* not a valid argument anyway */
  }
  rambo->set_name( "archer " + lower_case( roman ) );
  rambo->set_alias( "archer" ); 
  rambo->set_race( "human" );
  rambo->set_short( "Archer " + roman );
  rambo->set_long( "This is Archer "+roman+". Wow! What bulging muscles! " 
    + "He is employed by Padrone to guard the treasury. Which he does.\n" );
  rambo->set_level( 14 + nr );	    /* 15, 16, and 17 */
  rambo->set_hp( 200 + 100 * nr );  /* 300, 400, 500 */
  rambo->set_ac( 8 + 2 * nr );      /* 10, 12, 14 */
  rambo->set_al( 40 );
  rambo->set_aggressive( 1 );
  rambo->set_male();

  item = clone_object( "players/padrone/obj/m16f" );
  if( nr == 3 ) {
    item->set_max_bullets( 40 );
    item->set_bullets( 40 );
    item->set_wc_per_bullet( 2 );
    item->set_sound( "TOK" );
    item->set_value_per_bullet( 2 );
    item->set_value( 40 );
    item->set_info( "This is the advanced repeater crossbow version" );
  }
  item->set_monsters_reload_at_reset( 1 );
  transfer( item, rambo );
  rambo->init_command( "wield crossbow" );
  move_object( rambo, this_object() );
} /* End make_rambo() */
