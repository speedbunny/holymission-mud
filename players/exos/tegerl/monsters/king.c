/* Tegerl, 24.3.1995 */
/* monsters/king */


inherit "obj/monster";
void reset(int arg) 
{
    ::reset(arg);

    if (!arg){

	set_name("king");
	set_alt_name("man");
	set_race("human");
	set_short("King");
	set_long("King.\n"
	  + "He is a very old man.\n"
	  + "He is very dirty and wears dirty clothes.\n"
	  + "This man really doesn't look like a king.\n");  
	/* Exos 4-26-97
	set_level(30);
	Level Change */
	set_level(20);
	set_n_wc(15);
	set_n_ac(7);
	set_gender(1);
	set_al(200);
	load_chat(15,
	  ({"The king says: The monster will ruin our town.\n",
	    "He says: By the way, do you know where my pants are ?.\n",
	  }));
    }
}
void init() {
    ::init();
    add_action("give","give");
}

int give(string str) {
    object pants;
    if (!(str=="pants" || str=="pants to king")) return 0;
    pants=present("pants",this_player());
    if(!pants){
	write("The king slaps you, because you don't have his pants.\n");
	return 1; }
    destruct(pants);
    write("The king is very happy that you brought his pants.\n");
    write("The king hugs you.\n");
    write("He says: I am not rich anymore, but you deserve a reward.\n");
    write("He gives you a ring.\n");
    say (this_player()->query_name()+" gives some pants to the king.\n");
    say ("The king gives a ring to "+this_player()->query_name()+".\n");
    transfer(clone_object("/players/tegerl/jabberwocky/obj/ring"),this_player());
    return 1;
}
