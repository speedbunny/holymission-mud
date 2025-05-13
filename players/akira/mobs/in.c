 /* last edit: 180394 whisky (roland) uni-linz.ac.at */
#define PPATH ("/players/patience/forestMonst/")
inherit "obj/monster";

reset(arg)
{
   object amulet;
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "mujina" );
   set_level( 50 + random( 10 ) );
   set_size( 3 );
   set_short( "an evil mujina" );
   set_long( "A mujina appears at first to be a normal person. It has a natural\n" +
             "appearance-altering spell to conceal its true visage, a ....\n" );

    amulet = clone_object("/players/patience/guild/nother/onyxRing" );
    transfer(amulet,this_object());
    amulet =clone_object("/players/patience/guild/narmour/amulet");
    transfer(amulet,this_object());
    command("wear amulet");
   set_dead_ob( "/players/patience/eastMonst/monst_died" );

   set_n_wc( 20 );
   set_n_ac( 18 );
   set_aggressive( 1 );
}

varargs int attack( object weap, int hand )
{
   object victim;
   victim = query_attack();
   if (victim && living(victim) &&
          environment(this_object())==environment(victim) )
   {
      if ( !victim->query_npc() && !random(5) )
      {
         tell_object(victim,
            "*** The mujina tries to change its appearance. BEWARE !!! ***\n" );
         call_out( "unmask", random(8) + 4, victim );
         return( 1 );
      }
   }
   
   return( ::attack( weap, hand ) );
}

unmask( victim )
{
   object madness;

   if (objectp(victim) && living(victim) && interactive(victim) ) 
   {
      if ( environment(this_object()) == environment(victim) )
      {
         tell_object( victim,
                 "The mujina alters its appearance. You look into a ....\n" +
             "\nOH NO, WHAT IS THIS. AND WHERE ARE YOU NOW !!!!!! HELP !!!\n" );
         if ( victim->query_immortal() ) return;

         madness = clone_object( "/players/akira/fun/strain" );
         move_object( madness, victim );
         madness->start_madness( victim );
         
         return( 1 );
      }
   }
}
 /* religion check for amaterasu */
 string query_religion()
{
    return "Amaterasu";
}
