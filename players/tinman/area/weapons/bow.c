inherit "/players/tinman/weapons/autowpn";

reset(arg) {
    ::reset(arg);
    if (!arg) {
	set_name("multi-shot bow");
	set_short("multi-shot bow");
 	set_long("A finely crafted longbow with five arrow slots on it. It's"+
" one of Zhuge Liang's invention allowing an archer to shoot five arrows at"+
" once. There are limited amounts of arrows here.\n");
	set_value(500);
	set_weight(3);
	set_class(6);

	set_max_arrows(500);
	set_arrows(500);
	set_max_salvo(5);
	set_wc_per_arrow(8);
	set_sound("Sssshhhookk");
	set_value_per_arrow(2);
	set_monster_reload(1);
    }

} /* reset */


wield(str) {
    if (!id(str))
	return 0;
    if (environment() != this_player()) {
	/* write("You must get it first!\n"); */
	return 0;
    }
    /*
	if (wielded) {
	    write("You already wield it!\n");
	    return 1;
	}
    */

    /*
	if(wield_func)
	    if(!call_other(wield_func,"wield",this_object())) 
		return 1;
	*/
    if (call_other(this_player(), "query_level", 0) < 10) {
	write("You don't know how to use this bow.\n");
	write("This weapon is obviously too complicated for you.\n");
	say(call_other(this_player(),"query_name",0)+
	  " failed to wield a multi-shot bow\n");
	return 1;
    }
    write("The weight of the bow feels comfortable in your hand.\n");
    wielded_by = this_player();
    // call_other(this_player(), "wield", this_object());
    // wielded = 1;
    ::wield(str);
    return 1;
} /* wield */


id(str)
{

    return    str == "multi-shot bow" || str == "bow";
}
