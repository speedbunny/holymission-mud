#include "/players/qclxxiv/mymonster.h"
object hammer;

reset(arg) {
        ::reset(arg);
	 if (arg) return;
	 load_chat(10,({
		"The dwarfen smith looks at you slightly frowning.\n",
		"The dwarfen smith chuckles.\n",
		"The dwarfen smith tussles his beard.\n",
		"The dwarfen smith giggles.\n",
	  }));
	 load_a_chat(20,({
        "The dwarfen smith tries to get behind his opponent.\n",
        "The dwarfen smith attempts a mighty spell.\n",
        "The dwarfen smith utters angry curses.\n",
        "The dwarfen smith grunts intelligible dwarf curses.\n",
	  }));
	set_name("dwarf");
	set_alias("smith"); 
	set_alt_name("dwarfen smith"); 
	set_level(20);
   	set_wc(30);
	set_ac(13);
   	set_hp(1500);
	set_sp(100);
   	set_spell_mess1(
	"The dwarfen smith casts a spell and cruches one of his opponent's toes.");
   	set_spell_mess2(
		"The dwarfen smith casts a spell and cruches one of your toes.");
	set_chance(25);
	set_spell_dam(20);
    set_al(0);
   	set_aggressive(0);
   	set_short("Dwarfen smith");
   	set_long("A dwarfen smith, old, bearded, his face black and soothy.\n"+
			"Though he is quite small, he looks strong like a bear.\n" );
	set_gender(1);
	enable_commands();
	set_living_name("dwarfsmith");
	set_size(1);
    hammer=clone_object("obj/weapon");
    hammer->set_id("tail");
    hammer->set_class(12);
    hammer->set_weight(2);
    hammer->set_value(1700);
    hammer->set_short("A hammer");
    hammer->set_long("The hammer of a dwarfen smith.\n");
    move_object(hammer,this_object());
	command("wield hammer",this_object());
}
