inherit "obj/monster";
string chats;
object money;
reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("evil dark lord");
	set_race("beast");
	set_short("Evil Dark Lord");
	set_long("This is the Evil Dark Lord of the great fortress Haden. You can\n"+
	  "just sense the evil magic coming from him. He has a black aura\n"+
	  "around him. He cackles evilly at you as if he knows you are about\n"+
	  "to die!\n");
	set_alias("lord");
	set_level(80);
	set_al(-1000);
	set_ac(15);
	set_wc(35);
	set_dead_ob(this_object());
	money = clone_object("obj/money.c");
	money->set_money(8000);
	transfer(money,this_object());
	set_spell_mess1("Evil Dark lord casts a evil spell at his attacker!\n");
	set_spell_mess2("Evil Dark Lord sends a nightmare cloud after you!\n");
	set_chance(55);
	set_spell_dam(50);
	if(!chats) {
	    chats=allocate(5);
	    chats[0]= "Evil dark lord chants a evil spell.\n";
	    chats[1]= "Evil dark lord yells: Fool i shall destroy you!\n";
	    chats[2]= "You can hear the Evil Dark Lords claws scratching the stone table.\n";
	    chats[3]= "Evil dark lords eyes glow yellow and peer at you!\n";
	    chats[4]= "You can hear the crackling of evil magic.\n";
	}
	load_chat(3,chats);
    }
}
int monster_died(object ob)
{
    if(!this_player()->query_immortal())
    {
        shout(this_player()->query_name_true()+" has destroyed the Evil \
Dark Lord of Haden!\n");
	return 0;
    } else {
	tell_room(environment(this_object()), "Evil dark lord is destroyed!\n",this_player());
	write ("Sorry you are immortal it will not echoall.\n");
	return 0;
    }
}
