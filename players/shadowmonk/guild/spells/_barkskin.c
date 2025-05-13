#include "func.c"

int cost;

status do_spell_checks(string args, object *soul, string file) {
  
  cost = INFO->get_cost("barkskin");
  if (CHECK(cost, INFO->get_level("barkskin")))
    return (1);
  
  if (TP->bark_shadow()) {
    write("You still have your barkskin.\n");
    return (1);
  }
  
  if (!TIME("barkskin", soul, file)) return (1);
  return (1);
}

status do_spell() {
  object shad;

  write("Your skin transforms into a strong dark bark.\n");
  say(NAME(TP) + "'s skin transforms into a strong dark bark.\n");
  if (TP->fireshield()) {
    write("The bark quenches the flames of your fireshield.\n");
    TP->stop_fshield_shad();
  }
  shad = CO(OBJ + "bark_shad");
  shad->set_owner(TP);
  shad->start();
  REDSP(cost);
  return (1);
}
