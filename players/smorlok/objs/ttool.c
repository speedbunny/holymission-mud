inherit "obj/treasure";
#include "/players/smorlok/ansi.h"

int hidden;

reset(arg) {
  if(!arg) {
    set_id("ttool");
    set_value(0);
    set_weight(0);
set_short("Smorlok's *testing* tool");

    set_long("This testing tool is only a test, read it for more info.\n");
    set_info("Smorlok's testing tool.");
    set_read("Possible commands are:\n\n"
           +HIC+ "hideit  "+NOR+": Makes the tool invisible\n"
           +HIC+ "searchit"+NOR+": Finds the tool after you've hidden it\n"
           +HIC+ "tearit  "+NOR+": Destroys the tool\n"
           +HIC+ "wnmc    "+NOR+": announces a colored chat msg\n"
           +HIC+ "rsay str"+NOR+": say something in "+HIR+"red"   +NOR+"\n"
           +HIC+ "ysay str"+NOR+": say something in "+HIY+"yellow"+NOR+"\n"
           +HIC+ "bsay str"+NOR+": say something in "+HIB+"blue"  +NOR+"\n"
           +HIC+ "gsay str"+NOR+": say something in "+HIG+"green" +NOR+"\n"
           +HIC+ "ssh str"+NOR+": shout something "+NOR+"\n"
           +HIC+ "ssay str"+NOR+": say something "+NOR+"\n"
);
  }
}

init() {
  ::init();
  add_action("hide_it","hideit");
  add_action("search","searchit");
  add_action("tear","tearit");
  add_action("wnmc","wnmc");
  add_action("rsay","rsay");
  add_action("ysay","ysay");
  add_action("bsay","bsay");
  add_action("gsay","gsay");
add_action("ssh","ssh");
add_action("ssay","ssay");


}

short() {
  if(hidden) return 0;
  return ::short();
}

hide_it() {
  if(!present(this_object(),this_player())) return 0;
  if(hidden) {
    write("But it's already hidden!\n");
    return 1;
  }
  write("You hide the tool.\n");
  say(this_player()->query_name()+" hides something.\n");
  hidden=1;
  return 1;
}

search() {
  if(!present(this_object(),this_player())) return 0;
  if(!hidden) {
    write("But it wasn't hidden!\n");
    return 1;
  }
  write("You find your tool again.\n");
  say(this_player()->query_name()+" finds something in his pockets.\n");
  hidden=0;
  return 1;
}

tear(str) {
  write("You tear the tool to shreds.\n");
  say(this_player()->query_name()+" tears a tool to shreds.\n");
  destruct(this_object());
  return 1;
}
wnmc(){
shout("\n[chat] "+this_player()->query_name()+" says: we need more "
                                                          +HIR+"C"
                                                          +HIG+"O"
                                                          +HIB+"L"
                                                          +HIG+"O"
                                                          +HIC+"R"
                                                          +HIM+"S"
                                                          +NOR+".\n");
return 1;
}
ssh(str){
shout(str+"\n");
return 1;
}
rsay(str){
write("You say: "+HIR+str+NOR+"\n");
say(this_player()->query_name()+" says: "+HIR+str+NOR+"\n");
return 1;
}

ysay(str){
write("You say: "+HIY+str+NOR+"\n");
say(this_player()->query_name()+" says: "+HIY+str+NOR+"\n");
return 1;
}

bsay(str){
write("You say: "+HIB+str+NOR+"\n");
say(this_player()->query_name()+" says: "+HIB+str+NOR+"\n");
return 1;
}

gsay(str){
write("You say: "+HIG+str+NOR+"\n");
say(this_player()->query_name()+" says: "+HIG+str+NOR+"\n");
return 1;
}
ssay(str){
say(str+"\n");
return 1;
}
/*
getcontrol(name){

object obj;
if (!name)
{ write("A name of a living is required.\n"); return 1;}
obj=find_living(name);
if(!obj){write("No "+name+" found.\n");return 1;}

}
*/

drop(silently) {
  return 1;
}

query_auto_load() {
  return "players/smorlok/objs/ttool:";
}

prevent_insert() {
  return 1;
}

