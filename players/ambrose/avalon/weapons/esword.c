inherit "obj/weapon";

reset(arg){
 if(arg)return;

  set_name("sword");
  set_short("Longsword");
  set_long("This longsword looks very sharp indeed.  Its shines with a \n"+
           "inner silver light which dazzles you.\n");
  set_value(2000);
  set_weight(4);
  set_class(20);
 }
