inherit "obj/monster";
string chats;
object money;
reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("dirty troll");
	set_race("troll");
	set_short("Dirty troll");
	set_long("This troll looks as if he has been playing in the mud.\n");
	set_alias("troll");
	set_level(18);
	set_al(-200);
	set_ac(8);
	set_wc(19);
	if(!chats) {
	    chats=allocate(2);
	    chats[0]= "Dirty troll burps.\n";
	    chats[1]= "Dirty troll says: Hey you! What do you think you are doing here?\n";
	}
	load_chat(5,chats);
	money = clone_object("obj/money.c");
	money->set_money(2000);
	transfer(money,this_object());
    }
}
