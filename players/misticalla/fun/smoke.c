/* Cigarette - Gambit, parody of Cigar */
#define DEFSORT "Tobacco"
#include "/players/gambit/defs2.h"
#define DEFVALUE 25 
#define DEFSTRENGTH 0 
#define DEFMAXDRAWS 15
#define PLAYERNAME this_player()->query_name()
string SORT;
int VALUE;
int SORT;
int STRENGTH;
int MAXDRAWS;
int lighted;

int draws;
string SORTKEY;
id(str) { return str=="cigarette" || str == "tobacco cigarette"
    || str == SORT || str==SORTKEY; }
short() { if (lighted) return "A cigarette (Burning)";
    return "A cigarette"; }
long()  { 
    write("This cigarette tastes smooth and refreshing.\n");
    if (lighted) 
	write("It is burning and smoke drifts from the burning end.\n");
    else write("The cigarette, shaped "+SORT+", invites you for a drag.\n");
}
get()	{ return 1; }
query_weight() { return 1; }
query_value() { return draws*VALUE/MAXDRAWS; }

set_sort(arg) { SORT = arg; }
set_sortkey(arg) { SORTKEY = arg; }
set_value(arg) { VALUE = arg; }
set_strength(arg) { STRENGTH = arg; }
set_draws(arg) { MAXDRAWS = arg; }
set_maxdraws(arg) { MAXDRAWS = arg; }

reset(arg) {
    if (arg) return;
    MAXDRAWS = DEFMAXDRAWS;
    VALUE = DEFVALUE;
    STRENGTH = DEFSTRENGTH;
    SORT = DEFSORT;
    SORTKEY = "cigarette_tob";
    draws=MAXDRAWS;
    return 1;
}

init()  { 
    add_action("smoke_cigarette", "smoke");
    add_action("light", "light" );
}

light(str) {
    if ((!str) || (!id(str))) { return 0; }
    if (lighted) {
	write("But it is already lighted.\n");
	return 1;
    }
    if (!present("lighted_torch",this_player())&&
      (!environment(this_player())->query_property("has_fire"))) {
	write("You have nothing to light it with!\n");
	return 1;
    }
    if(environment(this_player())->query_property("has_fire")) {
	environment(this_player())->light_text("cigarette");
    }
    else {
	write("You light up a cigarette.\n");
	say(PLAYERNAME + " lights up a cigarette.\n");
    }
    lighted = 1;
    return 1;
}

smoke_cigarette(str) {
    object cloud1, cloud2;
    if ((!str) || (!id(str))) { return 0; }
    if (!lighted) {
	light(str);
	if (!lighted) return 1;
    }
    write("You take a drag on the cigarette.\n");
    say(PLAYERNAME + " takes a drag on a cigarette.\n");
    write("You taste the smooth tobacco.\n");
    cloud1 = clone_object("players/gambit/obj/cig_smoke");
    move_object(cloud1,environment(this_player()));
    if (random(10)>4) {
	cloud2 = clone_object("/players/gambit/obj/cig_smoke");
	move_object(cloud2,environment(this_player()));
	write("You blow out a small cloud of smoke.\n");
	say(PLAYERNAME + " blows out a small cloud of smoke.\n");
    }
    else {
	write("You blow out a small cloud of smoke.\n");
	say(PLAYERNAME + " blows out a small cloud of smoke.\n");
    }
    if (--draws<=0) {
	write("You finished the cigarette, just the butt left.\n");
	say(PLAYERNAME + " finished the cigarette.\n");
	destruct(this_object());
    }
    return 1;
}

