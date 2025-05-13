/* 971011, Uglymouth: Recoded to use /room/doorroom.c now.
 */
#include "../config.h"
#include "location.h"		// Defines where to put the shop!

inherit "/room/room";

object shopkeeper;

object make_shopkeeper();

void reset( int arg ) {
  if( !present( "shopkeeper" ) ) shopkeeper = make_shopkeeper();
  ::reset( arg );
  if( arg ) return;
  set_light(1);
  short_desc = "In the secret police shop";
  long_desc = "You are in a small shop. It looks like any other shop you have been in, "
    + "and you note that it is a bit strange that yet another shop in this area "
    + "can show a profit... But maybe you can buy or sell things here, too? "
    + "The exit is to the south, and a door leads north. "
    + "There is a small note close to the north door.\n";
  dest_dir = ({
    SHOP_PLACE, "south",
    "players/padrone/secret_police/backroom", "north",
  });
  items = ({
    "note", "A small, yellowed note. You can read it",
  });
}

void init() {
  ::init();
  add_action( "no_shop", "sell" );
  add_action( "no_shop", "value" );
  add_action( "no_shop", "buy" );
  add_action( "no_shop", "list" );
  add_action( "do_read", "read" );
}

object make_shopkeeper() {
  object keeper, item;

  keeper = clone_object( "obj/monster" );
  keeper->set_name( "shopkeeper" );
  keeper->set_short( "The shopkeeper" );
  keeper->set_long( "At first glance, this shopkeeper looks like an "
    + "ordinary shopkeeper - fat, middle-aged, big and strong. But as "
    + "you take a closer look at this particular shopkeeper "
    + "you notice some very un-shopkeeper-like features, like "
    + "a set of more or less hidden daggers and a pair of dark "
    + "sunglasses...\n" );
  keeper->set_level( 4 );
  keeper->set_hp( 250 );
  keeper->set_al( 80 );
  keeper->set_male();
  keeper->set_spell_mess1( "Shopkeeper kicks his opponent very hard." );
  keeper->set_spell_mess2( "Shopkeeper kicks you very hard. You are hurt!" );
  keeper->set_chance( 20 );
  keeper->set_spell_dam( 10 );
  keeper->load_chat( 20, ({
    "The shopkeeper looks at you suspiciously.\n",
    "The shopkeeper says: Psst! We might have a job for you. "
      + "Go north, quickly!\n",
    "The shopkeeper says: Psst! You can earn 10000 gold coins!\n",
    "The shopkeeper says: You can earn 10000 gold coins!\n",
    "The shopkeeper says: Psst! We'll give you 10000 for a small job!\n",
    "The shopkeeper tries to look like a shopkeeper.\n",
    "The shopkeeper pretends to be counting some money.\n",
  }) );

  item = clone_object( "players/padrone/secret_police/membership" );
  transfer( item, keeper );

  item = clone_object( "obj/weapon" );
  item->set_name( "long, sharp dagger" );
  item->set_alias( "dagger" );
  item->set_short( "A long, sharp dagger" );
  item->set_long( "A long, sharp dagger. Good for self defense.\n" );
  item->set_class( 7 );
  item->set_value( 15 );
  item->set_weight( 1 );
  transfer( item, keeper );
  keeper->init_command( "powerup" );

  item = clone_object( "obj/thing" );
  item->set_name( "iron key" );
  item->set_alias( "key" );
  item->set_alt_name( "interrogation" );
  item->set_short( "An iron key" );
  item->set_long( "An iron key with the secret police logo on it.\n" );
  item->set_value( 10 );
  transfer( item, keeper );
  move_object( keeper, this_object() );
  return keeper;
}

status check_shopkeeper() {
  if( shopkeeper ) return 1;
  printf( "How can you do that when there is no shopkeeper here?\n" );
  return 0;
}

int no_shop( string item ) {
  string msg;

  if( !check_shopkeeper() ) return 1;
  switch( query_verb() ) {
    case "sell":
      msg = "The shopkeeper says: Sorry, but we don't buy " + item + "s.\n";
    break;
    case "buy":
      msg = "The shopkeeper says: Sorry, but we are currently out of "
        + item + "s.\n";
    break;
    case "list":
    case "value":
      msg = "The shopkeeper says: I am sorry, but I cannot give you "
        + "that information.\n";
    break;
  }
  printf( msg );
  say( msg, this_player() );
  return 1;
}

int do_read( string str ) {
  if( str != "note" && str != "small note" ) return 0;
  printf( "The note says: 'Pssst! This way!\n" );
  return 1;
}

