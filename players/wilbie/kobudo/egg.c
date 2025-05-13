#define AIT          all_inventory(this_object())
#define TO           (this_object())
#define TP           (this_player())
#define TPN          (this_player()->query_name())

#define THROW_SKILL  (1)

#define BLINDING_LIQUID "/players/patience/guild/nother/blind_liquid"

inherit "obj/container";

reset( arg )
{
   ::reset( arg );
   
   if ( arg )
      return;
      
   set_name( "'egg'" );
   set_alias( "egg" );
   set_short( "an 'egg'" );
   set_long( "'Eggs' are small containers used to deliver the various ninja powders to\n" +
             "targets in the combat. They shatter on impact, releasing their contents in\n" +
             "a cloud to affect the target.\n" );

   set_weight( 1 );
   set_max_weight( 4 );
   set_value( 100 );
   set_can_close( 1 );
}

init( )
{
   ::init();
   
   add_action( "_mumble", "mumble" );
}

query_npowder_throw( )
{
   if ( present( "white pepper", TO ) && present( "red pepper", TO ) &&
        sizeof(AIT) == 4 )
      return( 3 );
   if ( sizeof( all_inventory( this_object() ) ) == 1 )
      if ( all_inventory(this_object())[0]->id( "blinding liquid" ) )
         return( 2 );

   if ( sizeof( all_inventory(this_object()) ) == 2 )
      if ( (AIT[0]->id( "shikome blood" ) &&AIT[1]->id( "mukade blood" )) ||
           (AIT[0]->id( "mukade blood" ) &&AIT[1]->id( "shikome blood" )) )
         return( 1 );
            
   return( 0 );
}

throw_powder( arg )
{
   int res;

   res = query_npowder_throw();
   
   if ( res == 1 )
      return( throw_blood( arg ) );
   else if ( res == 2 )
      return( throw_blind( arg ) );
   else if ( res == 3 )
      return( throw_pepper( arg ) );
      
   return( 0 );
}

throw_blood( arg )
{
   object who, inv, nsoul;
   int    i;

   who = present( arg, environment(this_player()) );
   nsoul = present( "ninjasoul", this_player() );
   if ( !nsoul ) {
      write( "You are no ninja, you cannot use this egg !!!\n" );
      return( 1 );
   }
   
   if ( random(100) >= nsoul->query_throw_skill() ) {             /* too unskillfull ? */                             /* miss              */
      tell_object( this_player(), 
         "You try to throw a blood-egg at your opponent, but you are so unskillfull,\n" +
         "that you break the egg in your hand and spread the blood over yourself !!!\n" );
      tell_object( who,
           TP->query_name() +
           " tries to throw a blood-egg at you, but " + TP->query_pronoun() + " breaks\n" +
           "the egg and spreads the blood over " + TP->query_possessive() + " body.\n" );
      say( TP->query_name() + " tries to throws a blood-egg at " + 
          who->query_name() + ",\n" +
          "but " + TP->query_pronoun() + " breaks the egg and spreads the blood over " +
          TP->query_possessive() + " body.\n",
          who);

      inv = all_inventory( environment(TP) );
      for ( i = 0; i < sizeof( inv ); i++ ) {
         if ( living( inv[i] ) )
            if ( inv[i]->query_npc() )
               inv[i]->attack_object( TP );
      }
      
      destruct( TO );

      return( 1 );
   }

   nsoul->advance_skill( TP, THROW_SKILL, 1, 100 );

   tell_object( this_player(), 
                "You THROW a blood-egg onto your opponent. The egg shatters on impact\n" +
                "and spreads blood all over your enemies body.\n" );
   tell_object( who,
                TP->query_name() +
                " throws a blood-egg onto you. The egg shatters\n" +
                "on impact and spreads blood all over your body.\n" );
   say( TP->query_name() + " throws a blood-egg at " + 
        who->query_name() + ". The egg shatters\n" +
        "on impact and spreads blood all over " + who->query_possessive() + "'s body.\n",
        who);
        
   
   inv = all_inventory( environment(TP) );
   for ( i = 0; i < sizeof( inv ); i++ ) {
      if ( living( inv[i] ) )
         if ( inv[i]->query_npc() || inv[i] != who )
            inv[i]->attack_object( who );
   }
   
   who->attacked_by( TP );
   who->attack_object( TP );
   
   inv = all_inventory( this_object() );
   for ( i = 0; i < sizeof( inv ); i++ )
      destruct( inv[i] );
   destruct( TO );
   
   return( 1 );
}

throw_blind( arg )
{
   object who, inv, nsoul;
   int    i, holdTime;

   who = present( arg, environment(this_player()) );
   nsoul = present( "ninjasoul", this_player() );
   if ( !nsoul ) {
      write( "You are no ninja, you cannot use this egg !!!\n" );
      return( 1 );
   }
   
   if ( random(100) >= nsoul->query_throw_skill()*2 ) {          /* too unskillfull ? */                             /* miss              */
      write( "You are too unskillful to throw this blinding-egg.\n" );
      return( 1 );
   }

   nsoul->advance_skill( TP, THROW_SKILL, 1, 100 );

   tell_object( this_player(),
                "You THROW a blinding-egg at your opponent. The egg shatters on impact\n" +
                "with a bright flash and BLINDS your opponent !!!\n" );
   tell_object( who,
                TP->query_name() +
                " throws a blinding-egg at you. The egg shatters\n" +
                "on impact with a bright flash and blinds you !!!\n" );
   say( TP->query_name() + " throws a blinding-egg at " + 
        who->query_name() + ". The egg shatters\n" +
        "on impact with a bright flash and blinds " + who->query_name() + ".\n",
        who);
   
   inv = all_inventory( this_object() );
   for ( i = 0; i < sizeof( inv ); i++ )
      destruct( inv[i] );
   
   holdTime = 
     (this_player()->query_wis() + this_player()->query_int() + 10)/10 + 1;
   who->hold( TP, holdTime );
   
   who->attacked_by( TP );
   who->attack_object( TP );
   destruct( TO );

   return( 1 );
}

_mumble( arg )
{
   object bl;

   if ( !arg )
      return;
      
   if ( arg == "takayoto ai gemosa" ) {
      say( this_player()->query_name() + " mumbles something.\n" );
      
      if ( sizeof( all_inventory(this_object()) ) == 2 ) {
         if ( !(present( "fluorescent moss", this_object() ) &&
              present( "reflecting liquid", this_object() ) ) )
         {
            write( "Mumbeling these holy words affect nothing!\n" );
            return( 1 );
         }
      }
      else {
         write( "Mumbeling these holy words affect nothing!\n" );
         return( 1 );
      }
      
      if ( this_player()->query_sp() < 30 ) {
         write( "You are too low on power, so your words affect nothing.\n" );
         return( 1 );
      }
      
      this_player()->restore_spell_points( -30 );
      
      while( sizeof( all_inventory( this_object() ) ) )
         destruct( all_inventory( this_object() )[0] );
      
      bl = clone_object( BLINDING_LIQUID );
      if ( transfer( bl, this_object() ) )
         move_object( bl, this_object() );

      write( "As you mumble these holy words, a blinding flash comes out of the egg !\n" );
      say( "You can see a blinding flash coming out of an egg of " + this_player()->query_name() );
   }

   return( 1 );
}

throw_pepper( arg )
{
   object nsoul, who, shad, inv;
   int    i;

   if ( !arg )
      who = TP->query_attack();
   else
      who = present( arg, environment(this_player()) );
   if ( !who ) {
      write( "There is nobody called "+arg+" here !\n" );
      return( 1 );
   }

   nsoul = present( "ninjasoul", this_player() );
   if ( !nsoul ) {
      write( "You are no ninja, you cannot use this egg !!!\n" );
      return( 1 );
   }
   
   if ( query_open() == 1 ) {
      write( "Arrggghhhh !!!! The egg is still open !!!!!\n"+
             "You pour the pepper all over yourself !!!\n" );
      say( TPN+" tries to throw an 'egg', but is so clumsy,\nthat "+
            TP->query_pronoun()+" pours pepper all over "+
            TP->query_possessive()+"self !\n" );

      shad = clone_object( "/players/patience/guild/nother/sneeze_shad" );
      shad->start_shadow( TP, 20 );
      who->attack_object(TP);
   }
   else if ( random(100) >= nsoul->query_throw_skill()+TP->query_dex() ) {
      write( "You aim at your opponent, but unfortunately you MISS !!!\n" );
      say( TPN+" throws an 'egg' over the head of "+TP->query_possessive()+
             " opponent.\n", who );
      tell_object( who, TPN+" tried to throw an 'egg' at you, but "+
                   "fortunately missed.\n" );
   }                                                       // it's a hit
   else {
      write( "You throw a PEPPER-BOMB right into the face of you opponent,\n"+
             "making him sneezing !!!\n" );
      say( TPN+" throws an 'egg' right into the face of "+
           who->query_name()+",\nmaking "+who->query_objective()+" sneezing"+
           " !!!\n" );
      tell_object( who, TPN+" throws an 'egg' into your face !!!\n"+
          "You smell pepper and your eyes beginning to fill with tears !\n" );
      nsoul->advance_skill( TP, THROW_SKILL, 1, 100 );

      who->attacked_by( TP );
      who->attack_object( TP );
      TP->attack_object( who );

      shad = clone_object( "/players/patience/guild/nother/sneeze_shad" );
      shad->start_shadow( who, 20+random(nsoul->query_throw_skill())/5 );
   }

   is_open = 1;                // otherwise shit msg for the player !!!!
   inv = all_inventory( this_object() );
   for ( i = sizeof(inv)-1; i >= 0; i-- )
      destruct( inv[i] );
   destruct( this_object() );

   return( 1 );
}
