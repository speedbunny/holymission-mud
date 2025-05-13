
inherit "/obj/armour";

void reset(int arg)
{
   ::reset(arg);

   if (arg) return;

   set_name("warbag");
   set_alias("gnomish warbag");
   set_short("a gnomish warbag");
   set_long(
       "You see a small bag, made of tough leather. It has \n"+
       "3 big holes made to put your head and your arms through \n"+
       "it to wear it as armour.\n");
   set_type("armour");
   set_ac(3);
   set_weight(2);
   set_value(100);
   set_size(3);
}



