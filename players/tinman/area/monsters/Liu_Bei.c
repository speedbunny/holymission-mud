#include "/players/tinman/defs.h"
inherit "obj/monster";
void reset( int tick )
{
    //Liu Bei:Tinman 10-2-95

    ::reset(tick);
    if(tick) return;

	set_name("Liu Bei");
	set_alias("liu");
	set_alt_name("bei");
    set_short("Liu Bei");
    set_long("A middle-age moustached man with a majestic aura around him.  You can feel him radiating with rightessness and integerity.  He is a desendent of one of the royal family of Hans China and is fighting to ascend the throne with his blood-sworn brothers Guan Yu and Zhang Fei.\n");
    set_gender(1);
    set_race("human");
    set_number_of_arms(2);
    add_property("humanoid");
    set_size(2);
    set_level(35);
    set_al(550);
    set_aggressive(0);
move_object(clone_object("/players/tinman/area/weapons/lsword"),this_object());
	command("wear all");
}

int object_died(object mob) {
object ob;

if (!this_player()->query_immortal()) {
	write("Suddenly a sword appears in Liu Bei's corpse.\n");
    }
    return 0;
}
init() {
    ::init();
    add_action("do_give", "give");
    call_out ("aa",4);
}
void aa() {
    if (!present (this_player())) return;
    write ("Liu Bei looks like you from behind the table.\n");
    call_out ("ab",4);
    return;
}
void ab() {
    if (!present (this_player())) return;
    write ("Liu Bei says: I don't have much to offer you....\n");
    call_out ("ac",3);
    return;
}
void ac() {
    if (!present (this_player())) return;
    write ("but if you find me the Ruler Seal you'll save my people....\n");
    call_out ("ad",4);
    return;
}
void ad() {
    if (!present (this_player())) return;
    write ("Liu Bei says: You'll save the Han Dynasty...\n");
    call_out ("ae",3);
    return;
}
void ae() {
    if (!present (this_player())) return;
    write ("Liu Bei sighs with resignation.\n");
    return;
}

int do_give(string str){
    string what, whom;
    if(!str)
	return 0;
    if(!sscanf(str, "%s to %s", what, whom))
	return 0;
    if(!present(what, this_player())){
	write("Liu Bei says: You do not have that object.\n");
	return 1;
    }
    if(!id(whom))
	return 0;
    if(present(what, this_player())->query_name() == "ruler seal"){
	write("Liu Bei says: You have brought it!\n");
	say("Liu Bei accepts the Ruler Seal.\n");
	destruct(present(what, this_player()));
	// Jack, set the quest for player here
	return 1;
    }
}
