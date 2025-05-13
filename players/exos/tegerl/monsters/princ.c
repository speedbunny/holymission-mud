

/* Tegerl, 22.3.1995 */
/* monsters/princ */
/* Exos 4-26-97, give one "pants" per reset in case this is a quest */

inherit "obj/monster";

int pants;

void reset(int arg) 
{
    ::reset(arg);

    pants=0;

    if (!arg){

	set_name("princess");
	set_alt_name("girl");
	set_race("human");
	set_short("Princess");
	set_long("Princess.\n"
	  + "She is very young and beautiful.\n"
	  + "She is the king's daughter.\n"
	  + "(eh, kiss her *smile*)\n");  
	/* Exos 4-26-97
	set_level(20);
	Levl change */
	set_level(5);
	set_n_wc(15);
	set_n_ac(7);
	set_gender(2);
	set_al(200);
    }
}

void init() {
    ::init();
    add_action("kiss","kiss");
}

int kiss(string str) {
    if (!(str=="princess" || str=="girl")) return 0;
    write("You kiss the princess deep and passionate.\n");
    write("The princess closes here eyes and enjoys that kiss.\n");
    say (this_player()->query_name()+" kisses the princess deep and passionate.\n");
    if (!pants) {
	write("She tells you: can you do me a favor and bring this to my father ?\n");
	write("The princess gives you pants.\n");
	transfer(clone_object("/players/tegerl/jabberwocky/obj/pants"),this_player());
	pants=1;
	return 1;
    }
    return 1;
}
