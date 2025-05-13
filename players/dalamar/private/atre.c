#include "/players/gareth/define.h"
object captured_monster, monster;
string monster_name;
int empty;

 reset(arg) {
  if(arg) return;
  empty = 1;
}

 init() {
  add_action("get_monster"); add_verb("capture");
  add_action("free_monster"); add_verb("free");
}

 id(str) {
  return (str == "sphere" || str == "black sphere");
}

 short() {
  if(empty) return "A Small Black Sphere";
  return "A Small Colorful Sphere";
}

 long() {
  if(empty) {
   write("This small black sphere is quite light.\n");
   return 1;
 }
  write("This small colorful sphere is quite heavy for it's size.\n");
  write("You can see a miniature "+monster_name+" inside the sphere.\n");
  return 1;
}

 get() { return 1; }
 drop() { return 0; }
 query_value() { return 1200; }
 query_weight() { 
  if(empty) return 1;
  return 5;
}
  query_name() { return "Black Sphere"; }
  query_info() {
  write("This is a sphere of holding. Type 'capture <monster>' to fill\n");
  write("or type 'free' if the sphere is filled.\n");
}

 get_monster(str) {
  monster = present(str, environment(this_player()));
  if(!str || !monster) {
	 write("Must be present to be captured.\n");
	 return 1;
 }
  if(!empty) {
	 write("The sphere is currently occupied.\n");
	 return 1;
 }
  if(monster == TP) {
	 write("You can't capture yourself!!!\n");
	 return 1;
  }
   monster_name = call_other(monster,"query_name");
   captured_monster = monster;
   MO(captured_monster, this_object());
   write("You capture "+str+"!\n");
   say(monster_name+" suddenly disappears!\n");
  empty = 0;
  return 1;
}

 free_monster() {
  if(empty) {
	 write("The sphere is not occupied!\n");
	 return 1;
  }
  if(captured_monster == TP) {
	write("You are imprisoned inside a sphere. You can not escape!\n");
	return 1;
  }
  MO(captured_monster, environment(TP));
  write("You free the imprisoned "+monster_name+".\n");
  write(monster_name+" is angry at being captured. "+monster_name+" attacks!\n");
  say(monster_name+" suddenly appears!\n");
  if(call_other(captured_monster,"query_npc"))
	 call_other(captured_monster, "set_aggressive", 0);
  if(call_other(captured_monster,"query_npc"))
	 call_other(captured_monster, "attack_object", TP);
  empty = 1;
  monster_name = "";
  captured_monster = 0;
  return 1;
}
