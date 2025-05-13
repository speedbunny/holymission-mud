#define DIR "/players/brainsprain/guild"
/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Poison =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/
int main(string arg) {
  
  string          weap, with, pois;
  object          weap_ob, pois_ob, shad, pope;
  int             i;
  
  if(!arg){
    write("Poison what with what?\n");
    return 1;
  }
  
  if (sscanf(arg, "%s %s %s", weap, with, pois) != 3 || with != "with") {
    write("Poison what with what?\n");
    return 1;
  }
  
  if (!(weap_ob = present(weap, this_player()))) {
    write("You have no " + weap + ".\n");
    return 1;
  }
  
  if (!(pois_ob = present(pois, this_player()))) {
    write("You have no " + pois + ".\n");
    return 1;
  }
  
  if (!pois_ob->query_poison()) {
    write("The " + pois_ob->query_name() + " is no poison.\n");
    return 1;
  }
  
  if (weap_ob->poison_shadow() || weap_ob->query_poison_shadow()) {
    write("You fumble, and pour the " + pois_ob->query_name() 
          + " on the ground.\n");
    return 1;
  }
  
  
  write("You pour " + pois_ob->query_name() +
        " over " + weap_ob->short() + ".\n");
  say(capitalize(this_player()->query_name()) + 
      " pours " + pois_ob->query_name() +
      " over " + weap_ob->short() + ".\n");
//  pois_ob->dec_doses();
  
  if (weap_ob->query_weapon()) {
    i = pois_ob->query_strength();
    shad = clone_object(DIR + "/poison_shadow");
    shad->start_shadow(weap_ob, i * 600 / 50, i);
  }
  
  write("guild/master"->query_dir(1) + "/obj/poison_food\n");
  if (weap_ob->id("potion")){
    pope=clone_object("guild/master"->query_dir(1)+
                      "/obj/poison_food");
    move_object(pope,this_player());
    pope->query_food_type("drink");
    pope->add_poison(pois_ob->query_strength());

    write("Setting names.\n");
    write("Name == "+weap_ob->query_name() + "\n");
    pope->set_name(weap_ob->query_name());
    write("alias == "+weap_ob->alias() + "\n");
    pope->set_alias(weap_ob->query_name());
    // alias set to name
    write("alt_name == "+weap_ob->alias() + "\n");
    pope->set_alt_name(weap_ob->query_short());
    write("short == "+weap_ob->short() + "\n");
    pope->set_short(weap_ob->short());
    //    write("long == "+weap_ob->query_long_desc() + "\n");
    // change to query_long()
    pope->set_long(weap_ob->query_name());
    write("weight == "+weap_ob->query_weight() + "\n");
    pope->set_weight(weap_ob->query_weight());
    write("value == "+weap_ob->query_value() + "\n");
    pope->set_value(weap_ob->query_value());
    write("query_id == "+weap_ob->query_id() + "\n");
    pope->set_id(weap_ob->query_name());
    write("query_smell == "+weap_ob->query_smell() + "\n");
    pope->set_smell(weap_ob->query_smell());
    write("query_get == "+weap_ob->query_get() + "\n");
    // pope->set_can_get(weap_ob->can_pget());
    write("query_info == "+weap_ob->query_info() + "\n");
    pope->set_info(weap_ob->query_info());
  }    
  return 1;
}






