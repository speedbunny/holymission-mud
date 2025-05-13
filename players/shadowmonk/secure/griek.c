inherit "obj/monster";
#include "/players/shadowmonk/include/defs.h"
object who;

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("Dodo's persoonlijke Griek");
	set_alias("griek");
	set_short("Dodo's persoonlijke Griek");
	set_long("This is Dodo's persoonlijke Griek.. een echte EIKEL.\n");
	set_race("man");
	set_hp(1);
	set_level(1);
	set_wc(1);
	set_ac(1);
	set_aggressive(0);
    }
}



heart_beat() {
    ::heart_beat();
switch(random(10))
  {
   case 0 : say("Dodo's Griek fluit naar Dodo\n"); break;
   case 4 : say("Dodo's Griek vraagt de tijd aan Dodo\n"); break;
   case 9 : say("Dodo's Griek jumps on Dodo\n"); break;
  }
    who=find_player("ausus");
    if (who && ENV(who)) {
	if (ENV(who) != ENV(this_object())) {
	    say("Dodo's Griek drools after Dodo.\n");
	    move_object(this_object(),ENV(who));
	}
    }
}

int attack() 
{
 return 0;
}
