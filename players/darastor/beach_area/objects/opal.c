inherit "/obj/treasure";
void reset(int arg) {
  ::reset(arg);
  if(!arg) {
     set_name("opal");
     set_alias("stone");
     set_short("An opal");
     set_long("A large opal. It must be quite valuable.\n");
     set_value(250);
     set_weight(1);
   }
}
