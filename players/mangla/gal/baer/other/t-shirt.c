inherit "/obj/armour";
 
reset(arg) {
  ::reset(arg);
  if(!arg) {
      set_name("T-shirt");
      set_id("T-shirt");
      set_alias("shirt");
      set_ac(0);
      set_short("An OFFICIAL Cara-Basher T-Shirt");
      set_long("An OFFICIAL shirt denoting membership into HM's BIGGEST club!\n");
      set_value(0);
      set_weight(0);
  }
}
query_auto_load() { 
      return "/players/baer/shirt:";
}

drop() {
   return 1;     /* may not be dropped */
}

int query_monk_wear()
{
    return 1;
}

init() {
   ::init();
add_action("_bash","rbash");
}

int _bash(string arg) {
    object who;
    if (!arg){
    write ("You bash your head into the nearest wall.\n");
    return 1;
    }
    who=find_living(arg);
    if(!who || (who->is_invis_for(this_player()))){
        write("No such person.\n");
        return 1;
        }
        write("You bash "+capitalize(arg)+" with all your might.\n");
     tell_object(who,"You feel "+this_player()->query_name()+
      " bashing you about the skull.\n");
        return 1;
}

