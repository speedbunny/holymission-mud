#define TP this_player()
#define TPN TP->query_name()
#define PPATH "/players/whisky/"

string tied_to,str1;

id(str) {
    return str == "cord";
}

short() {
    if (tied_to) 
        return "A cord tied to " + tied_to;
    return "A cord";
}

long() {
    write("You see nothing special about the cord.\n");
}

query_value() { return 8; }

get() {
    tied_to=0;
    return 1;
}

     
query_weight() {
    return 1;
}

init() {
    add_action("tie", "tie");
    add_action("untie", "untie");
    
    }


drop(arg) {
  object ob;
  ob=present("nose",TP);
  if(!ob)
    notify_fail("You have no cord.");
  if ((arg=="cord") && (str1=="nose" || str1=="clown-nose") && (ob->query_worn())) {
     destruct(ob);
     write("The nose slips from your face.\n");
     say(TPN+" nose slips from "+TP->query_possessive()+" face.\n");
     move_object(clone_object(PPATH+"cnose"),TP);
     tied_to=0;
     write("Your cord vanishes.\n");
     destruct(this_object());
     return 1;                 /* just to be sure */
     }
  else if (arg==str1) {
     tied_to=0;
     move_object(this_object(),environment(TP));
     return 1;
     }
  else if (arg=="cord") {
  tied_to=0;
  write("Your cord vanishes.\n");
  destruct(this_object());
  return 1;
  }
  return;
  }
  
     
tie(arg)
{
    
    if (!arg) return;
    if (sscanf(arg,"rope to %s",str1)==1) return;
    
    if (TP) {
    if (sscanf(arg,"cord to %s",str1)==1) {
    if (tied_to) {
        write("First you should untie the cord.\n");
        return 1;
       }
    if (present(str1,TP)) {
       write("You tie the cord to "+str1+".\n");
       say(TPN+" ties the cord to "+str1+".\n");
       tied_to=str1;
       }
       
    else if (present(str1,environment(this_player()))) {
       write("You tie the cord to "+str1+".\n");
       say(TPN+" ties the cord to "+str1+".\n");
       tied_to=str1;
       move_object(this_object(),environment(this_player()));
       }
    else {
    write("There is no "+str1+" here.\n");
    return 1;
    }
   }
  
 else if (arg=="cord") {
  write("Tie cord to what ?\n");
  return 1;
  }
  }
   return 1;
 }
 
 untie(arg)
 {
    object ob;
    ob=present("nose",TP);
    
    if (!arg) return;
    if (sscanf(arg,"rope from %s",str1)==1) return;
    
    if (TP) {
    if (sscanf(arg,"cord from %s",str1)==1) {
    if (!tied_to) {
        write("The cord is already untied.\n");
        return 1;
       }
       
    if ((str1=="nose" || str1=="clown-nose") && (ob)) {
        destruct(ob);
        move_object(clone_object(PPATH+"cnose"),TP);
        write("You nose slips down your face.\n");
        say(TPN+"'s nose slips down "+TP->query_possessive()+" face.\n");
        }
        
    if (present(str1,TP)) {
       write("You untie the cord from "+str1+".\n");
       say(TPN+" unties the cord from "+str1+".\n");
       tied_to=0;
       }
       
    else if (present(str1,environment(this_player()))) {
       write("You untie the cord from "+str1+".\n");
       say(TPN+" unties the cord from "+str1+".\n");
       tied_to=0;
       }
    else {
    write("There is no "+str1+" here.\n");
    return 1;
    }
   }
  else if (arg=="cord") {
    write("Untie cord from what ?\n");
   return 1;
   }
  }
   return 1;
 }
    
 query_nose() {                   /* special questfunction Whisky */
    if ((tied_to) && (str1="nose" || str1=="clown-nose")) return 1;   
    return;
    }
    
 query_cord() {
   if (tied_to) return 1;
   return;
   }
       
