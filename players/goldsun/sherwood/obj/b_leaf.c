inherit "/obj/treasure";
#define TO this_object()

reset(arg){
 if (arg) return;
 set_id("blue leaf");
 set_alias("leaf");
 set_short("A blue leaf");
 set_long("A blue leaf.\n");
 set_value(0);
 set_weight(1);
 }

init(){
  ::init();
 add_action("eat","eat");
 }

drink(str){
 write("You eat blue leaf.\n");
 destruct(TO);
 return 1;
}


