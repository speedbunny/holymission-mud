inherit "obj/monster";
object money;
string chats;
reset(arg) {
    ::reset(arg);
    if(!arg){
	set_name("guard");
	set_race("orc");
	set_short("Evil guard");
	set_long("This evil guard is torturing these poor prisoners, maybe you should\n"+
	  "teach him a lesson.\n");
	set_alias("guard");
	set_level(19);
	set_al(-780);
	set_ac(9);
	set_wc(20);
money = clone_object("obj/money.c");
money->set_money(1000);
transfer(money,this_object());

	if(!chats){
	    chats=allocate(5);
	    chats[0]="Evil guard says: You will tell me where they are!\n";
	    chats[1]="Evil guard whips the prisoner.\n";
	    chats[2]="Evil guard cackles with evil glee!\n";
	    chats[3]="You can hear the crack of the whip.\n";
	    chats[4]= "Evil guard punches the prisoner.\n";
	}
	load_chat(5,chats);
    }
}
