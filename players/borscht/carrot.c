inherit "obj/treasure";
reset(arg) {

    set_id("A small carrot chunk");
    set_alias("carrot");
    set_short("A carrot chunk");
    set_long(
"  A small chunk of carrot.  It has a reddish tint.  It looks like\n"+
"  it might taste good with some bread.\n"+
"\n");
    set_value(0);
    set_weight(1);
}
void init(){ 
  ::init();
  add_action("eat","eat");
}
eat(arg){
if (arg != "carrot"){
write("Sorry, you can not eat that.\n");
return 1;
}