inherit "obj/weapon";
#include "/players/turbo/defs.h"
void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Minbari Fighting Pike");
    set_alt_name("pike");
    set_class(15);
    set_type(28);
    set_weight(2);
    set_light(1);
    set_hit_func(TO);
    set_short("A Minbari fighting pike");
    set_long(
      "Light and luminous, this pike feels like a formidable "+
      "weapon in the hands of the right person.  "+
      "One must be both cunning and charming.  One must "+
      "walk within the light, and not hide behind a mask.\n");
    set_two_handed();
}
weapon_hit(attacker) {
    int i, dam;
    string tome, tothem;
    i=random(3);
    switch(i) {
    case 0:
	tome="The pike seems to guide your hands for an extra hit!";
	dam=50; break;
    case 1:
	tome="The pike seems almost alive, guiding your hands for a triple hit!";
	dam=70; break;
    case 2:
	tome="Your pike vibrates slightly as you hit REALLY hard!!";
	dam=100; break;
	return 0; break;
    }
    write(tome+"\n");
    if (TPWIZ) write("Wiz info: "+dam+" extra damage.\n");
    return dam;
}
wield(arg) {
    if(!id(arg)) return 0;
    if ((this_player() -> query_guild() == 8) || (this_player()->query_alignment() <= 200)) {
	write("Either your too evil, or your a ninja, because you cannot wield this weapon!\n");
	return 1;
    }
    if(::wield(arg)) {
	write("The pike feels very strong.\n");
	return 1;
    }
}
