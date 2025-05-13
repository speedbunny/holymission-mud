inherit "obj/monster";

int block;

#define S(x) tell_room(environment(this_object()),x)
  
  reset(arg) {
     ::reset(arg);
    
  if (!arg) {
  
    set_name("monk");
    set_alt_name("poor monk");
    set_short("An old poor monk");
    set_long("You see an old, poor monk. He looks very thin and weak. \n"+
             "He seems to be very hungry. When you look at his face\n"+
             "you get the impression, that he is a old wise man.\n");
             
    set_level(2);
    set_gender(1);
    }
 }
 

run_away() { return; }

enter_inventory(ob)
{
  if (ob->query_food() && !block)
  {
     happy();
     block = 1;
  }
}

catch_tell(arg) {
   object ob;
   string str1,str2;
     
   if (sscanf(arg,"%s arrives.",str1)==1) {
      call_out("sulk",2);
      return 1;
   }
   if (sscanf(arg,"%s curtseys %s",str1,str2)==2) {
      write("The monk bows at you.\n");
      return 1;
   }
    if (sscanf(arg,"%s bows %s",str1,str2)==2) {
      write("The monk bows at you.\n");
      return 1;
   }  
   if (sscanf(arg,"%s waves %s",str1,str2)==2) {
      write("The monk waves at you.\n");
      return 1;
   }
   return 1;
     
}
    
sulk() {
   S("The monk says: I am so hungry, i wish somebody could give me something to eat.\n");
         
   }
    
   
   happy() {
   write("The monk smiles happily.\n");
   call_out("happy2",2);
   }
   
   happy2() {
   write("The monk hugs you.\n");
   call_out("happy3",2);
   }
   
   happy3() {
   S("The monk says: Thank you stranger, you are really kind to me.\n");
   call_out("happy4",5);
   }
   
   happy4() {
   S("The monk says: Hmm I see you are adventuring, maybe i can give you a help.\n");
   call_out("happy5",8);
   }
   
   happy5() {
   S("The monk says: You will find what you need in one eye of the devil.\n"+
     "               But you will need something to remove it's curse.\n");
   call_out("happy6",7);
   }
   
   happy6() {
    S("The monk says: I heared in the Crescent lake might be\n"+
      "               an item, which helps you on your mission.\n");
    call_out("happy7",4);
 }
   happy7() {
   write("The monk bows to you.\n");
   block = 0;
   }
   
   
