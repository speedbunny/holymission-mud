#define PPATH "/players/patience/smilequest/"
inherit "obj/food";

reset(arg) {

  if (!arg) {
    set_name("ham");
    set_alias("delicious ham");
    set_short("A piece of delicious ham");
    set_long("It's a piece of delicious austrian-ham, there is a cord tied to the ham.\n");
    set_eater_mess("Wow, that tastes fine.\n");
    set_eating_mess(" eats piece of ham.\n");
    set_strength(8);
    set_value(40);
    set_weight(2);
  }
}
 init() {
   add_action("untie","untie");
   add_action("untie","get");
   ::init();
   }
   
 untie(arg) {
   if (arg!="cord from ham") return;
      write("You untie the cord from the ham.\n");
      say(this_player()->query_name()+" unties the cord from the ham.\n");
      move_object(clone_object(PPATH+"cord"),this_player());      
      destruct(this_object());
     return 1;
   }
