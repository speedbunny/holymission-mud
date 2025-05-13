
/* haunt */

inherit "obj/npc";

void reset(int tick)
{
   ::reset( tick );

   if (tick) 
       return;

   set_race( "undead" ) ;
   set_name( "ghostly haunt" );
   set_alt_name("haunt");
   set_level( 29 );
   set_size( 3 );
   set_short( query_name() );
   set_long(
   "A half-rotten humanoid crawling slowly onto you !\n");
   set_gender( 1 );
   set_al( -900 );
   add_money( 2000 );
   set_aggressive( 1 );
   set_n_wc( 30 );
   set_attacks(3);
   set_attacks_change(60);
   set_spell_mess1("");
   set_spell_mess2("The Ghostly haunt touches you !");
   set_chance(30);
   set_spell_dam(90+random(150));
}

