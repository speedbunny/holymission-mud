inherit "obj/armour";
 
int power;
 
reset(arg) {
::reset(arg);
if (arg) return;
 set_name("boots");
 set_alias("combat boots");
 set_short("A pair of combat boots");
 set_long("This is a pair of combat boots. You can image that it must "+
   "terribly hurt to get kicked with them.\n");
 set_ac(1);
 set_size(3);
 set_value(5000);
 set_weight(2);
 set_type("boot");
 power=20;
}
 
init(){
  add_action("kicking","kick");
 ::init();
}
 
kicking(str) {
  object ob;
 
  if(!worn) { write("If you want to kick somebody, you have to wear"+
    " your combat boots.\n");
    return 1; }
  if(!str)
   ob=worn_by->query_attack();
  else
   ob=present(lower_case(str),environment(worn_by));
  if(!ob || !living(ob)) {
    write("Kick !? Whom ?\n");
    return 1; }
  if(ob==worn_by) {
    write("How want you to do that ? Please show me !\n");
    return 1; }
  if(power>0) {
    kick_object(ob);
    --power; }
  else  write("Your boots have bocome useless.\n");
 
  return 1;
}
 
kick_object(ob) {
  string name;
  name=ob->query_name();
  write("You kick " + name + " with your combat boots.\n");
  say(worn_by->query_name() + " kicks " + name + " with "+
      worn_by->query_possessive() + " combat boots.\n");
  call_other(ob,"hit_player",20);
 
}
 
recharge() {
  power=50;
}
 
 
 
