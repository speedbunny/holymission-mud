inherit "obj/monster.c";
void reset( int tick ){
//Little Wai Kit:tinman 10-5-95

	::reset(tick);
	if(tick) return;

	set_name("Wai Kit");
	set_alias("kit");
	set_alt_name("wai");
	set_short("Wai Kit");
set_long("A mischieveous little chinese boy that can't stand the isolation and the quiet, boring life of hidding in this village. He often goes into the battlefield of Tian-chui to wander and collect spoils when there is no war. He might know something about the field.\n");
set_gender(1);
set_race("human");
set_number_of_arms(2);
set_size(1);
set_level(5);
set_al(500);
set_aggressive(0);
command("wear all");
}
init() {
call_out ("aa",2);
}
void aa() {
if (!present (this_player())) return;
write ("Little Wai Kit say: I saw men disappear into a tree one night.\n");
call_out ("ab",3);
return;
}
void ab() {
if (!present (this_player())) return;
write ("Little Wai Kit say: They were wearing green armours.\n");
call_out("ac",4);
return;
}
void ac() {
if (!present (this_player())) return;
write ("Little Wai Kit say: I ran when they saw me. I was scared.\n"+
"Little Wai Kit gave a small shiver...\n");
return;
}
