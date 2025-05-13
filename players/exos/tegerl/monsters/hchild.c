

/* Tegerl, 9.3.1995 */
/* monsters/hchild */


inherit "obj/monster";
reset(arg) 
{
    object chats;
    ::reset(arg);

    if (arg) return;

    set_name("child");
    set_alt_name("kid");
    set_race("human");
    set_short("Kid");
    set_long("A sweet child.\n"
      + "It knows that its parents love it.\n"
      + "It hopes to have more food once.\n");  
    /* Exos 4-26-97
    set_level(4);
    Level Change */
    set_level(2);
    set_gender(0);
    set_aggressive(0);
}
