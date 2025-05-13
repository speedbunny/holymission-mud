
/* Apollo - Barbarian Guild */
inherit "room/room";

#include "/players/apollo/guild/barb.h"
object trader;
string trader_name;

reset( arg ) {
    if ( !trader ) {
	trader = clone_object("/players/apollo/guild/monsters/atrader");
	if ( trader )
	    transfer( trader, this_object() );

	trader_name = trader->query_name();
    }

    if ( arg ) return;

    set_light(1);

    short_desc = "The Traders' Tent";

    long_desc = 
      "This tent is filled with many types of different barbarian armors. "+
      "Tables are placed among the tent for access of the armor and a sign "+
      "carved out of wood hangs over the last table to see what the Trader "+
      "has to sell or is looking to buy.\n";

    items = ({ 
	"chamber", long_desc,
      	"table","A simple wooden table",
      	"desk", "It is a large wooden desk, which devides the room in two parts",
      	"walls","They are cloth. Its a tent",
      	"cushions", "The cushions are made of pink silk and look very comfortable",
      	"armours", "There so many armours, that you better should read the sign",
      	"armour", "There so many armours, that you better should read the sign",
      	"sign","Carved out of wood, hangs over the table",
      	"wood", "It is teak",
    });

    smell = "You smell the odor of wood, leather, clothes and steel.";

    dest_dir = ({
	GROOMS+"camp4", "west" 
      });

}


init() {
    ::init();
    add_action("search","search");
    add_action( "read_it", "read" );
    add_action( "buy_it",  "buy"  );
    add_action( "sell_it", "sell" );
    add_action( "help_it", "help" );
    add_action( "value_it", "value" );
    add_action( "price_it", "price" );
}

search( arg ) {
    if ( !arg ) return;

    write("You search and search, but find nothing special.\n");
    say(this_player()->query_name()+" searches around.\n");

    return( 1 );
}

read_it(arg) {
    if ( TP->query_guild() == 11)
	return( NORM_STORE_ARM->read( arg ) );
    else
	write( "This language is very primitive, you can't understand.\n");

    return( 1 );
}

buy_it(arg) {
    if ( trader && present(trader,this_object()) )
	return( NORM_STORE_ARM->buy( arg ) );
    else
	write( "Someone has killed " + trader_name + ", so he cannot serve you.\n");

    return( 1 );
}

sell_it(arg) {
    if ( trader && present(trader,this_object()) )
	return( NORM_STORE_ARM->sell( arg ) );
    else
	write( "Someone has killed " + trader_name + ", so he cannot serve you.\n");

    return( 1 );
}

help_it(arg) {
    if ( trader && present(trader,this_object()) )
	return( NORM_STORE_ARM->help( arg ) );
    else
	write( "Someone has killed " + trader_name + ", so he cannot serve you.\n");

    return( 1 );
}

price_it(arg) {
    if ( trader && present(trader,this_object()) )
	return( NORM_STORE_ARM->price( arg ) );
    else
	write( "Someone has killed " + trader_name + ", so he cannot serve you.\n");

    return( 1 );
}

value_it(arg) {
    if ( trader && present(trader,this_object()) )
	return( NORM_STORE_ARM->value( arg ) );
    else
	write( "Someone has killed " + trader_name + ", so he cannot serve you.\n");

    return( 1 );
}
