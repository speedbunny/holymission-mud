/* 930130 mud@mud.edvz.uni-linz.ac.at Herp aka Herbert Rosmanith */

/*-----------------*
 * Poisoned flasks *
 *-----------------*/

#define TP	this_player()
#define TPN	this_player()->query_name()

string color;

inherit "obj/soft_drink";

id(str) {			/* We support colored poison */
string s1,s2;

 if (sscanf(str,"%s %s",s1,s2)==2 && s1==color && ::id(s2)) return 1;
 return ::id(str);
}

drink(str) {			/* We have to redefine that */
  if (!str || !id(str)) return;
  full=0;
  food=0;
  TP->add_poison(strength);
  write("Oops, that didn't taste fine.\n");
  if (drinking_mess)
	say(TPN+drinking_mess);
  else
	say(TPN+" drinks "+short_desc+".\n");
  call_out("dest_bottle",600);
  return 1;
}

query_poison() { return 1; }

set_empty() { full=0; food=0; }

set_color(str) { color=str; }

/* There really is no nead for query_color. We may add it if needed */
