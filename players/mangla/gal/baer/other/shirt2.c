inherit "/obj/armour";
#define ENV environment
#define TP this_player()
#define QNAME query_name()
#define QPOS query_possessive()

 
reset(arg) {
  ::reset(arg);
  if(!arg) {
      set_name("T-shirt");
      set_id("T-shirt");
      set_alias("shirt");
      set_ac(0);
      set_short("An OFFICIAL Cara-Basher T-Shirt");
      set_long("An OFFICIAL shirt denoting membership into HM's BIGGEST club!\n"
		"The front of the shirt depicts a bloodied, battered, broken, \n"
		"and bruised face which has been pulverised by a piece of steel \n"
		"piping. Singed stubble is all that remains of any facial hair, \n"
		"as if the whole head had been doused in flamable liquid and \n"
		"set alight. Flaps of skin hang loosly amongst the acid scarred \n"
		"cuts and burns on the face. A bloodied pulp lies mashed into the \n"
		"nose would normally be. The few remaining teeth jut out awkwardly. \n"
		"On the back of the shirt is written a story about the lying \n"
		"pathetic bastards life and a damnation written at the bottom  \n"
		"with the words 'Sleep with one eye open, or one day you wont \n"
		"wake up'. Someone has scrawled under this the words 'Die Scum, \n"
		"Die' in blood.\n");
      set_value(0);
      set_weight(0);
  }
}
query_auto_load() { 
      return "/players/baer/shirt2:";
}

drop() {
   return 1;     /* may not be dropped */
}

int query_monk_wear()
{
    return 1;
}

int query_mage_wear()
{
    return 1;
}

int query_ninja_wear()
{
    return 1;
}

init() {
   ::init();
add_action("_rbash","rbash");
add_action("_show","show");
}

_rbash(arg) {
    object who;
    if (!arg){
    write ("You bash your head into the nearest wall.\n");
    return 1;
    }
    who=find_living(arg);
    if(!who || (who->is_invis_for(this_player()))) {
        write("No such person.\n");
        return 1;
        }
        write("You bash "+capitalize(arg)+" with all your might.\n");
        tell_object(who, "You feel "+this_player()->query_name()+
          " bashing you about the skull.\n");
        return 1;
}
_show(arg) {
  if(!arg || (arg!="shirt"))
  {
    write("Show what?\n");
    return 1;
    }
        write("You show everyone your shirt.\n");
tell_room(ENV(TP),TP->QNAME+" proudly displays "+TP->QPOS+" OFFICIAL Cara-Bashers T-Shirt.\n");
tell_room(ENV(TP),"It indicates "+TP->QPOS+" membership to the BIGGEST club in Holy Mission.\n");
        return 1;
        }
