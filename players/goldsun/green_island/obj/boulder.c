inherit "/obj/treasure";
 reset(arg){
  ::reset(arg);
 if (arg) return;
 set_name("boulder");
 set_short("A boulder");
 set_alias("rock");
 set_long("A big boulder. It hurt somebody.\n");
 set_value(1);
 set_weight(12);
 }
