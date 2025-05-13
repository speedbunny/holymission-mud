inherit "obj/armour";
reset(arg) {
    ::reset(arg) ;
    if (arg) return 1;

    set_name("cloak");
    set_type("cloak");
    set_weight(1);
    set_value(200);
    set_ac(0);
    set_short("Realmer's Cloak");
   set_long("The cloak worn by the great adventurers from 'Realms'. \n"
+"Type 'twirl cape' to show your pride! \n");
}
init() {
    ::init() ;
    add_action("twirl","twirl");
}

int twirl(string str_arg) {
    if(str_arg!="cape"){return 0;}
    else {
	if (this_player()->query_gender()==1) {
	    write("You twirl your cape and magic fills the air! \n\n");
  say(this_player()->query_name() + "flips his cape and a magical pattern forms: \n\n"
+"               <<<LORD OF THE REALMS>>>\n");
	    return 1;}
	if (this_player()->query_gender()==2) {
	    write("You twirl your cape and the words LADY OF THE REALMS float above you! \n");
	    say(this_player()->query_name() + " flips her cape and a magical pattern forms: \n\n"
+"          <<<LADY OF THE REALMS>>>\n");
	    return 1;
	}
    }
}

