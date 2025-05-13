
inherit "obj/treasure";
#include "/players/brainsprain/spiral/spidef.h"
int drank;
int randomizer;
reset(arg) {
    set_id("A small bottle");
    set_alias("bottle");
    set_short("The small bottle");
    set_long(
"A small bottle with a thick black fluid inside.  The fluid moves back "+
"and forth in the container as if it has a life of its own.  The glass "+
"has a finely engraved picture of a two-headed man.  One head smiling, "+
"the other frowning.\n");
    set_value(100);
    set_weight(1);
}
void init(){
  ::init();
  add_action("drink","drink");
}
int drink(string arg){
if (arg != "bottle"){
write("Sorry, you can not drink that.\n");
return 1;
}
if (arg == "bottle"){
if(!drank) {
randomizer = random(2);
if(randomizer == 1) {
this_player()->heal_self(20);
write("You feel better as you drink the potion.\n");
say(capitalize(TP->query_name())+" drinks the fluid from a bottle.\n");
write("The bottle shatters in your hand!\n");
destruct(TO);
drank = 1;
return 1;
}
else {
TP->hit_player(20);
write("Ughh! This poison tastes awful.\n");
say(capitalize(TP->query_name())+" drinks the fluid from a bottle\n");
destruct(TO);
write("The bottle shatters in your hand!\n");
drank = 1;
return 1;
}
}
}
}
