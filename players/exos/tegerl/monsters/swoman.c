

/* Tegerl, 9.3.1995 */
/* monsters/swoman */


inherit "obj/monster";
reset(arg) 
{
    object chats;
    ::reset(arg);

    if (arg) return;

    set_name("housewife");
    set_alt_name("woman");
    set_race("human");
    set_short("Housewife");
    set_long("A housewife.\n"
      + "She runs around and tries to get food for her family.\n"
      + "Maybe some delicious rats or some rotten potatoes.\n");  
    /* Exos 4-26-97
    set_level(10);
    Lowered level */
    set_level(5);
    set_gender(2);
    set_aggressive(0);
}
