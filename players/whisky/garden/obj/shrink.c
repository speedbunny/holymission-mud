inherit "/obj/treasure";
reset(arg) {
  if (arg) return ;
    set_id("shrink");
    set_short("A Shrink");
    set_long("The magical shrink from an adventurer.\n"+
             "It looks really awful and it stinks horrible.\n"+
             "maybe you can <anger> someone with it.\n"+
             "You'll see what happens.\n");
    set_value(200);
    set_weight(1);
}
init() {
    ::init();
   add_action("anger","anger");
     } 
  anger(str) {
   int i;
   object irritator;
   string irritator_name;
   irritator_name=str;
    irritator = present(str,environment(this_player()));
   if (!irritator){
      write("Your shrink can't find "+(str)+" next to you.\n");
      return 1; } 
   if (!(irritator->query_npc())) {
    if (irritator->query_alignment() <= this_player()->query_alignment()) {
       write("Your shrink found a new owner.\n");
       tell_object(irritator,this_player()->query_name()+" tried to use "+
       "show you the shrink.\n"+"but the shrink found you "+
       "a more evil person and jumps in your\n"+"inventory.\n");
       move_object(this_object(),irritator);
       return 1;
      }
    else  {
      write("As you show your shrink to "+irritator_name+" "+irritator_name+"\n"+
          "is really shocked, can hardly breath and looks now\n"+

          "really stupid and brain-damaged in your direction.\n");
     tell_object(irritator,"\n\nIhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh.\n"+
     this_player()->query_name()+" shows you an awful shrink.\n"+
     "You can hardly breath as you see that awful dried scalp.\n"+
     "You breath to get air, but you nearly die.\n"+
     "You feel to cry but you can't as you feel your power\n"+
     "getting lower.\n");
    i = irritator->query_spell_points();
   if (irritator->query_player()) {
    irritator->restore_spell_points(-i/4);
   }
    irritator->set_vis();
    irritator->run_away();
    return 1;
 }
   return 1; }
  else {
  write("You show the shrink to "+(str)+" but nothing happens.\n");
  return 1; }
}
