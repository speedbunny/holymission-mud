
inherit "/room/room";

#include "/players/apollo/guild/barb.h"

object trader;
string trader_name;

void reset(int arg) {
    if ( !trader ) {
	trader = clone_object( "/players/apollo/guild/monsters/wtrader");
	if ( trader )
	    transfer( trader, this_object() );

	trader_name = trader->query_name();
    }

    set_light(1);

    short_desc = "The Barbarians Weapon Trader";

    long_desc = 
	"This medium size tent covers wooden tables that carry all kinds of\n"+
    	"barbarian weapons. Each table has different weapon is big and small sizes and\n"+
    	"and many barbarians are looking over each piece. A sign hangs above the last\n"+
    	"table. Showing the prices and supply of what the trader has to offer.\n";

    items = ({ 
	"tent", long_desc,
     	"floor", "The floor is made of grass",
      	"tables", "It is a large wooden desk, which devides the room in two parts",
      	"walls", "The walls are made of wood",
      	"wall", "The wall is made of wood",
      	"table", "There are a lot of weapons laying on the table",
      	"weapons", "There so many weapons, that you better should read the sign",
      	"weapon", "There so many weapons, that you better should read the sign",
      	"sign", "There are some strange barbaric letters written on it",
      	"wood", "It is teak",
    });

    smell = "You smell the odor of wood and steel.";

    dest_dir = ({
	GROOMS+"camp4", "east",
     });

}


init() {
    ::init();
    AA("search","search");
    AA( "read_it", "read" );
    AA( "buy_it",  "buy"  );
    AA( "sell_it", "sell" );
    AA( "help_it", "help" );
    AA( "value_it", "value" );
    AA( "price_it", "price" );
}

search( arg ) {
    if ( !arg )
	return;

    write("You search and search, but find nothing special.\n");
    say(this_player()->query_name()+" searches around.\n");

    return( 1 );
}

read_it(arg) {
    if ( TP->query_guild() == 11 )
	return( NORM_STORE_WEA->read( arg ) );
    else
	write("This language is too primitive to understand.\n");

    return( 1 );
}

buy_it(arg) {
    if ( trader && present(trader,this_object()) )
	return( NORM_STORE_WEA->buy( arg ) );
    else
	write( "Someone has killed " + trader_name + ", so he cannot serve you.\n");

    return( 1 );
}

sell_it(arg) {
    if ( trader && present(trader,this_object()) )
	return( NORM_STORE_WEA->sell( arg ) );
    else
	write( "Someone has killed " + trader_name + ", so he cannot serve you.\n");

    return( 1 );
}

help_it(arg) {
    if ( trader && present(trader,this_object()) )
	return( NORM_STORE_WEA->help( arg ) );
    else
	write( "Someone has killed " + trader_name + ", so he cannot serve you.\n");

    return( 1 );
}

price_it(arg) {
    if ( trader && present(trader,this_object()) )
	return( NORM_STORE_WEA->price( arg ) );
    else
	write( "Someone has killed " + trader_name + ", so he cannot serve you.\n");

    return( 1 );
}

value_it(arg) {
    if ( trader && present(trader,this_object()) )
	return( NORM_STORE_WEA->value( arg ) );
    else
	write( "Someone has killed " + trader_name + ", so he cannot serve you.\n");

    return( 1 );
}


