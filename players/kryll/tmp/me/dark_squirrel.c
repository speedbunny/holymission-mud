inherit "/obj/monster";

object nut;
int i, how_many;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("squirrel");
  set_alt_name("animal");
  set_short("A small squirrel with red eyes");
  set_long(
    "A small squirrel that is munching on a nut or two. "+
    "It is foaming at the mouth and its red beady eyes are looking "+
    "around, as if for some meat to eat.\n"
  );
  set_level(5);
  set_size(1);
  set_wc(6);
  set_al(-70);
  set_aggressive(1);
  set_race("mammal");

  how_many = random(3);
  for(i=0; i<how_many; i++) {
    nut = clone_object("/obj/food");
    nut->set_name("nut");
    nut->set_short("nut");
    nut->set_long(
      "A small nut that the squirrel was munching. If it "+
      "could eat it, certainly you could. This nut looks odd though.\n"
    );
    nut->set_weight(1);
    nut->set_value(1);
    nut->set_strength(1);
    nut->set_heal_amount(5);
    nut->set_poison(3);
    nut->set_eating_mess(" gobbles the nut quickly.\n");
    nut->set_eater_mess("The nut tastes bitter.\n");
    move_object(nut, this_object());
  }
}

