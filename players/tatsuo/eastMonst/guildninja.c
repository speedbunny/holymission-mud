#define TO this_object()

  /* moved out by whisky : its buggy 
inherit "/players/tatsuo/GenObj/mymonster";
     */

inherit "/obj/monster";
object weapon;

reset( arg )
{
   ::reset( arg );
    
   if ( arg )
      return;
  
   set_name("ninja");
   set_alt_name("guard");
   set_alias("ninja guard");
   set_level(50);
   set_short("A ninja guard");
   set_long( "This is a guard of the ninja guild. He wears a red-black robe and you\n" +
             "can only see his eyes, which are staring at you. He seems to very strong\n" +
             "and you'd better run, but it could already be too late !!!\n" );

  load_a_chat(20,(
            { "The ninja guard growls at you.\n",
              "The ninja guard says: I kill you bastard.\n",
            }));

  /*
  set_no_fear();
  set_follow_chance(0);
  set_parry(20);
  set_n_ac(0);

  set_ninja();
  set_accuracy( 30 );

  weapon = clone_object( "/players/tatsuo/guild/nweap/sai" );
*/
  if (objectp(weapon))  /* whisky */
     move_object(weapon, this_object() );
  command( "wield sai" );
}
