inherit "obj/monster";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      set_name("staci");
      set_alias("blonde");
      set_short("Staci");
      set_long("A blond haired bimbo named Staci.\n");
      set_female();
      set_level(15);
   }
}
init(){
   ::init();
   add_action("Strip","strip");
   add_action("wear","wear");
   add_action("lay","lay");}
Strip(str){
   if (str == "staci" || str == "Staci"){
      write("You take off staci's clothes and she giggles wickedly.\n");
      /*in the above line, there was a \\n instead of \n, and it was outside the "" */
      return 1;
   }
}
wear(str){
   int yescon; /*the flag for whether the condom is worn 0 = false*/
   yescon = 0;
   if (str == "condom" && yescon == 0) {
      write("Staci says: Ok, that's better.  And somehow you feel safer.\n");
      return 1;}
   else 
      if (yescon == 1) {
      write ("Staci says: But you already have one on!\n");
      return 1;
   }
}
lay(str) {
   if (str == "staci" && yescon == 1) {
      write("Ohh! That feels soo good!  Been a LONG time huh!\n");
      return 1;}
   else
      write("You really oughta be protected! The STD's arn't always that pleasent.\n");
return 1;
}
