inherit "/obj/treasure";

reset(arg){
 if (arg) return;
 set_id("leaf");
 set_value(0);
 set_weight(1);
 set_short("A leaf");
 set_long("A small leaf from the tree or bush.\n"); 
}
