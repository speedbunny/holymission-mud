inherit "/obj/armour";

reset(arg) {

   ::reset(arg);
   if (!arg) {
     set_name("crown");
     set_short("The crown of the queen of Denmark");
     set_long("This is the royal crown for the queen of the house of Denmark.  There is \n"+
                "a rather large emerald at the center of it.\n");
     set_ac(1);
     set_size(3);
     set_type("helmet");
     set_value(1000);
     set_weight(1);
  }
}
