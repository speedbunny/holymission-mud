#include "std.h"

int stat;
status angry;
object spirit;
object intruder;
object doomsgiver;

reset(arg) {
    if (!arg)
	set_light(1);
    if (!spirit) {
        create_spirit();
	stat=1;
    }
}

init() {
    add_action("west", "west");
    if (any_here())
	set_heart_beat(1);
}

west() {
    this_player()->move_player("west", "players/topaz/angmar/corridor");
    return 1;
}

short() {
    return "Empty room";
}

long() {
    write("You are in a totally empty room. You feel the presence of\n"
        + "a magic force here...\n");
    write("    The only obvious exit is west\n");
}

any_here() {
    object ob;
    ob = first_inventory(this_object());
    while(ob) {
	if (ob != this_object() && living(ob) && !ob->query_npc()) {
	    intruder = ob;
	    return 1;
	}
	ob = next_inventory(ob);
    }
    intruder = 0;
    return 0;
}

heart_beat() {
    string str1, str2, str3, str4, str5;

    if (!spirit) {
	stat=20; return; }
    if (spirit && spirit->query_attack(0))
	angry=1;

    if (!any_here()) {
        set_heart_beat(0);
        if ( !angry && (stat>=12) && (stat<17) ) {
	    if (doomsgiver)
		destruct(doomsgiver);
	    destruct(spirit);
	    create_spirit();
	    stat=1;
	    return;
	}
        if (stat<12) {
	    stat = 1;
	    return; }
        stat = 12;
	return;
    }

    if (stat>=17)
	return;


    str1 = "You get an uneasy feeling...\n";
    str2 = "Something is very wrong in here. Your brain is screaming\n"+
	   "to you to get out of here immediately!\n";
    str3 = "A shimmering light slowly appears in front of you.\n";
    str4 = "A half transparent luminous spirit hovers in the air.\n";
    str5 = "The spirit begins to wail in a hair-raising voice.\n";

    stat++;
#define write(s) /* amylaar */
    if (stat==4)	{ say(str1); write(str1); }
    if (stat==7)	{ say(str2); write(str2); }
    if (stat==10)	{ say(str3); write(str3); }
    if (stat==12)	{ move_object(spirit, this_object());
			  say(str4); write(str4);
			}
    if (stat==14)	{ say(str5); write(str5); }
    if (stat==17)	{ spirit->attacked_by(intruder); }
}


create_spirit() {

    angry=0;

    spirit=clone_object("obj/monster");
    spirit->set_race("demon");
    spirit->set_name("spirit");
    spirit->set_level(15);
    spirit->set_hp(200);
    spirit->set_ac(8);
    spirit->set_al(-400);
    spirit->set_short("An evil powerful spirit");
    spirit->set_long("Get out of here! It will kill you!\n");
    spirit->set_aggressive(0);
    spirit->set_spell_mess1("The spirit conjures a fire elemental");
    spirit->set_spell_mess2("The spirit throws a fire elemental at you.");
    spirit->set_chance(20);
    spirit->set_spell_dam(30);

    doomsgiver = clone_object("players/topaz/angmar/doomsgiver");
    move_object(doomsgiver, spirit);
    command("wield doomsgiver",spirit);
}

