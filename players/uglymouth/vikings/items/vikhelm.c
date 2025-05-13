/* A vikinghelm */
/* Airborne: Altered so players not of medium size can finish the quest. */
inherit "/obj/armour";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
   set_name("viking helm");
   set_alias("helm");
   set_short("A viking helm");
   set_long("An iron helmet with a big curved horn protruding from each side. \n");
   set_type("helmet");
   set_ac(1);
   set_size(0);
   set_value(30);

   }
}
