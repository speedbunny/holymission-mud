inherit "obj/monster";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("horiuchi owari");
	set_alias("owari");
	set_alt_name("horiuchi");
	set_short("Dansensei Horiuchi Owari");
	set_long("This is Horiuchi Owari, great great grandson of the founder"+
	" of this school. He is a small man in his 40's. He has straight "+
	"black hair. He wears a black gi, with a black silk sash around his "+
	"waste with writing on it. He also wears a red silk sash tied around "+
	"his left ankle. \n");
	set_level(25);
	set_al(120);
	set_hp(2600);
	set_race("human");
	set_gender(1);
	set_number_of_arms(2);
	set_wc(35);
	set_ac(14);
	GP(4000);
	set_size(2);
	}
