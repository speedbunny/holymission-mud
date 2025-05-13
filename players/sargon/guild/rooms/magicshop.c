#include "/players/sargon/define.h"
#define ROOM "/players/sargon/guild/rooms/"
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define STORE ("/players/sargon/guild/store/guild_store")

inherit "room/room";
object trader;
string trader_name;

reset( arg ) {
    int x;
    object store;

    if ( !trader ) {
	trader = CO("/players/sargon/guild/mon/xena" );
	if ( trader )
	    TR( trader, TO );
	trader_name = trader->N;
    }

    if ( arg )
	return;

    set_light(1);
    short_desc = "Fighter's magic shop";
    long_desc = "This magic shop was opened by Xena, the Warrior Princess.\n"+
    "In her travels, she has managed to acquire quite a few items that she's\n"+
    "willing to barter to aid you in yer many adventures. Even though the \n"+
    "walls are cold the room has a cozy feeling with the carpet & pictures.\n"+
    "There's a shelf that can be seen behind the sign. \n";

    items = ({ 
      "walls", "The walls are covered with pictures and there is a shelf",
      "wall", "The walls are covered with pictures and there is a shelf",
      "carpet", "It is an expensive, blue carpet with the sign of a woman",
      "shelf", "There are a lot of items at the shelf",
      "items", "There're so many items, that you can't recognize a single one",
      "sign", "There are some letters written on it",
      "pictures","The pictures showes Xena fighting evil beings",
      "picture","The picture shows Xena and her lesbian friend Gabby",
    });

    smell = "You smell the essence of a woman.";
    property =({ "no_teleport" });

    dest_dir = ({ ROOM+"restroom","down", });

    TR(CO( "/players/sargon/guild/store/can.c" ), TO);

    catch(call_other(STORE,"???"));

    if (store = find_object(STORE)) {
	if (!present("blue scroll",store)) {
	    for(x=0; x < 9; x++)
		TR(CO("/players/whisky/obj/recall_scroll"),store);
	}
    }

}


init( ) {
    ::init( );

    add_action("search","search");
    add_action( "read_it", "read" );
    add_action( "buy_it",  "buy"  );
    add_action( "sell_it", "sell" );
    add_action( "help_it", "help" );
    add_action( "value_it", "value" );
    add_action( "price_it", "price" );
}

search( arg ) {
    if ( !arg )
	return;

    write("You search and search, but you don't find any coupons.\n");
    say(TPN+" searches around like a fool.\n");
    return( 1 );
}

read_it(arg) {
    if ( TP->query_guild() == 3  )
	return( STORE->read( arg ) );
    else
	write("This place is only for the Noble Fighters!!!!!\n" );

    return( 1 );
}

buy_it(arg) {
    if ( trader && present(trader,TO) )
	return( STORE->buy( arg ) );
    else
       write("Someone has killed " + trader_name + ", so she can't help ya.\n");
    return( 1 );
}

sell_it(arg) {
    if ( trader && present(trader, TO) )
	return( STORE->sell( arg ) );
    else
     write("Someone has killed " + trader_name + ", so she can't help you.\n");
    return( 1 );
}

help_it(arg) {
    if ( trader && present(trader, TO) )
	return( STORE->help( arg ) );
    else
      write("Someone has killed " + trader_name + ", so she can't help ya.\n");
    return( 1 );
}

price_it(arg) {
    if ( trader && present(trader, TO) )
	return( STORE->price( arg ) );
    else
      write("Someone has killed " + trader_name + ", so she can't help ya.\n");
    return( 1 );
}

value_it(arg) {
    if ( trader && present(trader, TO) )
	return( STORE->value( arg ) );
    else
	write("Someone has killed " + trader_name + ", so she can't help ya.\n");

    return( 1 );
}


