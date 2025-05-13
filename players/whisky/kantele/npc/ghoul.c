
/* ghoul */

inherit "obj/monster";

void reset(int tick)
{
   int    i;

   ::reset( tick );

   if (tick) 
       return;

   set_race( "undead" ) ;
   set_name( "rotten ghoul" );
   set_level( 9 );
   set_size( 3 );
   set_short( query_name() );
   set_long(
   "You see a rotten, slimy humanoid glaring hungrily at you !\n");
   set_gender( 0 );
   set_al( -100 );
   add_money( 250 );
   set_aggressive( 1 );
   set_n_wc( 8 );

   change_spell( "paralyze", 99, 99, 3 );
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
      if ( rnd < 15 )
         npc_process_spell( "paralyze", vic );
   }
   return( 1 );
}
