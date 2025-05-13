#include "/players/qclxxiv/mymonster.h"
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("grub");
	set_alias("gnat's grub");
	set_race("skum");
	set_level(1);
   	set_wc(5);
	set_ac(0);
   	set_hp(52);
	set_sp(10);
	set_al(0);
   	set_aggressive(0);
   	set_short("A gnat's grub");
   	set_long("A gnat's grub, that will soon grow into a nasty gnat.\n");
	set_size(1);
    add_money(random(5)+1);
}

