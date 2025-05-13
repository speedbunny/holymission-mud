/* Galadriel 1-SEP-1994: fixed bug in help_it() */
inherit "/obj/armour";

object *owner;
int timer;

reset( arg )
{
   ::reset( arg );
   
   if ( arg )
      return;
    
   set_name( "ring" );
   set_alias( "onyx ring" );
   set_type( "ring" );
   set_ac(0);
   set_size( "any" );
   
   set_short( "an onyx ring" );
   set_long( 
"A very precious looking onyx ring. It has a magical, but VERY demonic aura.\n"+
"A voice deep inside of you tells you: THRUST IT AWAY !!!\n"+
             "Type \"help onyx ring\" for further infos.\n" );
   set_value( 5000 );
   set_weight( 1 );
   set_ac( 0 );
   owner = 0;
}

id( x )
{
   return( ::id(x) || x == "_onyx_ring_" );
}

query_ninja_wear( ) { return( 1 ); }

query_owner() { return( owner ); }

init()
{
   ::init();

   add_action( "help_it", "help" );
   add_action( "_lightning", "lightning" );
   add_action( "_heal", "heal" );
}

get(arg)
{
   if (!owner)
      owner = this_player();
   return( ::get(arg) );
}

help_it( arg )
{
   if ( !arg || arg != "onyx ring" )
      return 0;
      
    write( "These are the functions of the ring:\n" +
             "\"Lightning <monster>\": A lightning will strike your opponent,\n" +
             "\"heal myself\": The magic of the ring will heal you.\n" );

   return( 1 );
}

wear( arg )
{
   ::wear( arg );
   
   if ( !id( arg ) )
     return( 0 );

   if ( !query_worn() )
      return( 1 );

   call_out( "kill_player", 100+random(100) );
   
   return( 1 );
}

kill_player()
{
   if ( query_worn() && worn_by && living( worn_by ) ) {
      if ( random( 100 ) < 10 ) {
         tell_object( worn_by,
                "Suddenly the onyx ring explodes with a bright flash, releasing its demonic\n" +
                 "force. You can see a bright, blinding light, from which two eyes are\n" +
                 "staring at you causing you awful pain !\n");
         say( "The ring of " + capitalize( worn_by->query_name() ) + "explodes with a " +
              "bright flash, releasing\nits demonic force. You can see a bright, blinding "+
              "light,\nfrom which two eyes are staring at " + capitalize( worn_by->query_name() ) +
              ". Suddenly, with a blink of theses eyes, " + capitalize( worn_by->query_name() ) +
              " got a bad hit !!!\n" );
         
         if ( living( worn_by ) )
         {
           if (random(5))
            worn_by->hit_player(worn_by->query_max_hp()/3 * 2 ,7);
           else 
            worn_by->hit_player(1000,7);
         }
            
         destruct( this_object() );
         
         return( 1 );
      }
   }

   call_out( "kill_player", 20 );
}

_lightning( arg )
{
   object atWhom;

   if ( !arg ) {
      if ( !worn_by ) {
         write( "You have to wear the ring for this.\n" );
         return( 1 );
      }
      if ( worn_by->query_attack() )
         atWhom = worn_by->query_attack();
      else
         return( 0 );
   }
   else {
      if ( !worn_by ) {
         write( "You have to wear the ring for this.\n" );
         return( 1 );
      }
      atWhom = find_living( arg );
   }
      
   if ( !atWhom || !living( atWhom ) || !present( atWhom, environment( worn_by ) ) ) {
      write( "Sorry, but this is not a living or you cannot see it.\n" );
      return( 1 );
   }
   
   tell_object( worn_by,
      "Your ring starts to glow. Suddenly a bright lightning strikes your opponent !!!\n" );
   tell_object( atWhom, capitalize(worn_by->query_real_name()) + "'s ring starts to" +
      "glow.\nSuddenly a bright lightnings strikes you !!!\n" );
   say( capitalize(worn_by->query_real_name()) + "'s ring starts to glow.\nSuddenly " +
      "a lightning strikes " + capitalize( worn_by->query_real_name() ),
      atWhom );


   atWhom->hit_player( 25 + random( 25 ) );
   
   return( 1 );
}

_heal( arg )
{
   if ( arg != "myself" )
      return( 0 );
      
   if (timer == 1)
   {
       write("You have to wait for a while.\n"); /* whisky */
       return 1;
   }

   if ( !worn_by ) {
      write( "You have to wear the ring for this.\n" );
      return( 1 );
   }
      
   if (worn_by->query_hp() >= worn_by->query_max_hp())
   {
       tell_object(worn_by,"You are already full healed !\n");
       return 1;
   }
   worn_by->reduce_hit_point( -5 );
   
   tell_object( worn_by, "You feel better now.\n" );

   timer = 1;
   call_out("timer_zero",2);
   return( 1 );
}
void timer_zero()
{
    timer = 0;
}
