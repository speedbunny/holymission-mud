inherit "obj/armour";

reset(arg){
if(arg) return;

  set_name("ring");
  set_short("Class Ring");
  set_long("This is a class ring from the Avalonian Military Academy.  You\n"+
           "see a Unicorn engraved on it, below that the logo AMA.  You can\n"+
           "barely make out some writing below the crest.\n");
  set_read("The ring reads 'Order is an Absolute.'\n");
  set_ac(1);
  set_type("ring");
  set_weight(1);
  set_size("any");
  set_value(100);

}
