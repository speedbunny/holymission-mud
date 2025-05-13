inherit "obj/monster";
reset(arg){
::reset(arg);

set_name("Myrddraal");
set_alias("fade");
set_alt_name("myrddraal");
set_long("For the most part it looks like a normal human save one\n"+
         "thing. It has no eyes, where they should rest on its face\n"+
         "sit empty black holes. Even without eyes you can feel it\n"+
         "looking back at you with a hate that burns for all those\n"+
         "who live.\n");
set_level(27);
set_al(-1000);
set_number_of_arms(2);
set_ac(10);
set_wc(15);
set_aggressive(1);
set_move_at_reset();
}
init(){
 ::init();
   add_action("block","cast");
}
block(arg){
 if(query_verb()== "cast")
{
this_player()->restore_spell_points(-(this_player()->query_sp()/2));
write("Myrddrall says: Your magic is to weak to use here mortal!\n");
return 1;
}
}
