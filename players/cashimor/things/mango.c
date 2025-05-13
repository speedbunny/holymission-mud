inherit "obj/food";

object voorwerp,sap;
string naam;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("mango");
    set_short("A delicious mango");
    set_long("This mango is still a little bit green, but looks nice...\n");
    set_value(25);
    set_weight(2);
    set_strength(10);
    set_eating_mess(" eats a mango. It seems to taste good...\n");
    set_eater_mess("This mango is delicious!\n");
  }
}

init() {
  ::init();
  add_action("squeeze","squeeze");
}

squeeze(str) {
  if(!id(str)) return 0;
  if(!present(this_object(),this_player())) return 0;
  naam=bevatter();
  if(!naam) {
    write("You squeeze the mango but you spill all the juice!\n");
    say(this_player()->query_name()+" squeezes the mango to nothingness.\n");
    destruct(this_object());
    return 1;
  }
  sap=clone_object("players/cashimor/things/mangojuice");
  sap->set_empty_container(naam);
  write("You squeeze the mango and catch the juice...\n");
  say(this_player()->query_name()+" makes an orange juice of a mango.\n");
  move_object(sap,this_player());
  destruct(voorwerp);
  destruct(this_object());
  return 1;
}

bevatter() {
  voorwerp=present("bottle",this_player());
  if(voorwerp) return "bottle";
  voorwerp=present("jug",this_player());
  if(voorwerp) return "jug";
  voorwerp=present("glass",this_player());
  if(voorwerp) return "glass";
  return 0;
}
