
/* skeleton warrior */

inherit "obj/npc";

void reset(int tick)
{
   ::reset( tick );

   if (tick) 
       return;

   set_race( "undead" ) ;
   set_name( "skeleton warrior" );
   set_alt_name("skeleton");
   set_alias("warrior");
   set_level( 19 );
   set_size( 3 );
   set_short( query_name() );
   set_long(
   "A strong looking, humanoid pile of crawling bones !\n");
   set_gender( 0 );
   set_al( -150 );
   add_money( 1500 );
   set_aggressive( 1 );
   set_n_wc( 20 );
   set_attacks(2);
   set_attacks_change(60);
}

