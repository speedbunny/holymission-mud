#include "/players/qclxxiv/mymonster.h"
object axe;

reset(arg) {
        ::reset(arg);
	 PLACE_IN_THIS(axe,"/players/qclxxiv/leaf7/throwaxe");
	 if (arg) return;
	 load_chat(10,({
		"The dwarfchampion looks at you suspiciously.\n",
		"The dwarfchampion chuckles.\n",
		"The dwarfchampion scratches his head.\n",
		"The dwarfchampion looks around.\n",
	  }));
	 load_a_chat(20,({
        "The dwarfchampion tries to get behind his opponent.\n",
        "The dwarfchampion attempts a mighty spell.\n",
        "The dwarfchampion utters angry curses.\n",
        "The dwarfchampion grunts intelligible dwarf curses.\n",
	  }));
	set_name("dwarf");
	set_alias("dwarfchampion"); 
	set_level(20);
   	set_wc(30);
	set_ac(13);
   	set_hp(1500);
	set_sp(100);
   	set_spell_mess1(
	"The dwarfchampion casts a spell and cruches one of his opponent's toes.");
   	set_spell_mess2(
		"The dwarfchampion casts a spell and cruches one of your toes.");
	set_chance(25);
	set_spell_dam(20);
    set_al(0);
   	set_aggressive(0);
   	set_short("Dwarfchampion");
   	set_long("Dwarfchampion, obviously the largest dwarf in the area.\n"+
			"Though he is small still, he looks rather strong.\n" );
    /* set_whimpy(); */
	set_gender(1);
	enable_commands();
	set_living_name("dwarfchampion");
}

/*
hit_player(dam) {
	set_heart_beat(1);
   	set_aggressive(1);
	return dam;
}

reduce_hit_point(dam) {
	set_heart_beat(1);
   	set_aggressive(1);
	return dam;
}
*/

throwaxe() {
	if (  present("throwaxe",this_object()) ) {
		init_command("throw axe");
		call_out("getaxe",1);
	}
	else getaxe();
}

getaxe() {
	object ax;
	if (random(10)>7) return;
	if (ax = present("throwaxe",environment(this_object()))) {
		move_object(ax, this_object() );
		write("Dwarfchampion takes the axe.\n");
	}
}

heart_beat() {
	::heart_beat();
    if (attacker_ob && present(attacker_ob)) {
		if (random(10)>6) throwaxe();
	}
}
