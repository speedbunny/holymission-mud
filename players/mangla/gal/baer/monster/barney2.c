inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) return ;
    set_name("barney, the purple dinosaur");
    set_alias("dinosaur");
    set_alt_name("barney");
    set_race("dinosaur");
    set_hp(300);
    set_level( 5 + random(2) );
    short_desc = ("Barney, the purple Dinosaur");
    long_desc = ("This is Barney, the loveable and very cute singing purple dinosaur.\n");
    set_wc(10);
    set_ac(15);
    add_money(250);
    load_chat(12,({
	("Barney says: I love you, you love me...\n"),
	("Barney says: Let's sing a song together...\n"),
	("Barney says: Will you be my friend... ?\n"),
	("Barney hugs you and smiles with joy...\n"),
      }));
    load_a_chat (12, ({
	("Barney shouts: This sucks...\n"),
	("Barney cries: Leave me alone you fucken brat...\n"),
	("Barney cries: Leave my tail alone, you stupid kid...\n"),
	("Barney screams: Help, Help...leave me alone !!\n"),
	("Barney munches on a kid and powers up...\n"),
      }));
}


