inherit "obj/treasure";

reset(arg){
 if (arg) return;
  set_id("purse");
  set_short("An old small purse");
  set_long(" This is common purse. It is small and old, but something in\n"
          +"your mind tells you that you could try to shake it.\n");
 
  set_value(30); /* you could destruct it .. if drop*/
 }

drop() {
 write("Your purse crumbles to the dust.\n");
 destruct(this_object());
 return 1;
 }
put(){
 write("Your purse looses his magical power and crumbles to the dust.\n");
 destruct(this_object());
 return 1;
 }

init(){
 ::init(); 
 add_action("shake","shake");
 }

shake(str){
  this_player()->add_money(3000);
  return 1;
 }
