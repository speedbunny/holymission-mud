inherit "obj/treasure";

reset(arg){
	if(arg) return 1;
  	set_id("quest_statue");
	set_name("statuette");
	set_value((random(10)+ 1) * ((random(10)+ 1)));
	set_short("A statuette");
	set_long("A small statue of a Baal-Rog.\n");
  return 1;
}
