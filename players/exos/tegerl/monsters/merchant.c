/* Tegerl, 24.3.1995 */
/* monsters/merchant */


inherit "obj/monster";
reset(arg) 
{
    ::reset(arg);

    if (arg) return;

    set_name("merchant");
    set_alt_name("man");
    set_race("human");
    set_short("Merchant");
    set_long("Merchant.\n"
      + "He is a very greedy merchant.\n"
      + "He earns a lot of money while the beast is alive.\n"
      + "He can sell his merchandise very expensive.\n");  
    /* Exos 4-26-97
    set_level(20);
    Level Change */
    set_level(10);
    set_n_wc(15);
    set_n_ac(7);
    set_gender(1);
    set_al(100);
    load_chat(20,
      ({"The merchant says: Don't kill the beast, it is much to dangerous.\n",
	"The merchant says: The monster is good for the town.\n"
      }));
    return 1;
}
