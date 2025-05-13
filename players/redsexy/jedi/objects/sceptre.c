inherit "obj/weapon";

reset(arg){
 ::reset(arg);
 if (arg) return;
 set_name("sceptre");
 set_short("Jabba the Hutt's sceptre");
 set_long("This golden sceptre once belonged to Jabba the Hutt.\n"+
          "It looks as if it would make a powerful club if you were to wield it.\n");
 set_value(10000);
 set_weight(5);
 set_type(1);
 set_class(20);
}
