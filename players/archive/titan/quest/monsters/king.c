	inherit "obj/monster";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("king Vladimir");
	set_alt_name("king");
	set_alias("vladimir");
	set_race("human");
	set_gender(1);
	set_level(30);
	set_al(2000);
	set_short("King Vladimir");
	set_long("Kral Hoganu.\n");
	add_money(50000);
	set_spell_mess2("King prays to your god and then you feel hard hit");
	set_spell_mess1("");
	set_chance(20);
	set_spell_dam(45);
}
	catch_tell(arg) {
	string str1;
 
	if(sscanf(arg,"%s arrives.",str1)==1) {
	call_out("welcome",3);
	return 1;
}}
	
	welcome() {
	if(present("princess Claudia",environment(this_object()))) {
	write("King stands up from throne and bows before you.\n");
	this_player()->set_quest("find_princess_quest");
	call_out("happy",2);
	return 1;
}
	else {
	write("King looks sadly at you.\n");
	call_out("sadly",2);
	return 1;
}}
   	sadly() {
	write("King says sadly: help me stranger.\n");
	call_out("sadly1",3);
}
	sadly1() {
	write("King says: find my daughter princess Claudia.\n");
	call_out("sadly2",3);
}
	sadly2() {
	write("King tears into the burst.\n");
	return;
}
	attack() {
	object utocnik;
	utocnik=this_player()->query_attack();

  	if(::attack()) {
       	if(!present("kill_thing",utocnik)) {
	move_object(clone_object("players/titan/quest/items/kill_thing"),utocnik);
	return 1;
}}}
	happy() {
	write("King say: thank you stranger.\n");
	shout("King of Hogan is happy again.\n");
	call_out("happy1",3);
}
	happy1() {
	object princezna;
	write("King cuddles princess.\n");
	princezna=present("princess",environment(this_object()));
	destruct(princezna);
	call_out("happy2",1);
}
	happ2() {
	write("Princess leaves to the private part of castle.\n");
	write("King smiles happyly at you.\n");
}                   
