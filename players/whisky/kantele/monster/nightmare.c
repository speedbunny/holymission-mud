
/* nightmare */

inherit "obj/npc";

void reset(int tick)
{
   int    i;

   ::reset( tick );

   if (tick) 
       return;

   set_race( "undead" ) ;
   set_name( "nightmare" );
   set_level( 25 );
   set_size( 3 );
   set_short( "nightmare" );
   set_long(
   "A black horse like undead creature, with glowing red eyes\n"+
   "and burning hooves.\n");
   set_gender( 0 );
   set_al( -500 );
   add_money( 5000 );
   set_aggressive( 1 );
   set_number_of_arms( 4 );
   set_n_wc( 20 );

   change_spell( "paralyze", 99, 99, 3 );
}

int detect_invis()
{
   return( 1 );
}

int infravision()
{
   return( 1 );
}

int cast_spell( object vic )
{
   int rnd;

   if ( !query_casting() ) 
   {
      rnd = random( 100 );
      if ( rnd < 5 )
         npc_process_spell( "paralyze", vic );
   }
   return( 1 );
}
