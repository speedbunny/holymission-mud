/* Cigar - Qclxxiv, parody on Spliff
*/
#define DEFSORT "havanna"
#define DEFVALUE 25 
#define DEFSTRENGTH 0 
/* strength not used in this parody:-) */
#define DEFMAXDRAWS 7
#define PLAYERNAME this_player()->query_name()
string SORT;
int VALUE;
int STRENGTH;
int MAXDRAWS;
int lighted;

int draws;
string SORTKEY;
id(str) { return str == "cigar" || str == "havanna cigar" 
				|| str == SORT || str==SORTKEY; }
short() { if (lighted) return "A cigar(burning)"; 
		return "A cigar ("+SORT+")"; }
long()  { 
	write("This cigar seems to be filled with very good tobacco.\n");
	if (lighted) 
		write("It is burning and spreads heavy clouds.\n"); 
	else write("The cigar, shaped: "+SORT+", invites you to smoke it.\n");
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
	SORTKEY = "cigar_hav";
	draws=MAXDRAWS;
	return 1;
}

init()  { 
    add_action("smoke_cigar", "smoke" );
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
     environment(this_player())->light_text("cigar");
  }
  else {
	write("You light up the cigar.\n");
	say(PLAYERNAME + " lights up a cigar.\n");
  }
  lighted = 1;
  return 1;
}

smoke_cigar(str) {
	object cloud1, cloud2;
	if ((!str) || (!id(str))) { return 0; }
	if (!lighted) {
		light(str);
		if (!lighted) return 1;
	}
	write("You take a deep draw from your cigar.\n");
    say(PLAYERNAME + " takes a deep draw from a cigar,\n");
	write("You cough your lungs out.\n");
    say("and coughs "+this_player()->query_possessive()+" lungs out.\n");
	cloud1 = clone_object("/players/qclxxiv/cigarsmoke");
	move_object(cloud1,environment(this_player()));
	if (random(10)>4) {
		cloud2 = clone_object("/players/qclxxiv/cigarsmoke");
		move_object(cloud2,environment(this_player()));
		write("You blow out thick clouds of smoke.\n");
		say(PLAYERNAME + " blows out thick clouds of smoke.\n");
	}
	else {
		write("You blow out a thick cloud of smoke.\n");
		say(PLAYERNAME + " blows out a thick cloud of smoke.\n");
	}
	if (--draws<=0) {
		write("You finished a good cigar, just ashes left.\n");
		say(PLAYERNAME + " finished a good cigar, just ashes left.\n");
		destruct(this_object());
	}
	return 1;
}

