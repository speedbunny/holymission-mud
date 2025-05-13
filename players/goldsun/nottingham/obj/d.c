inherit "/obj/treasure";
#define TO this_object()

reset(arg){
 if (arg) return;
 set_id("nottingham diamond");
 set_alias("diamond");
 set_short("A small diamond");
 set_long("A small diamond. It looks very shine and expensive.\n");
 set_value(10000);
 set_weight(1);
 }

int drop(){
 write("You lost your diamond.\n");
 destruct(this_object());
 return 1;
}
