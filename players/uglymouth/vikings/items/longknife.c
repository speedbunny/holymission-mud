/* Sil's longknife */
inherit "obj/weapon";

void reset(int arg)   {
   ::reset(arg);
   if(!arg)   {

   set_name("longknife");
   set_alias("knife");
   set_short("A longknife");
   set_long("Sil's longknife. Old but sharp. It smells fishy \n");
   set_weight(1);
   set_value(25);
   set_class(7);

   }
}
