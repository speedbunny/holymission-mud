inherit "obj/monster";
reset(arg) {
	::reset(arg);
	if (arg) return;
set_name("chojin");
set_level(35);
set_ep(10000);
	set_gender(1);
set_race("human");
set_short("The dragon.");
set_long("Chojin is an older man who looks very nimble, his followers call him\n"
	"the dragon.\n");
add_money(1500);
}
