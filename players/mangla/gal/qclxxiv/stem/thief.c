#include "/players/qclxxiv/mymonster.h"
object knife;
reset(arg) {
	::reset(arg);
    add_money(random(30));
	if (arg) return;
	load_chat(10,({ 
"Thief looks at your possessions, as if he estimates their value.\n",
"Thief moves around you slowly.\n",
"Thief mumbles something.\n",
"Thief moves around you slowly.\n",
"Thief looks at his knife.\n",
	}));
	load_a_chat(10,({ 
"Thief says: I should never have come here\n",
"Thief says: shit,  they were right about this place\n",
"Thief says: why attack an innocent man like me?\n",
"Thief says: stop this please\n",
"Thief shouts: HELP\n",
	}));
	set_name("thief");
	set_race("skum");
	set_level(7);
	set_al(-10);
   	set_aggressive(0);
   	set_short("thief");
	set_gender(1);
   	set_long("A nasty looking thief.\n");
	set_size(3);
	knife = clone_object("players/qclxxiv/obj/qweapon");
	knife->set_class(10);
	knife->set_weight(1);
	knife->set_value(200);
	knife->name_qweapon( "knife" ); 
	move_object(knife,this_object());
	init_command("wield knife"); 
    add_money(random(50)+150);
}

monster_died() {
	notify("Thief rattles: uhh ohhh. \n");
}

