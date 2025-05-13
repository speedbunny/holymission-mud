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
  
   set_name("Hawamuku Ajakudji");
   set_alias( "ajakudji-san" );
   set_alt_name( "ajakudji-San" );
   set_level(70);
   set_short("A very learned ninja");
   set_long(
      "This obviously is the most learned ninja you have ever seen. He is\n"+
      "even better than the shogun of the guild and he has spent all his\n"+
      "life to get knowledge of the ninja-kis. Fortunately he has decided to\n"+
      "make his knowledge popular, and he will be eager give you practice.\n");

  load_a_chat(40,(
            { "Ajakudji-San growls at you.\n",
              "Ajakudji-San says: YOU ARE DOOMED, UNWORTHY !!!\n",
              "Ajakudji-San says: YOU ARE DEAD MEAT !!!\n",
            }));

  /*
  set_no_fear();
  set_follow_chance(0);
  set_parry(20);
  set_n_ac(0);

  set_ninja();
  set_accuracy( 30 );

  */
  weapon = clone_object( "/players/tatsuo/guild/nweap/sai" );
  if (objectp(weapon))  /* whisky */
     move_object(weapon, this_object() );
  command( "wield sai" );

   set_chance( 100 );
   set_spell_mess1("Ajakudji-San hits his opponent CRITICALLY at the head !!!");
   set_spell_mess2("Ajakudji-San hits you CRITICALLY at the head !!!" );
   set_spell_dam( 100 );

   set_dead_ob( "/players/tatsuo/eastMonst/monst_died" );
}

init()
{
   add_action( "_up", "up" ); 
}

_up()
{
   if ( this_object()->query_attack() == this_player() ) {
      write( "Ajakudji-San blocks the way back up !!!\n" );
      return( 1 );
   }

   return( 0 );
}
