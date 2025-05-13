inherit "/obj/monster";
object shield, mace, mail;
string chat_str;

reset(arg) {
	::reset(arg);
	chat_str=({"Kane says: Word!\n"});
	if(arg) return 1;
	set_name("kane");
	set_alias("troll");
	set_gender(1);
	set_short("Kane the Troll");
	set_long("Kane is a Troll palladin.  He is very strong.\n" + "Be very careful!\n");
	set_level(15);
	set_size(4);
	add_money(100 +random(100));
	load_chat(4,chat_str);
	set_al(-50);
if(!present("shield")){
	  shield=clone_object("players/airborne/armours/lshield");
	  mail=clone_object("players/airborne/armours/double");
	  mace=clone_object("players/airborne/weapons/mace");
	  move_object(shield,this_object());
	  move_object(mail,this_object());
	  move_object(mace, this_object());
	  init_command("wear shield");
	  init_command("wear mail");
	  init_command("wield mace");
	}
   return 1;
}
