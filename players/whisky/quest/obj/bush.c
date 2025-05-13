/* fireberry-bush  (c) Whisky */

#define TP  this_player()
#define TPN TP->query_name()
#define TPPOS  TP->query_possessive()
#define TPOBJ  TP->query_objective()

inherit "obj/treasure";
int counter;

reset(arg) { 
   counter=0; 

  if (arg) return;
  
  set_id("bush");
  set_alias("fireberry-bush");
  set_short("A fireberry-bush");
  set_long("A big fireberry-bush.\n");
  set_weight(1000);
  set_light(41);
  }
    

init() { 
  add_action("get_berry","pick");
  add_action("get_berry","get");
  add_action("get_berry","take");
  add_action("shake","shake");
}

get_berry(str) {
  object ob;
  if (str=="berry" || str=="fireberry") {
    if (counter >= 40) {
       write("You can't, there are no berries left in the bush.\n");
       return 1;
    }
    write("You picked a berry from the bush.\n");
    say(TPN+" picked a berry from the bush.\n");
    ob=clone_object("players/whisky/quest/obj/berry");
   if (transfer(ob,TP)) { move_object(ob,environment(TP)); }
    counter++;
    return 1;
  }
}

shake (str) {
object ob;
int i;

  if (str=="bush") {
    if (counter >= 4 ) {
       write("You shake the bush. Nothing happens.\n");
       return 1;
    }
    write("Some berries fell from the bush.\n");
    say(TPN+" shakes the bush, and some berries fall down.\n");
    for (i=0;i<2;i++)
       move_object(clone_object("players/whisky/quest/obj/berry"),
         environment(this_object()));
    counter+=2;
    return 1;
  }
}

no_clean() { return 1; }
