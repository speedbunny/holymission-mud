
test_if_any_here() {
    object ob;
    ob = environment();
    if(!ob)
	return;
    ob = first_inventory(environment());
    while(ob) {
	if(ob != this_object() && living(ob) && !call_other(ob, "query_npc"))
	    return 1;
	ob = next_inventory(ob);
    }
    return 0;
}

