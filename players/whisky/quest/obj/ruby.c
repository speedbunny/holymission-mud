

inherit "obj/treasure";
   int charges, i;
   

  reset(arg) {
  
  if (arg) return;
  i = 1;
  set_id("ruby");
  set_alias("ruby of fear");
  set_short("A red ruby");
  set_weight(1);
  set_value(2000);
  
  }
  
  long() {
     write("You see flames red and burning as the flames from hell.\n"+
           "You feel your heart moving faster, as you look at this\n"+
           "devilish ruby. Your bain seems to explode from fear.\n"+
           "Your nerves are crying from pain and you feel your heart.\n"+
           "full of fear !!!!.\n");
           run_fool();
        }
    
    
  run_fool() {
    int i;
    for(i=0;i<(2+random(10));i++) {
   this_player()->run_away();
    }
   }
   
  init() {
    add_action("show","show");
    ::init();
    }
    
  show(arg) {
    string vname;
    object victim;
    int i;
    
  
  
  if (!arg) return;
  
  if (sscanf(arg,"ruby to %s",vname)==1) {
  
  victim=present(vname,environment(this_player()));
  
  if (victim && living(victim)) {
  
  if (charges <=4) {
   
  tell_object(victim,
  this_player()->query_name()+" shows you a strange ruby !!!!\n\n\n"+
  "You see flames red and burning as the flames from hell.\n"+
  "You feel your heart moving faster, as you look at this\n"+
  "devilish ruby. Your bain seems to explode from fear.\n"+
  "Your nerves are crying from pain and you feel your heart.\n"+
  "full of fear !!!!.\n");
  
   if (victim) {
   for(i=0;i<(2+random(10));i++) {
   victim->run_away();
   }
   charges++;
   }
   
  }
  
  else {
  write("Your ruby suddenly crumbles to dust !\n");
  destruct(this_object());
  }
  
  return 1;
 }
 
  write("Nothing happens.\n");
 }
  
 return 1;
 }
  
 query_quest_item() { return 1; }
  
  
   drop() {
    write("Somehow you can't drop this ruby.\n");
      return 1;
      }

clean_up() { 
   return 1; 
}

query_cursed()
{
   return i;
}

remove_curse()
{
  i = 0;
}

get()
{
 if (!i)
  return 1;
 else 
  write("You are * zapped * by a mental bolt.\n");
  return 0;
}
