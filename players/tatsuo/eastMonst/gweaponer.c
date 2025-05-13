#define TO this_object()

inherit "/players/tatsuo/GenObj/mymonster";

object weapon;

reset( arg )
{
   ::reset( arg );
    
   if ( arg )
      return;
  
   set_name("Yukio Usami");
   set_alt_name("usami-san");
   set_alias("yukio usami");
   set_level( 45 );
   set_short("Yukio Usami");
   set_long( "This is Yukio usami. She wears a white kimono with a  picture on it.\n" +
             "The picture shows two crossed katanas. She stands behind the desk and\n" +
             "looks patiently at you.\n" );

   load_chat( 10, ({ "Yukio Usami says: Do you need a weapon, ninja?\n",
                     "Yukio Usami bows to you.\n",
                     "Yukio Usami looks at her weapons.\n",
                     "Yukio Usami looks patiently at you.\n", 
             }) );

   load_a_chat(20,
           ({ "Yukio Usami scratches you.\n",
              "Yukio Usami tears at your hear.\n",
             }) );

   set_gender(2);
   set_no_fear();
   set_follow_chance(0);
   set_parry(20);
   set_n_ac( 0 );
   set_feelings();

   set_ninja();
   set_accuracy( 20 );

}
