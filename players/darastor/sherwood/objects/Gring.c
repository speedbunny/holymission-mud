inherit "obj/armour";
int num;
reset(arg){
 num=3;
 ::reset(arg);
if (arg) return;
 set_id("goldsun_ring");
 set_alias("ring");
 set_type("ring");
 set_short("Goldsun's ring");
 set_long("Goldsun's ring with small inscription. He got it from Hern.\n");
 set_ac(1);
 set_value(1000);
 set_weight(1);
 set_read("You read a small insription on it: 'Cure poison'.\n");
 }

init(){
 ::init();
 add_action("cure","cure");
 }

cure(str){
 if (((str)=="poison") && (worn)){
   write("The ring heals you from the poison.\n");
   say("A magic power heals the "+capitalize(this_player()->query_name())+".\n");
   this_player()->add_poison(-this_player()->query_poisoned());
    num--;
   if (num<1){
    write("The ring crumblest to the dust.\n");
    destruct(this_object());
   }
  return 1;
 }
 }
