inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
    ::reset();
    set_name("dragon");
    set_race("dragon");
    set_gender(0);
    set_alias("guard");
    set_short("Treasury guard");
            set_long(
"A medium size dragon curls protectively around the treasury of Bismarck. "+
"Her silver scales glimmer as her sinious body moves.  Her five inch long "+
"teeth glisten with saliva as she glares intently into your eyes.\n");
    set_level(20);
    set_hp(1500);
    set_al(-400);
    set_ac(11);
    set_wc(30);
    set_chance(7);
    set_spell_dam(random(10) + 50);
    set_spell_mess1("The dragon breathes flame on you");
    set_spell_mess2("The dragon breathes flame at you");
    }
/*
init(){
  ::init();
        heart_beat();
  }

heart_beat(){
        object ob;
        ob=this_object()->query_attack();
        ::heart_beat();
        if (this_object()->query_attacking(ob)) {
        tell_object(ob,this_object()->query_name()+" breathes fire on you.\n");
        say(this_object()->query_name()+" covers "+ob->query_name()+" in flames.\n",ob);
        ob->hit_player(random(25));
        return;
      }
      }
*/
