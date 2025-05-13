/* Axlrose - Guns N' Roses Shirts */
inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("shirt");
    set_alias ("t-shirt");
    set_type("armour");
    set_ac(3);
    set_short("Guns N' Roses t-shirt");
    set_long
      ("A black G N'R shirt with 'Guns N' Roses' written in yellow across the \n"
      +"front.  A skull has two firing guns from the eye sockets while being \n"
      +"pierced with two arrows, a rose, scalpel, and spike.  The back has \n"
      +"'Appetite For Destruction' written in red.\n");
    set_value(1500);
    set_weight(1);
}
