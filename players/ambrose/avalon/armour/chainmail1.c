inherit "obj/armour";

reset(arg){
if(arg) return;

  set_name("chainmail");
  set_short("Mithril Chainmail");
  set_long("This is a shining silver suit of Mithril Chainmail.  It can\n"+
           "turn aside all but the strongest of blows.\n");
  set_ac(4);
  set_weight(7);
  set_type("armour");
  set_size("any");
  set_value(1000);

}
