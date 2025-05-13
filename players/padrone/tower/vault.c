/* vault.c
 * Note: money is not put here, but in players/padrone/walker/cell.c
 * 230293, Ethereal Cashimor: better anti-teleport, room/room, ect.
 * 970913, Uglymouth: Now using /room/doorroom.c and updated code.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

object thief1, thief2, lawbringer;

status check_for_players();
void make_big_thief();
void make_small_thief();

void reset( int arg ) {
  ::reset( arg );
  if( check_for_players() && arg ) return;
  if( thief1 && !present( thief1, this_object() ) )
    thief1->move_player( "X#" + file_name( this_object() ) );
  if( thief2 && !present( thief2, this_object() ) )
    thief2->move_player( "X#" + file_name( this_object() ) );
  if( !thief1 ) make_big_thief();
  if( !thief2 ) make_small_thief();
  if( !lawbringer ) {
    lawbringer = clone_object( "players/padrone/obj/lawbringer" );
    if( thief2 ) transfer( lawbringer, thief2 );
    else if( thief1 ) transfer( lawbringer, thief1 );
    else transfer( lawbringer, this_object() );
  }

  if( arg ) return;
  set_light( 1 );
  short_desc = "The treasury vault";
  long_desc="This is the vault in the treasury in Padrone's Castle. The\n"
    + "walls are made of steel, and to the south a steel door leads\n"
    + "out. The floor has been engraved with anti-teleport runes. But\n"
    + "despite these precautions, and the fierce guards outside,\n"
    + "criminals have managed to sneak in to steal the contents.\n";
  hidden_dir = ({
    "players/padrone/tower/treasury", "south",
  });
  items = ({
    "door", "dummy door description",
  });
  property = "no_teleport";
  smell="The air is very old here.";

}

void make_big_thief() {
  object temp;

  thief1 = clone_object( "obj/monster" );
  thief1->set_name( "big thief" );
  thief1->set_alias( "thief" );
  thief1->set_short( "A big thief" );
  thief1->set_long( "This is an experienced and dangerous criminal. "
    + "He has managed to sneak into the vault, despite the Archers!\n" );
  thief1->set_male();
  thief1->set_level( 16 );
  thief1->set_hp( 400 );
  thief1->set_ac( 10 );
  thief1->set_al( -50 );
  thief1->set_aggressive( 1 );
  thief1->set_spell_mess1( "The thief throws a knife with astonishing accuracy." );
  thief1->set_spell_mess2( "The thief throws a knife with astonishing accuracy at you." );
  thief1->set_chance( 20 );
  thief1->set_spell_dam( 50 );

  temp=clone_object( "obj/weapon" );
  temp->set_name( "sword of fire" );
  temp->set_alias( "sword" );
  temp->set_short( "A sword of fire" );
  temp->set_long( "A sword of fire.\n" );
  temp->set_class( 18 );
  temp->set_weight( 3 );
  temp->set_value( 2000 );
  transfer( temp, thief1 );

  temp = clone_object( "obj/thing" );
  temp->set_name( "official letter" );
  temp->set_alias( "letter" );
  temp->set_short( "An official letter from Padrone" );
  temp->set_long( "It is witten on a sheet of high-quality paper "
    + "with the official Castle of Padrone letterhead. "
    + "Maybe you should try to read it?\n" );
  temp->set_read_file( "/players/padrone/tower/vault_letter.txt" );
  temp->set_value( 10 );
  transfer( temp, thief1 );
  move_object( thief1, this_object() );
  thief1->init_command( "wield sword" );
}

void make_small_thief() {
  object temp;
  thief2 = clone_object( "obj/monster" );
  thief2->set_name( "small thief" );
  thief2->set_alias( "thief" );
  thief2->set_short( "A small thief" );
  thief2->set_long( "This thief is small, weak and ugly, but very greedy and "
    + "devious. He has taken almost all the valuables in the vault.\n" );
  thief2->set_level( 5 );
  thief2->set_male();
  thief2->set_hp( 100 );
  thief2->set_ac( 15 );
  thief2->set_al( -150 );
  thief2->set_aggressive( 1 );
  thief2->set_spell_mess1( "The small thief throws a knife." );
  thief2->set_spell_mess2( "The small thief throws a knife at you." );
  thief2->set_chance( 20 );
  thief2->set_spell_dam( 20 );

  temp = clone_object( "obj/weapon" );
  temp->set_name( "sword of frost" );
  temp->set_alias( "sword" );
  temp->set_short( "A sword of frost" );
  temp->set_long( "A sword of frost.\n" );
  temp->set_class( 18 );
  temp->set_weight( 3 );
  temp->set_value( 2000 );
  transfer( temp, thief2 );

  temp = clone_object( "players/padrone/obj/gravstone" );
  temp->set_weight( -2 );
  transfer( temp, thief2 );

  temp = clone_object( "obj/treasure" );
  temp->set_id( "jewel" );
  temp->set_alias( "gem" );
  temp->set_short( "A jewel" );
  temp->set_long( "A beautiful, glittering jewel.\n" );
  temp->set_weight( 3 );
  temp->set_value( 1000 );
  transfer( temp, thief2 );

  temp = clone_object( "obj/treasure" );
  temp->set_id( "painting" );
  temp->set_alias( "picture" );
  temp->set_short( "A painting" );
  temp->set_long( "This painting shows a landscape. It is signed 'Gandalf', "
    + "and on the backside it says 'Made in Mordor'.\n" );
  temp->set_weight( 3 );
  temp->set_value( 100 );
  transfer( temp, thief2 );

  temp = clone_object( "obj/armour" );
  temp->set_name( "golden crown" );
  temp->set_alias( "crown" );
  temp->set_short( "A golden crown" );
  temp->set_long( "This is a golden crown. It is probably very expensive, " 
    + "and has possibly once belonged to a great king. As a "
    + "helmet, however, it would be worse than nothing.\n" );
  temp->set_weight( 3 );
  temp->set_ac( -1 );
  temp->set_type( "helmet" );
  temp->set_value( 5000 );
  transfer( temp, thief2 );

  temp = clone_object( "obj/weapon" );
  temp->set_name( "golden sword" );
  temp->set_alias( "sword" );
  temp->set_short( "A golden sword" );
  temp->set_long( "This is a sword made of gold. It is not very useful as "
    + "a weapon, but hideously expensive.\n" );
  temp->set_class( 5 );
  temp->set_weight( 5 );
  temp->set_value( 3000 );
  transfer( temp, thief2 );

  temp = clone_object( "obj/thing" );
  temp->set_name( "panzer key" );
  temp->set_alias( "key" );
  temp->set_alt_name( "walkercell");
  temp->set_short( "A panzer key" );
  temp->set_long( "This is a panzer key. You wonder where it fits.\n" );
  temp->set_value( 10 );
  transfer( temp, thief2 );

  move_object( thief2, this_object() );
  thief2->init_command( "wield sword of frost" );
}

object return_lawbringer() { return lawbringer; }

object check_is_player( object ob ) {
  if( living( ob ) && !ob->is_npc() && query_ip_number( ob ) )
    return ob;
  return 0;
}

status check_for_players() {
  object *players, room;
  status found;

  found = 0;
  players = map_array( all_inventory( this_object() ), "check_is_player",
    this_object() );
  if( sizeof( players ) ) {
    tell_room( this_object(),
      "Suddenly, you get a feeling that no new treasure "
      + "will be put in the vault as long as you are here...\n" );
    found = 1;
  }
  players = ({ });
  if( room = find_object( "players/padrone/tower/treasury" ) )
    players = map_array( all_inventory( room ), "check_is_player", this_object() );
  if( sizeof( players ) ) {
    tell_room( room, "Suddenly, you get a feeling that no new treasure "
      + "will be put in the vault as long as you are here...\n" );
    found = 1;
  }
  return found;
}

void put_back_lawbringer( object lb ) {
  if( lb != lawbringer )
    /* Not the real Lawbringer! */
    move_object( lb, "players/padrone/store" );
  else if( thief2 && living( thief2 ) ) {
    if( !present( thief2, this_object() ) )
      thief2->move_player( "X#" + file_name( this_object() ) );
    /* Yes, ignore any weight limits. He can carry everything. */
    move_object( lb, thief2 );
  }
  else if( thief1 && living( thief1 ) ) {
    if( !present( thief1, this_object() ) )
      thief1->move_player( "X#" + file_name( this_object() ) );
    /* Yes, ignore any weight limits. He too can carry everything. */
    move_object( lb, thief1 );
  }
  else
    /* Yes, just put it there on the floor! */
    move_object( lb, this_object() );
}
