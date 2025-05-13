#define TO this_object()

inherit "/players/tatsuo/GenObj/mymonster";

object weapon;

reset( arg )
{
   ::reset( arg );
    
   if ( arg )
      return;
  
   set_name("Gidayu Nitta");
   set_alt_name("nitta-san");
   set_alias("gidayu nitta");
   set_level( 35 );
   set_short("Gidayu Nitta");
   set_long( "This is Gidayu Nitta. He is dressed in dark-red ninja-clothes. His head\n" +
             "is wrapped with head-wrappings, so that you just can see his brown eyes.\n" +
             "He stands behind the desk and looks at you.\n" );

   load_chat( 10, ({ "Gidayu Nitta says: Do you need some ninja-stuff ?\n",
                     "Gidayu Nitta rearranges his armours.\n",
                     "Gidayu Nitta stares at your fingers.\n",
             }) );

   load_a_chat(20,
           ({ "Gidayu Nitta growls at you.\n",
              "Gidayu Nitta says: Die, outcast.\n",
             }) );

   set_gender(1);
   set_no_fear();
   set_follow_chance(0);
   set_parry(20);
   set_n_ac( 0 );
   
   set_ninja();
   set_accuracy( 30 );

   weapon = clone_object( "/players/tatsuo/guild/nweap/yari" );
   transfer( weapon, this_object() );
   command( "wield yari" );
}
