/* 240393 Ethereal Cashimor: non_metal */

inherit "obj/weapon";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("sharp tusk");
 set_alias("tusk");
 set_short("sharp tusk");
 set_long("this is a very sharp wild boars tusk. It is about 2 feet long\n");
 set_class(10);
 set_weight(2);
 set_value(100);
}

query_non_metal() {
  return 1;
}
