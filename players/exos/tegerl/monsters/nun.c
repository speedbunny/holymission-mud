

/* Tegerl, 6.3.1995 */
/* monsters/gris */


inherit "obj/monster";
reset(arg) 
{
    ::reset(arg);

    if (arg) return;

    set_name("nun");
    set_alt_name("nun");
    set_race("human");
    set_short("Nun");
    set_long("Nun.\n"
      + "She is very young.\n"
      + "Her duty is to serve the princess.\n");  
    /* Exos 4-26-97
    set_level(15);
    Level Change */
    set_level(5);
    set_n_wc(10);
    set_n_ac(5);
    set_gender(2);
    set_al(120);
    return 1;
}
