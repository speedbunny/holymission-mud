#define TO this_object()

inherit "/players/tatsuo/GenObj/mymonster";

object weapon;

reset( arg )
{
   ::reset( arg );
    
   if ( arg )
      return;
  
   set_name("Akiko Ito");
   set_alt_name("ito-san");
   set_alias("akiko ito");
   set_level( 45 );
   set_short("Akiko Ito");
   set_long( "This is Akiko Ito. She wears a peach kimono with a  symbol on its back.\n" +
             "The symbols shows the rising red sun. She sits on a cushion by the table\n" +
             "and looks appreciatively at you.\n" );

   load_chat( 10, ({ "Akiko Ito says: Do you want a drink, ninja?\n",
                     "Akiko Ito bows her head to you.\n",
                     "Akiko Ito places herself in a better position.\n",
                     "Akiko Ito looks appreciatively at you.\n", 
             }) );

   load_a_chat(20,
           ({ "Akiko Ito scratches you.\n",
              "Akiko Ito tears at your heart.\n",
             }) );

   set_gender(2);
   set_no_fear();
   set_follow_chance(0);
   set_parry(20);
   set_n_ac( 0 );
   set_feelings();

   set_ninja();
   set_accuracy( 10 );

   weapon = clone_object( "/players/tatsuo/guild/nweap/sa-tja-koen" );
   transfer( weapon, this_object() );
   command( "wield sa-tja-koen" );
}
