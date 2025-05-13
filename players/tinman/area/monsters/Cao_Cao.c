inherit "/obj/monster";
void reset( int tick )
{
    //Cao Cao: Tinman 10-5-95

    ::reset(tick);
    if(tick) return;

	set_name("Cao Cao");
	set_alias("cao");
    set_short("Cao Cao");
    set_long("Cao Cao is an adopted son of an euench.  He is a middle-age man with awe-inspiring features.  He is power-hungry and ruthless.  He is said to be wise enough to rule China but also ruthless enough to destroy it.\n");
    set_gender(1);
    set_race("human");
    set_number_of_arms(2);
    set_size(2);
    set_level(45);
    set_al(-500);
    set_aggressive(0);
   /*
	clone_item("damulet",1,0,0,0);
	clone_weapon("swordt",1,0,0,0);
	clone_weapon("lsword",1,0,0,0);
	clone_armour("ghelmet",1,0,0,0);
	clone_armour("gparmor",1,0,0,0);
	clone_armour("gshield",1,0,0,0);
	clone_armour("gauntlet",2,0,0,0);
	clone_armour("boot",1,0,0,0);
	clone_armour("pant",1,0,0,0);
	command("wear all");
    */
}
init() {
    ::init();
    add_action("do_give", "give");
    call_out ("aa",5);
}
void aa() {
    if (!present (this_player())) return;
    write ("Cao Cao looks at you carefully.\n");
    call_out ("ab",5);
    return;
}
void ab() {
    if (!present (this_player())) return;
    write ("Cao Cao says: You'll have to do...Find me the Ruler Seal and I'll give you riches beyond your belief.\n");
    call_out ("ac",4);
    return;
}
void ac() {
    if (!present (this_player())) return;
    write ("Cao Cao says: I'll reward you with the rule of one of my provinces. Liu Bei can't offer you as much...\n");
    call_out ("ad",3);
    return;
}
void ad() {
    if (!present (this_player())) return;
    write ("Cao Cao gives a loud laugh..\n"+
      "Cao Cao says: He can't even win this war.\n");
    return;
}

int do_give(string str){
    string what, whom;
    if(!str)
	return 0;
    if(!sscanf(str, "%s to %s", what, whom)){
	write("Give what to whom?\n");
	return 1;
    }
    if(!present(what, this_player())){
	write("Cao Cao says: You do not have that to give to me.\n");
	return 1;
    }
    if(!id(whom))
	return 0;
    if(present(what, this_player())->query_name() == "ruler seal"){
	destruct(present(what, this_player()));
	write("You have brought it, now I will kill you!\n");
	say("Cao Cao attacks "+this_player()->query_name()+".\n");
	this_player()->attacked_by(this_object());
	this_player()->attack_object(this_object());
	return 1;
    }
}
