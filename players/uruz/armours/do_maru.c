inherit "/obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return 1;
   set_type("armor");
   set_name("do-maru");
   set_alias("domaru");
   set_ac(3); 
   set_short("A Do-Maru");
   set_long("A corselet of Lamellar armor.  Small tassels protect the legs\n"+
      "and hips.  The corselet itself protects the stomach, chest and back.\n");
   set_value(2250);
   set_weight(20);
   return 1;
}


