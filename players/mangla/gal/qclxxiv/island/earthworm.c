#include "/players/qclxxiv/island/ianimal.h"
predator() { return 1; }
shyness() { return 0; }
int count;
reset(arg) {
	count++;
	if (count>2) {
		destruct(this_object());
		return;
	}
	::reset(arg);
	if (arg) return;
	 load_chat(10,({
		"Worm creeps around in circles.\n",
		"Worm sucks something fromout of the earth.\n",
		"Worm curls and twists.\n",
	  }));
	 load_a_chat(15,({
        "Worm tries to curl around its attackers legs.\n",
		"Worm makes weird, irritated, and dirty-sounding noises.\n",
	  }));
	set_name("earthworm");
	set_alias("worm");
	set_level(15);
   	set_wc(20);
	set_ac(20);
   	set_hp(700);
	set_sp(70);
	set_al(-30);
   	set_short("A giant earthworm");
   	set_long("A giant earthworm, clearly some magically inflicted mutant.\n");
   	set_spell_mess1("Earthworm bites its opponent.");
   	set_spell_mess2("Earthworm bites you.");
	set_chance(15);
	set_spell_dam(25);
	set_size(5);
}

do_attack(obj) {
	attack_object(obj); 
	attack();
}

set_attack(obj) {
	call_out("do_attack",0,obj);
}

