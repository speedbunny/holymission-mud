inherit "/obj/treasure";
void reset(int arg) {
  ::reset(arg);
  if(!arg) {
     set_name("emerald");
     set_alias("stone");
     set_short("An emerald");
    set_long("A large, valuable-looking emerald.\n");
     set_value(280);
     set_weight(1);
   }
}
