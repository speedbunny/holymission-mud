
/* haunt */

inherit "obj/npc";

void reset(int tick)
{
   ::reset( tick );

   if (tick) 
       return;

   set_race( "undead" ) ;
   set_name( "rotten skeleton" );
   set_alt_name("skeleton");
   set_level( 9 );
   set_size( 3 );
   set_short( query_name() );
   set_long(
   "A humanoid pile of crawling bones !\n");
   set_gender( 0 );
   set_al( -50 );
   add_money( 150 );
   set_aggressive( 1 );
   set_n_wc( 3 );
   set_attacks(1);
   set_attacks_change(30);
}

