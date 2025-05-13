inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
if(arg) return;

    set_name("darkstaff");
    set_race("human");
    set_gender(1);
    set_alt_name("darkstaff");
    set_alias("man");
    set_short("Darkstaff");
    set_long(
"A tall and regal man.  Your eyes are drawn to his haughty face.  He glares "+
"at you with unveiled hatred.  His body is wrapped in a thick, purple cloak. "+
"However, you get the impression that he is incredibly strong.  His left "+
"hand is wrapped around the shaft of an impressive staff.\n");
    set_level(40);
    set_hp(4500);
    set_al(-1000);
    set_ac(31);
    set_wc(50);
    set_chance(7);
    set_spell_dam(30);
    set_spell_mess1("Badazio mumbles and you feel a shock run through you!\n");
    set_spell_mess2("Badazio mumbles and you feel a shock run through you!\n");
    move_object(clone_object(si+"/robe.c"), TO);
    move_object(clone_object(quest+"/mage_staff.c"),TO);
init_command("wield staff");
init_command("wear robe");
}
init(){
  ::init();
        heart_beat();
  }

heart_beat(){
        object ob;
        ob=TO->query_attack();
        ::heart_beat();
        if(TO->query_attack()){
        tell_object(ob,TO->query_name()+" summons a ball of fire on you.\n");

        say(TO->query_name()+" demolishes "+ob->query_name()+" with a fireball.\n",ob);
       ob->hit_player(80+ random(30));
        return;
      }
}
