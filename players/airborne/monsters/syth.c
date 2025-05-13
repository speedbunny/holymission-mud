inherit "/obj/monster";
object helm,earbiter;
string chat_str;

reset(arg) {
::reset(arg);
chat_str=({"Syth says: Fight me, I dare ya!\n"});
if (arg) return 1;
	set_name("syth");
	set_alias("thrillseeker");
	set_short("Syth Thrillseeker");
	set_long("This is the goblin they call 'Thrillseeker'. He is daring and bold!\n" + "He can be, he's just too good.\n");
	set_level(20);
	add_money(100 + random(500));
	load_chat(1,chat_str);
	set_al(-100);
	set_whimpy();
	set_frog();
	if (!present("earbiter")) {
	   earbiter=clone_object("players/airborne/weapons/earbiter");
	   move_object(earbiter,this_object());
	helm=clone_object("players/airborne/armours/helmet");
	move_object(helm, this_object());
	   init_command("wield maul");
	  init_command("wear helmet");
	}
   return 1;
}
