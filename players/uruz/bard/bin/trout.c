do_find(arg){
	object who;
	object env;
	object inv;
	who = find_player(arg);
	env = environment(who);
	if(!arg){
	write("what do you want to find?\n");
	return 1;
	}
	tell_object(this_player(), all_inventory(env));
}
