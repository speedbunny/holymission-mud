#include "/players/qclxxiv/island/muncher.h"
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("green stem-muncher");
   	set_short("A green stem-muncher");
   	set_long("A green stem-muncher.\n");
	set_race("muncher");
	set_alias("stem-muncher");
}
