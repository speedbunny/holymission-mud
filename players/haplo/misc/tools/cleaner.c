#define FILENAME "players/haplo/misc/cleaner"
id(str) {return str=="vacuum cleaner" || str=="vacuum_cleaner";}
short() {
tell_object(environment(this_object()),capitalize(this_player()->query_real_name())+" just looked at your inventory.\n");
        return "A vacuum cleaner"; }
long() { 
        write("To destruct an object type `cleanup <player> <object> [number in inventory.]\n"); }
get() { return 1; }
drop() { return 1; }
query_auto_load() { return FILENAME + ":"; }

init () {
  if (this_player()->query_immortal() || this_player()->query_testchar())
    add_action ("cleaning", "cleanup");
   add_action("check_list","checklist");
    add_action ("shadow","shadow");
   add_action ("list","makelist");

}
cleaning(str) { return "players/portil/extras/clean.c"->cleanup(str); }
shadow() {
        if(this_player()->query_real_name()!="haplo") return 0;
	return 1;
}

list() {
	"/players/portil/funobj/makelist"->get_list();
	return 1;
}

check_list() {
	"/players/portil/funobj/makelist"->list_so_far();
	return 1;
}
