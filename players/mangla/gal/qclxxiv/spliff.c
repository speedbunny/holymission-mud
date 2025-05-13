/* Spliff - Qclxxiv june 20, 92, and later
*/
#define DEFSORT "lambsbread"
#define DEFVALUE 100 
#define DEFSTRENGTH 49
#define DEFMAXDRAWS 7
#define PLAYERNAME this_player()->query_name()
string SORT;
int VALUE;
int STRENGTH;
int MAXDRAWS;
int lighted;
object soul;

int draws;
string SORTKEY;
id(str) { return str == "spliff" || str == "ital spliff" 
				|| str == SORT || str==SORTKEY
				|| (lighted && str=="lighted_torch"); }
short() { if (lighted) return "an ital spliff (burning)"; 
		return "an ital spliff ("+SORT+")"; }
long()  { 
	write("This ital spliff seems to be filled with very good "+SORT+".\n");
	if (lighted) 
		write("It is burning and spreads a delicious fragrance.\n"); 
	else write("It seems one could even eat this one (what a waste though).\n");
}
get()	{ return 1; }
query_weight() { return 1; }
query_value() { return draws*VALUE/MAXDRAWS; }

set_sort(arg) { SORT = arg; }
set_sortkey(arg) { SORTKEY = arg; }
set_value(arg) { VALUE = arg; }
set_strength(arg) { STRENGTH = arg; }
set_draws(arg) { MAXDRAWS = arg; draws = arg; }
set_maxdraws(arg) { MAXDRAWS = arg; }

reset(arg) {
	if (arg) return;
	MAXDRAWS = DEFMAXDRAWS;
	VALUE = DEFVALUE;
	STRENGTH = DEFSTRENGTH;
	SORT = DEFSORT;
	SORTKEY = "spliff_lb";
	draws=MAXDRAWS;
	return 1;
}

init()  { 
	add_action("eat_spliff", "eat" );
    add_action("smoke_spliff", "smoke" );
    add_action("light", "light" );
}

eat_spliff(str) {
	if ((!str) || (!id(str))) { return 0; }
	if (lighted) {
		write("Can't eat a burning spliff! You burned your lips.\n");
    	say(PLAYERNAME + " tries to eat a burning spliff.\n");
		return 1;
	}
	if (!check_soul(this_player(), MAXDRAWS)) {
		write(
"You can't possibly take anymore, you're as loaded as can be.\n" );
		say(PLAYERNAME+" fails to eat a spliff, being too loaded already.\n");
		return 1;
	}
	write("You enjoy the sweet taste of a good "+SORT+". You feel irie.\n");
    say(PLAYERNAME+" eats a good "+SORT+" and is obviously feeling irie.\n");

	call_other(this_player(),"heal_self",7*STRENGTH/10); /* NOTE: */
			/* spliffs are limited in similar way as food/drink from /obj */
			/* see check_soul statement above, and the file: 
			 *	qcl/obj/ganjasoul.c  for details and tuning.
			*/
	destruct(this_object());
	return 1;
}

light(str) {
	if ((!str) || (!id(str))) { return 0; }
	if (lighted) {
		write("But it is already lighted.\n");
		return 1;
	}
  if (!present("lighted_torch",this_player())&&!this_player()->query_npc()&&
   (!environment(this_player())->query_property("has_fire"))) {
    write("You have nothing to light it with!\n");
    return 1;
  }
  if(environment(this_player())->query_property("has_fire")) {
     environment(this_player())->light_text("spliff");
  }
  else {
	write("You light up the ital spliff.\n");
	say(PLAYERNAME + " lights up an ital spliff.\n");
  }
  lighted = 1;
  return 1;
}

smoke_spliff(str) {
	if ((!str) || (!id(str))) { return 0; }
	if (!lighted) {
		light(str);
		if (!lighted) return 1;
	}
	if (!check_soul(this_player(), 1)) {
		write(
"You can't possibly take anymore, you're as loaded as can be.\n" );
		say(PLAYERNAME+" fails to smoke a spliff, being too loaded already.\n");
		return 1;
	}
	write("You take a deep draw from the ital spliff.\n");
    say(PLAYERNAME + " takes a deep draw from the ital spliff,\n");
	write("You feel irie and start thinking about things and times.\n");
    say("and is obviously feeling irie.\n");
	call_other(this_player(),"heal_self",STRENGTH/MAXDRAWS); /* NOTE: */
			/* spliffs are limited in similar way as food/drink from /obj */
			/* see check_soul statement above, and the file: 
			 *	qcl/obj/ganjasoul.c  for details and tuning.
			 */
	if (--draws<=0) {
		if (this_player()) {
			write("You finished a good spliff, just ashes left.\n");
			say(PLAYERNAME + " finished a good spliff, just ashes left.\n");
		}
		destruct(this_object());
	}
	return 1;
}

check_soul(pl, i) {
	object o;
	if (!soul ||  !soul->player(pl)) {
		/* check whether pl has a soul already */
		if (o=present("qganjasoul",pl)) /* if so set soul to this soul */
			soul = o;
		else { /* if not give a new one */
			o = clone_object("players/qclxxiv/obj/ganjasoul");
			move_object(o,pl);
			soul = o;
		}
		soul->player(pl);
	}
	/* now soul point to pl's soul, check if eating/drawing can be done */
	return (soul->draw(i));
}

