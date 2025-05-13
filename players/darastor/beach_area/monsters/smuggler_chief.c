/* I want this guy wielding a cutlass in one hand and a long knife in the
other - Jez 270797 - use clone_list in room */

inherit "/obj/monster";

void reset (int arg)
{
    ::reset(arg);
    if(!arg)
    {
        set_name("smuggler chief");
        set_alias("smuggler");
        set_alt_name("chief");
        set_short("The chief of the smugglers' band.");
        set_long("The smugglers' chief is a very big, swarthy-looking guy."
        +  " You think you'd have to be pretty tough to take him on.\n");
        set_race("human");
        set_gender(1);
        set_smell("Horrible. You wonder when he last took a bath.");
        set_random_pick(1);
        
        set_level(15);
        set_n_wc(2); // Used to street-fighting 
        set_str(17);
        set_dex(18);
        set_con(15);
        
        set_number_of_arms(2);
        
        set_whimpy(10);
        set_al(-100);
        add_money(150 + random(50));
    }
}
