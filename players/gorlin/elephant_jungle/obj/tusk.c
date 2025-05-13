/* Gorlin, 15.10.1996 */

inherit "obj/thing";

void reset (int arg) {
   ::reset (arg);
   if (arg) return;

   set_name("ivory tusk");
   set_alt_name("tusk");
   set_short("ivory tusk");
   set_long("An elephant tusk made of ivory (what else ?).\n");
   set_weight(2);
   set_value(random(200)+600);
   return;
}
