/* Completed 05.05.1995 */

inherit "/obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("man");
    set_alt_name("aaa-programmer");
    set_short("A harmless-looking man");
    set_long("This is a middle-aged, rather average-looking man.\n"+
             "His clothes are worn and dirty, but he does not seem to "+
             "care; obviously, he is\ninterested only in the magic box "+
             "and the square things.\n"+
             "If you know what they are, you sure don't attack him...\n"+
             "If you don't, then here's a warning:\nTHERE WILL BE NO CHANCE "+
             "FOR YOU TO HIT TWICE!!!\n");
    set_gender(1);   
    load_chat(40,({"Man says something nasty on a thing called Microhard.\n",
               "Man says something nasty on a thing called Macrosoft.\n",
               "Man wishes somebody called Joe Portals to the hell.\n",
               "Man curses a 'machine' or what.\n",
               "Something arrives in the air! Man takes it, saying:\n"+
               "'****, another thing to work on.'\n"}));
    set_al(0);
    set_level(100000);  /* LETHAL opponent */
    set_chance(100);
    set_spell_dam(5000);  /* i mean, lethal */
    set_spell_mess1("The man quickly hits some cubes with his fingers.\n"+     
                  "You can feel the power of the gods - used against you!\n");
    set_spell_mess2("The man quickly hits some cubes with his fingers.\n"+     
                  "You can feel the power of the gods - used against you!\n");
    set_race("human");
    set_str(10);
    set_dex(10);
    set_wis(10);
    set_int(10);
    set_chr(10);
    set_ac(10);
    set_wc(10);
    set_hp(1000);
    add_money(30000);
    set_ep(200000);
}     
