inherit "/obj/monster";

reset(arg)  {
    ::reset(arg);
    if (arg) return;
    set_name("Bandit");
    set_alias("bandit");
set_short("A well dressed bandit");
    set_long("A Kilrathi is a Tiger-like race.  They are almost twice \n"+
      "the size of a human.  There warrior like nature, and \n"+
      "sense of loyality to thier hierachy, scares you.\n");

set_level(14);
set_dex(20);
    set_ep (5000000);
    set_al(-2000);
    set_wc(2);
    set_ac(1);
    load_chat(10,
      ({
	"Kilrathi says: You pathetic decendent of monkeys.\n",
	"Kilrathi says: You will die!\n",

      }));




}


