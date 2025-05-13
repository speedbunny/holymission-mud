
inherit "obj/soft_drink";
#include "/players/brainsprain/spiral/spidef.h"
int drank;
void reset(int arg) {
    ::reset(arg);
    if(!arg){
      set_name("green potion");
      set_alias("potion");
      set_short("A green potion");
      set_drinker_mess("You feel the poison drain out of your body.\n");
      set_drinking_mess(" drinks from a green potion.\n");
      set_empty_container("bottle");
      set_long(
"  A small bottle with a thick green fluid inside.  The fluid moves back\n"+
"  and forth in the container as if it has a life of its own.  The glass\n"+
"  seems to have chipped a bit, or might have been eroded by some acid.\n");
    set_value(5000);
    set_weight(1);
}

}
int bustup() {
write("The bottle shatters in your hand!\n");
  destruct(TO);
  return 1;
}

void init(){
  ::init();
  add_action("drink","drink");
}
int drink(string arg){
if (arg != "bottle" && arg != "potion"){
write("Sorry, you can not drink that.\n");
return 1;
}
else if(!drank) {
write(drinker_mess);
say(TP->query_name()+ drinking_mess);
TP->add_poison(-TP->query_poisoned());
bustup();
drank = 1;
return 1;
}
}
