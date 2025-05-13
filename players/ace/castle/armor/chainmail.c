inherit "obj/armour.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_ac(3);
   set_alias("chainmail");
   set_name("Chainmail");
   set_short("Chainmail");
   set_long("Chainmail armor worn by a guard of Ace's Castle.\n" +
            "It isn't all that impressive.\n");
   set_type("armor");
    set_value(400);
    set_weight(3);
}
