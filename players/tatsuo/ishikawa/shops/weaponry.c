/*shop code altered and specialized by tatsuo for the samurai guild*/
#define PPATH "/players/tatsuo/guild/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

#define NORM_STORE ("/players/tatsuo/ishikawa/shops/" + "guild_weap")

inherit "room/room";

object trader;
string trader_name;

reset( arg )
{
   if ( !trader ) {
      trader = clone_object( "/players/tatsuo/ishikawa/chatters/sunami" );
      if ( trader )
         transfer( trader, this_object() );
         
      trader_name = trader->query_name();
   }

   if ( arg )
      return;
      
   set_light(1);
   short_desc = "The Samurai's Weaponry";
    long_desc = "This is the weaponry where all the samurais come to sell and trade\n"+
               "there weapons they have collected from battle. There are a myriad\n"+
               "of samurai weapons hanging on shelves around the shop. The shop is\n"+
               "decorated with a graceful design there is a desk which divides the\n"+
               "room in half. There is a teak wood table and 2 silk cushions for\n"+
               "customers to sit on and relax while shopping. The man behind the\n"+
               "desk is smiling and looks like his only desire is to serve you.\n"+
               "There is also a sign hanging from the wall.\n";
   
   items = ({ "chamber", long_desc,
              "floor", "The floor is made of wood",
              "desk", "It is a large wooden desk, which devides the room in two parts",
              "walls", "The walls are made of wood",
              "wall", "The wall is made of wood",
              "shelf", "There are a lot of weapons at the shelf",
              "weapons", "There so many weapons, that you better should read the sign",
              "weapon", "There so many weapons, that you better should read the sign",
              "sign", "There are some strange oriental letters written on it",
              "wood", "It is teak",
              });
   
   smell = "You smell the odor of wood and steel.";
   
   dest_dir = ({PPATH + "court4.c","west",PPATH +"smith.c","south",
              });
              
   transfer( clone_object( "/players/tatsuo/ishikawa/shops/ming.c" ), this_object() );
}


init( )
{
   ::init( );
   
   add_action("search","search");

   add_action( "read_it", "read" );
   add_action( "buy_it",  "buy"  );
   add_action( "sell_it", "sell" );
   add_action( "help_it", "help" );
   add_action( "value_it", "value" );
   add_action( "price_it", "price" );
}

search( arg )
{
   if ( !arg )
      return;
         
   write("You search and search, but find nothing special.\n");
   say(this_player()->query_name()+" searches around.\n");
   
   return( 1 );
}

read_it(arg)
{
   if ( TP->query_guild() == 8 )
      return( NORM_STORE->read( arg ) );
   else
      write( "You don't understand this language.\n" );
      
   return( 1 );
}

buy_it(arg)
{
   if ( trader && present(trader,this_object()) )
      return( NORM_STORE->buy( arg ) );
   else
      write( "Someone has killed " + trader_name + ", so he cannot serve you.\n");
      
   return( 1 );
}
 
sell_it(arg)
{
   if ( trader && present(trader,this_object()) )
      return( NORM_STORE->sell( arg ) );
   else
      write( "Someone has killed " + trader_name + ", so he cannot serve you.\n");
      
   return( 1 );
}

help_it(arg)
{
   if ( trader && present(trader,this_object()) )
      return( NORM_STORE->help( arg ) );
   else
      write( "Someone has killed " + trader_name + ", so he cannot serve you.\n");
      
   return( 1 );
}

price_it(arg)
{
   if ( trader && present(trader,this_object()) )
      return( NORM_STORE->price( arg ) );
   else
      write( "Someone has killed " + trader_name + ", so he cannot serve you.\n");
      
   return( 1 );
}

value_it(arg)
{
   if ( trader && present(trader,this_object()) )
      return( NORM_STORE->value( arg ) );
   else
      write( "Someone has killed " + trader_name + ", so he cannot serve you.\n");
      
   return( 1 );
}


