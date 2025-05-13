inherit "obj/monster";
string chats;
object mstinger;
reset(arg) {
    ::reset(arg);
    if(!arg){
	set_name("mosquito");
	set_race("incent");
	set_short("Mosquito");
	set_long("A mosquito buzzing around you head and stinging you.\n");
	set_alias("mosquito");
	set_level(16);
	set_al(200);
	set_ac(7);
	set_wc(16);
	mstinger = clone_object("/players/tuppence/fortress/weapon/mstinger.c");
	transfer(mstinger,this_object());
	init_command("wield stinger");
	if(!chats) {
	    chats=allocate(1);
	    chats[0]= "Buzz Buzz Buzzzz\n";
	}
	load_chats(3,chats);
	set_spell_mess1("Mosquito stings you!\n");
	set_spell_mess2("Mosquito stings you with his stinger!\n");
	set_chance(20);
	set_spell_dam(10);
    }
}
