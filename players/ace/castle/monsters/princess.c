inherit "obj/monster.c";

reset(arg)
{
  ::reset(arg);
  set_level(20);
   set_aggressive(0);
   set_ac(12);
   set_al(800);
   set_name("Princess Riana, of the Hill People");
   set_alt_name("princess");
   set_race("human");
   set_wc(20);
   set_short("Princess Riana of the Hill People");
   set_long("Princess Riana is betrothed to Ace, and she is heir to the throne\n" +
	    "of the Hill People.  She is very attractive, and very dangerous.\n");
}
