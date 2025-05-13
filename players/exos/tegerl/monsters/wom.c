

/* Tegerl, 14.3.1995 */
/* monsters/wom */


inherit "obj/monster";
reset(arg) 
{
    ::reset(arg);

    if (arg) return;


    set_name("keeper's wife");
    set_alt_name("wife");
    set_race("human");
    set_short("keeper's wife");
    set_long("She is the keeper's wife.\n"
      + "She is a very beautiful woman.\n"
      + "You hardly can control your emotions.\n");  
    /* Exos 4-26-97
    set_level(30);
    level 30 is much much too high */
    set_level(5);
    set_n_wc(99);
    set_n_ac(99);
    set_gender(2);
    set_al(120);
    load_chat(15,(({
	  "The woman says: Let's go in my bedroom.\n"
	  "The woman says: We will have a lot of fun.\n"
	  "She smiles at you.\n"
	  "She says: But take care, if my man should see us,\n"
	  "She says: I am sure, that he will kill us !!!\n"
	  "She whispers to you: He has been known to kill people\n"
	  "She whispers to you: in the past, but don't you worry.\n"})));
    return 1;
}
