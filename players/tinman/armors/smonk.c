inherit "sys/mob.c";
void reset( int tick ){
//blue archer: Liu Bei's archer: Tinman 9-28-95

	::reset(tick);
	if(tick) return;

set_name( ({"monk","statue","warrior"}) );
set_short("silver monk statue");
set_long("This is a silver monk statue that guards Tinman's workroom. He comes alive to defend the room.\n");
set_gender(1);
set_look_info("A silver monk statue frozen in a stance of the Guan-shia manual.");
set_race("golem");
set_dodge(100);
set_parry(100);
set_number_of_arms(2);
set_size(2);
set_level(50);
set_al(100);
set_str(20);
set_dex(20);
set_wis(20);
set_int(20);
set_con(23);
set_chr(20);
set_class(3);
set_natural_damage(1,1,0);
set_natural_absorbage( 100 );
change_skill("club", 100, 100);
change_skill("parry", 100, 100);
clone_weapon("/players/tinman/weapons/arms",2,0,0,0);
command("wear all");
	switch( random(200)/100){
	case 0: set_aggressive(0); break;
	case 1: set_aggressive("all"); break;
}
}
