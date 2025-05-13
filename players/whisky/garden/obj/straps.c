
inherit "/obj/armour";

void reset(int arg)
{
    ::reset(arg);
   if (arg==0)
   {
     set_name("black straps");
     set_alias("straps");
     set_short("black leather straps");
     set_ac(1);
     set_type("boot");
     set_value(200);
     set_long(
     "Sexy black leather straps, build for the witch to animate.\n"+
     "curious adventurers.\n");
     set_weight(1);
   }
}

query_mage_wear()
{
     return 1;
}

query_monk_wear()
{
     return 1;
}

