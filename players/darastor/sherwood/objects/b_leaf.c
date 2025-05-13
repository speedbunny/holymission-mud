inherit "/obj/food";

void reset(int arg)
{
    if (!arg)
    {
        set_name("blue leaf");
        set_alias("leaf");
        
        set_short("A blue leaf");
        set_long("A pale blue leaf.\n");
        set_eater_mess("The leaf tastes really sour. You wouldn't want to "+
          "eat many of them.\n");
        set_eating_mess(" eats a blue leaf but appears not to enjoy it.\n");  
        
        set_strength(0);
        set_heal_amount(0);
        set_value(0);
        set_weight(1);
    }
}
