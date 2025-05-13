
/* kitiara */

inherit "obj/monster";
object shad;

reset(arg)
{
   object pot;

   ::reset( arg );
   
   if ( arg )
      return;

   set_race( "human" ) ;
   set_name( "death knight" );
   set_alias( "knight" );
   set_level( 55 );
   set_size( 3 );
   set_short( query_name() );
   set_long(
   "You see a rotten humanoid which is dressed like a paladin.\n"+   
   "Her eyes are glowing red and she looks like she has an evil\n"+
   "mind.\n");
   set_gender( 2 );
   set_ep( 3000000 );
   set_al( -3000 );
   add_money( 10000 );
   set_aggressive( 1 );
   set_number_of_arms( 2 );
   set_n_wc( 40 );

   change_spell( "fireball", 95, 95, 2);
   change_spell( "slay living", 95, 95, 6 );

   pot = clone_object( "/players/whisky/obj/hearo_potion" );
   transfer( pot, this_object() );
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
      if ( rnd < 10 )
         npc_process_spell( "fireball", vic );
      else if ( rnd < 15 )
         npc_process_spell( "slay living", vic );
   }
   return( 1 );
}


