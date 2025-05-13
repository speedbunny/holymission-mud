/*coded by tatsuo for the samuria guild*/
#define PPATH "/players/tatsuo/guild/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

#define NORM_STORE ("/players/tatsuo/ishikawa/shops/" + "guild_armour")

inherit "room/room";

object trader;
string trader_name;

reset( arg )
{
   if ( !trader ) {
       trader = clone_object( "/players/tatsuo/ishikawa/chatters/sunami2" );
      if ( trader )
         transfer( trader, this_object() );
         
      trader_name = trader->query_name();
   }

   if ( arg )
      return;
      
   set_light(1);
   short_desc = "In the armoury";
   long_desc = "This is the armoury where the mighty samurais come to sell and buy\n"+
               "armours. This is a renown shop everyone all over the world has heard\n"+
               "of this shop. You can see it is a airy room with many windows. There\n"+
               "is a large wodden desk in the middle of the shop. Seated behind it is\n"+
               "a lovely young lady. There are shelves lining the wall. On the shelves\n"+
               "are a wide selection of some of the finest armours available. In the\n"+
               "corner of the shop is a table with two cushions and some tea cups\n"+
               "for the customer to drink while they are shopping. You feel a sense\n"+
               "of peace and relaxation here.\n"+
               "There is a sign hanging on the wall behind the desk.\n";
   
   items = ({ "chamber", long_desc,
              "floor", "The floor is made of wood",
              "desk", "It is a large wooden desk, which devides the room in two parts",
              "walls", "The walls are made of wood",
              "wall", "The wall is made of wood",
              "shelf", "There are a lot of weapons at the shelf",
      "cushions", "The cushions are made of pink silk and look very comfortable",
              "armours", "There so many armours, that you better should read the sign",
              "armour", "There so many armours, that you better should read the sign",
              "sign", "There are some strange oriental letters written on it",
              "wood", "It is teak",
              });
   
   smell = "You smell the odor of wood, leather, clothes and steel.";
   
   dest_dir = ({ PPATH + "empty", "south",
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
