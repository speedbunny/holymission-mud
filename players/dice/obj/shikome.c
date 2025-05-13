#define PPATH ("/players/patience/eastMonst/")
inherit "obj/monster";

reset(arg)
{
   int rnd;

   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "shikome" );
   set_level( 10 );
   set_size( 2 );
   set_wc(10);
   set_short( "a shikome" );
      /* Corrected by Dice, you forgot to open the long :) */
   set_long("It lives in caves and under the earth. It envies and hates all humans.\n"+
            "A few have wandered far from Ezo in search of new land and human slaves.\n" );


   rnd = random( 50 );
   switch( rnd ) {
      case 0..10:
         transfer( clone_object( "/players/patience/guild/nweap/tanto" ), 
                   this_object() );
         break;
      case 11..21:
         transfer( clone_object( "/players/patience/guild/nweap/aikuchi" ),    
                   this_object() );
         break;
      case 22..27:
         transfer( clone_object( "/players/patience/guild/nweap/shuriken" ),
                  this_object() );
         break;
      case 28..33:
         transfer( clone_object( "/players/patience/guild/nweap/shuriken" ),
                  this_object() );
         break;
      case 34..40:
         transfer( clone_object( "/players/patience/guild/nweap/aikuchi"),
                  this_object() );
         break;
      default: 
         break;
   }
   command( "powerup" );  

   set_dead_ob( "/players/patience/eastMonst/monst_died" );
}

init( )
{
   ::init();

   if (this_player()->query_race() == "human")
         /* Changed by Dice to set the monster to be aggrassive to 
           Humans only */
      set_aggressive( 1 );
}
