id(str) { return str=="lock" || str=="hair"; }
short() { return "A lock of hair"; }
long() { 
 write("A small piece of a black lock of hair. You feel magical vibes.\n"
   + "A small ribbon tied around the lock reads: just issue the formula:\n"
+ "'whom'  to see by whom the place you're in or at was created, or \n"
+ "'whom something'  to see by whom some thing, monster, etc. was made.\n" );
 return 1;
}
init() { add_action("whom","whom"); }
get() { return 1; }
/*
   drop() { return 1; }
*/
query_weight() { return 0; }
query_value() { return 250; }
 
whom(str) /* snarfed from padrone's wand and hacked down to the bone */
{
    string what, the_creator;
    object the_thing;
    if (environment(this_object()) != this_player())
		return 0;
    if (!str) {
		the_creator = creator(environment(this_player()));
		if (the_creator)
	    	write("It must have been built by "+capitalize(the_creator)+".\n");
		else write("You get the impression that this place is very old.\n");
		return 1;
    }
    if ( !sscanf(str, "%s", what) )
		return 0;
    the_thing = present(what, this_player());
    if (!the_thing)
		the_thing = present(what, environment(this_player()));
    if (!the_thing) {
		write("There is no " + what + " here.\n");
		return 1;
    }
    the_creator = creator(the_thing);
    if (the_creator)
		write("You guess " + capitalize(the_creator) + " made " + what + ".\n");
    else write("You can't pick up the right vibes this time.\n");
    return 1;
} /* whom */
