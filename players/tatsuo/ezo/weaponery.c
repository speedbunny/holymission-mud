#define PPATH "/players/tatsuo/ezo/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define NORM_STORE (PPATH + "guild_weap")

inherit "room/room";
object trader;
string trader_name;
reset(arg) {
   if ( !trader ) {
      trader = clone_object( "/players/tatsuo/eastMonst/gweaponer" );
      if ( trader )
         transfer( trader, this_object() );
      trader_name = trader->query_name();
   }
   if(arg) return;
   set_light(1);
   short_desc = "In the weaponery";
   long_desc=
	"This is a chamber in the residence of Matsumae Yoshihiro, the evil\n"+
        "Shogun of the island of Ezo. At the south wall is a long desk which\n"+
        "divides the room in two parts. Behind the desk can you see a large\n" +
        "shelf, specially made for stocking weapons. There is a sign on\n"+
	"the wall.\n";
   items=({
	"chamber", long_desc,
        "floor", "The floor is made of wood",
        "desk", "It is a large wooden desk, which devides the room in two parts",
        "walls", "The walls are made of wood",
        "wall", "The wall is made of wood",
        "shelf", "There are a lot of weapons at the shelf",
        "weapons","There so many weapons, that you better should read the sign",
        "weapon", "There so many weapons, that you better should read the sign",
        "sign", "There are some nihonese letters written on it",
        "wood", "It is teak",
   });
   smell = "You smell the odor of wood and steel.";
   dest_dir=({  PPATH + "bar","south",  });
   transfer( clone_object( "/players/tatsuo/ezo/ming.c" ), this_object() );
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
      write("Someone has killed "+trader_name + ", so he cannot serve you.\n");
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
