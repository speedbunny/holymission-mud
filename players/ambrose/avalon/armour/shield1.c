inherit "obj/armour";

reset(arg){
if(arg) return;

  set_name("shield");
  set_short("Unicorn Shield");
  set_long("The shield has the crest of Avalon on it, the Unicorn rampant.\n"+
           "It is a sturdy round shield, easily moved to block almost any\n"+
           "any blows.\n");
  set_ac(2);
  set_size("any");
  set_type("shield");
  set_weight(4);
  set_value(600);

}
