inherit "obj/armour";
 
int power;
 
reset(arg) {
::reset(arg);
if (arg) return;
 set_name("gloves");
 set_alias("spiked gloves");
 set_short("A pair of spiked gloves");
 set_long("A pair of gloves, spiked with a lot of sharp nails.\n");
 set_ac(1);
 set_size(3);
 set_value(4500);
 set_weight(2);
 set_type("glove");
 power=20;
}
 
init(){
  add_action("punch","punch");
  add_action("punch","hit");
 ::init();
}
 
punch(str) {
  object ob;
 
  if(!worn) { write("You have to wear the gloves if you want to hit"+
    " somebody.\n");
    return 1; }
  if(!str)
   ob=worn_by->query_attack();
  else
   ob=present(lower_case(str),environment(worn_by));
  if(!ob || !living(ob)) {
    write("Punch !? Whom ?\n");
    return 1; }
  if(ob==worn_by) {
    write("Ok, do it ! But you will hurt yourself !\n");
    return 1; }
  if(power>0) {
    punch_object(ob);
    --power; }
  else write("The nails have become dull.\n");
  return 1;
}
 
punch_object(ob) {
  string name;
  name=ob->query_name();
  write("You punch directly into the face of " + name + ".\n");
  say(worn_by->query_name() + " punches into " + name + "'s face.\n");
  call_other(ob,"hit_player",15);
 
}
 
recharge() {
  power=50;
}
 
 
 
