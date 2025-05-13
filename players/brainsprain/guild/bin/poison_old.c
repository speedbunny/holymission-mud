#define DIR "/players/brainsprain/guild"
/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Poison =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/
int main(string arg) {
  
  string          weap, with, pois;
  object          weap_ob, pois_ob, shad;
  int             i;
  
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
  say(capitalize(this_player()->query_name()) + " pours " + pois_ob->query_name() +
      " over " + weap_ob->short() + ".\n");
  pois_ob->dec_doses();
  
  if (weap_ob->query_weapon()) {
    i = pois_ob->query_strength();
    shad = clone_object(DIR + "/poison_shadow");
    shad->start_shadow(weap_ob, i * 600 / 50, i);
  }
  return 1;
}






