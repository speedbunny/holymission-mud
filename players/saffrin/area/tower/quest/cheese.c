/* Coded by Llort */
/* Spruced up by Saffrin */

inherit "obj/poison";

reset(arg) {
    if (arg) return;

    set_name("cheese");

    set_short("a piece cheese");

    set_long("A piece of cheese that has several holes in it.  An odd\n"+
      "odor is coming from it.\n");

    set_eater_mess("H U R L ! ! ! You puke all over yourself.\n");

    set_eating_mess(" eats a piece of cheese and pukes all over themselves.\n");

    set_weight(1);

    set_value(1);

    set_strength(8);
}
