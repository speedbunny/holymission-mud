#define PPATH "/players/tatsuo/ezo/"
#define TP  this_player()
#define TPN TP->query_name()
#define NORM_STORE (PPATH + "guild_store")

inherit "room/room";
object trader;
string trader_name;
reset(arg) {
    int x;
    object store;
    if ( !trader ) {
	trader = clone_object( "/players/tatsuo/eastMonst/gtrader" );
	if ( trader )
	    transfer( trader, this_object() );
	trader_name = trader->query_name();
    }
   if(arg) return;
    set_light(1);
    short_desc = "In a chamber";
   long_desc=
	"This is a chamber in the residence of Matsumae Yoshihiro, the evil\n"+
       "Shogun of the island of Ezo. On the floor is a carpet and the walls\n"+
       "are covered with pictures. At the western wall can you see a large\n"+
       "shelf made of wood, on which a sign is attached.\n";
   items=({
	"chamber", long_desc,
        "floor", "The floor is made of wood and a carpet covers it",
        "walls", "The walls are covered with pictures and there is a shelf",
        "wall", "The walls are covered with pictures and there is a shelf",
        "carpet", "It is an expensive, blue carpet with the motive of a dragon",
        "dragon", "It is a nihonese seadragon",
        "shelf", "There are a lot of items at the shelf",
       "items","There are so many items that you fail to pick out a single one",
        "sign", "There are some nihonese letters written on it",
        "pictures","The pictures show fights of heroic men against evil creatures",
        "picture","The picture shows a fight of a heroic man against an evil creature",
   });
    smell = "You smell the odor of wood and different items.";
   dest_dir=({
	PPATH + "bar","north",
	PPATH + "inner-yard1","east",
	PPATH + "restroom","south",
//	PPATH + "boxes","west",
    });
    transfer( clone_object( "/players/tatsuo/ezo/ming.c" ), this_object() );
    catch(call_other(NORM_STORE,"???"));
   if(store=find_object(NORM_STORE)) {
      if(!present("blue scroll",store)) {
	    for(x=0; x < 9; x++)
             transfer(clone_object("/players/whisky/obj/recall_scroll"),store);
	}
    }
}

init() {
    ::init( );
    add_action( "read_it", "read" );
    add_action( "buy_it",  "buy"  );
    add_action( "sell_it", "sell" );
    add_action( "help_it", "help" );
    add_action( "value_it", "value" );
    add_action( "price_it", "price" );
}

read_it(arg) {
    if ( TP->query_guild() == 8 )
	return( NORM_STORE->read( arg ) );
    else
	write( "You don't understand this language.\n" );
    return( 1 );
}

buy_it(arg) {
    if ( trader && present(trader,this_object()) )
	return( NORM_STORE->buy( arg ) );
    else
	write("Someone has killed "+trader_name+", so he cannot serve you.\n");
    return( 1 );
}

sell_it(arg) {
    if ( trader && present(trader,this_object()) )
	return( NORM_STORE->sell( arg ) );
    else
	write("Someone has killed "+trader_name+", so he cannot serve you.\n");
    return( 1 );
}

help_it(arg) {
    if ( trader && present(trader,this_object()) )
	return( NORM_STORE->help( arg ) );
    else
	write("Someone has killed "+trader_name+", so he cannot serve you.\n");
    return( 1 );
}

price_it(arg) {
    if ( trader && present(trader,this_object()) )
	return( NORM_STORE->price( arg ) );
    else
	write("Someone has killed "+trader_name+", so he cannot serve you.\n");
    return( 1 );
}

value_it(arg) {
    if ( trader && present(trader,this_object()) )
	return( NORM_STORE->value( arg ) );
    else
	write("Someone has killed "+trader_name+", so he cannot serve you.\n");
    return( 1 );
}
