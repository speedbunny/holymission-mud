inherit "obj/monster";
string chats;
object money;
reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("mad fly");
	set_race("fly");
	set_short("Mad fly");
	set_long("A mad fly buzzes around you.\n");
	set_alias("fly");
	set_level(17);
	set_al(-300);
	set_ac(8);
	set_wc(19);
	set_aggressive(1);
	money = clone_object("obj/money.c");
	money->set_money(600);
	transfer(money,this_object());
	if(!chats) {
	    chats=allocate(2);
	    chats[0]= "A mad fly buzzes around you head annoyingly.\n";
	    chats[1]= "Buzzzzzz!\n";
	}
	load_chat(5,chats);
    }
}
