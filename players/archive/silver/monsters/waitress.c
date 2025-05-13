#define TP this_player()
#define NAME query_name()
#define OBJ "/players/silver/obj/"

inherit "/obj/monster";
object beer;


/*-------------ADD_COMMAND FUNCTIONS-----------------------------------*/
get_beer()
  {

 if( this_player()->query_player() && this_player()->query_immortal()   )
       {
        write("You snap your fingers.\n");
        say(TP->NAME + " snaps fingers.\n");

        write("Waitress comes to you and gives you a double beer.\n");
        say("Waitress gives a double  beer to " + TP ->NAME + ".\n");

        beer=clone_object(OBJ+"beer");
        transfer(beer,this_player());
      }
     else  /* player */
       {
        write("You snap your fingers.\n");
        say(NAME + " snaps fingers.\n");

     write("Waitress looks at you angrily and says 'You can't drink dude'.\n");
        say("Waitress looks angrily at " + TP->NAME + ".\n");
       };

   return 1;

  }   /* end of get beer */


destr_waitress()
  {
    write("Witress smiles at you and left.\n");
    say("Waitress smiles at " + TP->NAME + " and left.\n");
    destruct(this_object());
    return 1;
  
    }
/*-------------------------------------------------------------------*/

reset(arg)
  {
    ::reset(arg);
   if (!arg)
    {
     set_name("waitress");
     set_short("A waitress");
set_long("The waitress is really nice and cute girl you enjoy looking" +
 " at her \n" +
    "Better to stop that before you fantasy goes too far. You know" + 
  " that \n" + 
                  "she gives you a beer if you snap your fingers.\n");
     set_race("human");
     set_female();
     set_level(28);
     set_dex(60);
     set_al(1000);
     set_hp(1000);
     set_sp(0);
     set_wc(15);
     set_ac(15);
     set_aggressive(0);
     set_no_steal();
     set_size(3);
     set_dead_ob(this_object());
   }
  }

init()
 {
   ::init();
    add_action("get_beer","snap");
    add_action("destr_waitress","shoo");

    write("Waitress entered the room.\n");
    write("She smiles happily at you.\n");

}

