inherit"obj/monster";
string chats;

get_chats(){
    if(!chats){
	chats=allocate(3);
	chats[0]="The Drow guard says: Lolth is immortal!\n";
	chats[1]="The Drow Guard says: Queen Lolth's only threat has been eliminated!\n";
	chats[2]="The Drow guard screams: Prepare to die!\n";
    }
    return chats;
}
reset(arg){
    ::reset(arg);
    if (arg) return;
    set_race("drow");
    set_name("drow guard");
    set_alt_name("guard");
    load_chat(20,get_chats());
    set_ac(14);
    set_alias("drow");
    set_gender(1);
    set_level(25);
    set_wc(12);
    set_ac(18);
    set_aggressive();
    set_al(-5000);
    set_short("Drow guard");
    set_long("Here stands a dangerous looking drow guard with his hand on his sword.\n");
    add_money(200+random(150));
}

