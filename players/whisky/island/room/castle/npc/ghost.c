
/* castle ghost */

inherit "/obj/npc";
#include "../defs.h"

void reset(int arg) 
{
     ::reset(arg);
     if (!arg) 
     {
        call_out("show_me",1);
        set_long("You see the shadow of a humanuid creature \n"+
                 "hovering in the air. It's empty eyes are \n"+
                 "looking at you. On it's leg it has an iron \n"+
                 "ball. And a chain in one of its ghostly hands\n");
        set_gender(0);
        set_aggressive(1);
        set_level(35);
        set_al(-0);
        set_spell_mess1("Castle ghost waves its hands\n");
        set_spell_mess2("Castle ghost touches you, you shiver !\n");
        set_chance(40);
        set_spell_dam(50+random(100)); 
        set_attacks(1);
        set_attacks_change(30);
        set_dodge(40);
        CO("chain");
        init_command("wield chain");
      }
}

void show_me()
{
        set_name("castle ghost");
        set_alt_name("ghost");
        set_short(query_name());
        set_race("undead");
}

varargs int hit_player(int dam,int kind,mixed elem)
{
// must be a magic weapon
      if (kind==0) 
      {
         if (this_player()->query_wc() < 15 )
        {
           if (!random(5))
               write("Your attack passes through the ghosts etheral form.\n");
           return ::hit_player(0,kind,elem);
        }
        return ::hit_player( (1 + dam)/2,kind,elem);
      }
// no backstab death .......
        else if (kind!=5 && kind!=8)
        {
              write("Nothing Happens.\n");
              return ::hit_player(0,kind,elem);
        }
// else damage/2
        return ::hit_player( (1 + dam)/2,kind,elem);
}
        
varargs int hold(object caller,int time)
{
     return ::hold(caller,0);
}
          
int detect_invis() 
{
     return 1;
}
       

