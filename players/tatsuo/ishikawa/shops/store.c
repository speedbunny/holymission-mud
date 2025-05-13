/*coded by tatsuo for the samurai guild*/
#define PPATH "/players/tatsuo/guild/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

#define NORM_STORE ("/players/tatsuo/ishikawa/shops/" + "guild_store")

inherit "room/room";

object trader;
string trader_name;

reset( arg )
{
   if ( !trader ) {
trader = clone_object( "/players/tatsuo/ishikawa/chatters/tanaka" );
      if ( trader )
         transfer( trader, this_object() );
         
      trader_name = trader->query_name();
   }

   if ( arg )
      return;
      
   set_light(1);
   short_desc = "In the Samurai's General Store";
   long_desc = "This is the Samurai's general store where all the great warriors can come\n"+
               "and make purchases of the little things that one may need when roaming\n"+
               "the land. It is a plain store with shelves covered with different\n"+ 
               "odds and ends. You feel quite at home. There is a window on the east\n"+
               "side and, you can feel a gentle breeze blowing in. There is a desk in\n"+
               "in the center of the room and a gentleman sitting behind it.\n"+
               "There is a sign hanging from the wall.\n";
   
   items = ({ "chamber", long_desc,
              "floor", "The floor is made of wood and a carpet covers it",
              "walls", "The walls are covered with pictures and there is a shelf",
              "wall", "The walls are covered with pictures and there is a shelf",
              "carpet", "It is an expensive, blue carpet with the motive of a dragon",
              "shelf", "There are a lot of items at the shelf",
              "items", "There are so much items, that you fail to recognize a single one",
             "sign", "There are some strange oriental letters written on it",
              "picture","The picture shows a fight of a heroic man against a evil creature",
              });
   
   smell = "You smell the odor of wood and different items.";
   
   dest_dir = ({ PPATH + "bar",        "north",
                 PPATH + "restroom",   "south",
                 PPATH + "inner-yard1", "east",
              });
              
   transfer(clone_object("/players/tatsuo/ishikawa/shops/ming.c"), this_object());
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


