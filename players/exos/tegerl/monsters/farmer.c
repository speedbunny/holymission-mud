

/* Tegerl, 10.3.1995 */
/* monsters/farmer */


inherit "obj/monster";
reset(arg) 
{
    ::reset(arg);

    if (arg) return;

    set_name("farmer");
    set_alt_name("man");
    set_race("human");
    set_short("Farmer");
    set_long("A farmer.\n"
      + "He seems to be very anxious.\n"
      + "He left his farm because the monster destroyed the fields.\n"
      + "He wants to start a new life in town.\n");  
    /* Exos 4-26-97
    set_level(10);
    Level Change */
    set_level(5);
    set_gender(1);
    set_al(40);
}
