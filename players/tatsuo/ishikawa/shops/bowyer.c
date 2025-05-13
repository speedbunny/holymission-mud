/*coded by tatsuo for the samuria guild*/
#define PPATH "/players/tatsuo/guild/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

#define NORM_STORE ("/players/tatsuo/guild/"+"guild_bowyer")

inherit "room/room";

object trader;
string trader_name;

reset( arg )
{
   if ( !trader ) {
	trader=clone_object("/players/tatsuo/guild/npc/usaki");
      if ( trader )
         transfer( trader, this_object() );
         
      trader_name = trader->query_name();
   }

   if ( arg )
      return;
      
   set_light(1);
   short_desc = "In the Bowyer";
   long_desc = "This is the bowyer where samurai can buy special weapons of power\n"+
               "usable only by honorable samurai. It is extravegantly decorated to\n"+
               "honor the god of bowyer Raiden. There are lightning bolts carved into\n"+
               "the fine wooden desk that is in the room. There is a man behind the\n"+
               "desk how is dressed in the ceramonial robes of a priest. He smiles\n"+
            "confidently at you and beckons you to take you time shopping.\n"+
               "There is a sign hanging from the wall.\n";
   
   items = ({ "chamber", long_desc,
              "floor", "The floor is made of wood",
              "desk", "It is a large wooden desk, which devides the room in two parts",
              "walls", "The walls are made of wood",
              "wall", "The wall is made of wood",
              "shelf", "There are a lot of weapons at the shelf",
      "cushions", "The cushions are made of pink silk and look very comfortable",
      "bolt", "The lightining bolt is the sysmbol of Raiden god of Bowyer.",
              "bows", "Bows line the walls each a great tribute to Raiden",
              "sign", "There are some strange oriental letters written on it",
              "wood", "It is teak",
              });
   
   smell = "You smell the odor of wood, leather, clothes and steel.";
   
   dest_dir = ({PPATH + "court3.c","north",
              });
              
   transfer(clone_object("/players/tatsuo/guild/npc/ming.c"), this_object());
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
