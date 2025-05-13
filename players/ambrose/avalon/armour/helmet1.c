inherit "obj/armour";

reset(arg){
if(arg) return;

  set_name("helmet");
  set_short("Shining Helmet");
  set_long("This helmet cover the whole head of the guard except for two\n"+
           "eye slits to look through.  It does'nt quite extend down far\n"+
           "enough in the front to cover the mouth of the guard.\n");
  set_type("helmet");
  set_weight(3);
  set_ac(1);
  set_size("any");
  set_value(200);
}
