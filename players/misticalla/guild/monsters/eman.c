inherit "obj/monster";
   object ob1, ob2;
  
   reset(arg) {
   
    ::reset(arg);
    
   if (arg) return;
   
   set_name("monk");
   set_alias("preacher monk");
   set_short("A preacher monk");
   set_long(
        "A dark haired , green eyed monk smiles at you with \n"
        "gentle eyes. He is responsible for engagements between \n"
	"sweethearts. If you are higher than level 24 you can \n"
        "type 'engage <name1> with <name2>.\n");
       
   set_hp(10000);
   set_ac(1000);
   set_level(1);
   
   }
   
   init() {
     add_action("do_engage","engage"),
     ::init();
     }
     
    do_engage(arg) {
      string str1, str2;
      
      if (this_player()->query_level()<24) return;
    
      if (sscanf(arg,"%s with %s",str1,str2)==2) {
      
        ob1=find_living(str1);
        ob2=find_living(str2);
        
      if (ob1 && ob2 && ob1->query_player() && ob2->query_player() && 
          present(str1,environment()) && present(str2,environment()) &&
         (!present("engagement-ring",ob1)) && (!present("engagement-ring",ob2))) {
        
        if (ob1!=ob2) {          
         engage(ob1,ob2);
         ob1->set_title("happily engaged to "+capitalize(ob2->query_real_name())+"");
         ob2->set_title("happily engaged to "+capitalize(ob1->query_real_name())+"");
         }      
       } 
       return 1;      
      }
     tell_room(environment(),"The monk shrugs helplessly.\n");
      
     return 1;
    }
         
    engage(ob1,ob2) {
         object ring1,ring2;
    
    tell_room(environment(),"The monk gives "+ob1->query_name()+" and "+
                ob2->query_name()+" their rings.\n");
    call_out("done1",2);
                
    ring1=clone_object("players/whisky/genobj/ering");
        
    ring1->set_name1(ob1->query_real_name());
    ring1->set_name2(ob2->query_real_name());
    
    ring2=clone_object("players/whisky/genobj/ering");
  
    ring2->set_name1(ob2->query_real_name());
    ring2->set_name2(ob1->query_real_name());
    
    move_object(ring1,ob1);
    move_object(ring2,ob2);
    
    return 1;
    }
    
   done1() {
     tell_room(environment(),
     "The monk smiles happily.\n");
     call_out("done2",4);
     }
     
   done2() {
     tell_room(environment(),
     "The monk says: Now you are engaged "+ob1->query_name()+" and "+ob2->query_name()+
     ".\n");
     tell_room(environment(),"The preacher monk shakes your hand.\n");
      }
      
