inherit "obj/food";

void reset(int arg)
  {if(!arg)
    {set_name("fungus");
    set_short("A strange fungus");
    set_long("It looks edible, although rather disgusting.\n");
    set_eater_mess("Yuck!  It tastes like shit!\n");
    set_eating_mess(" eats some fungus.\n");
    set_strength(75);
    set_value(500);
    set_weight(1);}}
