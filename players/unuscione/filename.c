inherit "obj/monster";
// object shoes;
string chats;
reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("unuscione's Tangoing Mango");
	set_race("fruit");
	set_short("unuscione's Tangoing Mango");
	set_long("The Tangoing Mango loves to Tango almost as much as it\n"+
	   	 "loves Unuscione!\n");
	set_alias("mango");
	set_level(1);
	set_al(1000);
	set_ac(1);
	set_wc(20);
	if (!chats) {
	    chats=allocate(4);
	    chats[0]="The Tangoing Mango tangos with Unuscione!\n";
	    chats[1]="The Tangoing Mango says: Hey baby wanna dance?\n";
	    chats[2]="The Tangoing Mango tickles Unuscione to death!\n";
	    chats[3]="The Tangoing Mango giggles like Unuscione.\n";
	}
	load_chat(10,chats);
/*
	shoes = clone_object("players/tuppence/personal/shoes.c");
	move_object(shoes,this_object());
	init_command("wear shoes");
*/
    }
}
