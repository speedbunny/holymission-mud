inherit "obj/monster";
reset(arg){
::reset(arg);

set_name("Draghkar");
set_alias("draghkar");
set_long("It looks like a small dragon with only one set of legs.\n"+
         "Where its front legs should be stand a huge set of wings\n"+
         "that are twice as large as its body.Its teeth look like\n"+
         "they could bite a man in half.\n");
set_level(21);
set_number_of_arms(2);
set_ac(10);
set_wc(15);
set_aggressive(1);
set_move_at_reset();
}
init(){
 ::init();
 add_action("block","springleap");
}
block(arg){
 if(query_verb()=="springleap")
{
write("The Draghkar swoops down from the sky and knocks you out of\n"+
      "the sky!\n");
this_player()->hit_player(100);
return 1;
}
}

