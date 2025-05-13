/* A description. Like Adam's faces! */
/* 040794: Nokey: strict_typing this */
#pragma strict_types
#pragma save_types

/* declaration of functions */
string extra_look();
string description;

int id(string str) {
    return str == "appearance";
} /* id */

varargs void long(string str) {
    write(extra_look() + ".\n");
} /* long */

/* Set the description string. */
void set_description(string d) {
    string a, b;
    if (sscanf(d, "%s^!%s", a, b) == 2)
	d = a;	/* If someone makes a description with ^! in it... */
    description = d;
} /* set_description */

/* It is auto-loading, and the description string is always the same. */
string query_auto_load() {
    object env;
    env = environment(this_object());
    if (!living(env) || env->is_npc())
	return 0;
    else
	return "players/padrone/obj/appearance" + ":" + description;
} /* query_auto_load */

/* Set the description string from the auto-load. */
void init_arg(string d) {
    description = d;
} /* init_arg */

/* It cannot be dropped. */
int drop() {
    return 1;
} /* drop */

/* This will be printed when looking at the player! */
string extra_look() {
    object env;
    string pronoun;

    pronoun = (string)environment(this_object())->query_pronoun();
    if (!pronoun)
	return 0;
    else
	return capitalize(pronoun) + " " + description;
} /* extra_look */
