/* ###################################################################################

                            Engagementring (c) Whisky 
                            
   ################################################################################### */
   
   string name1, name2;
   
   id(arg) { return arg=="ring" || arg=="engagement-ring" || arg=="engagementring"; }
   
   short() { return "A whitegold engagement-ring (happily worn)"; }
   
   long() {
   
   write(
   
   "You see a beautiful whitegold engagementring with a blue diamond in it.\n"+
   "And the engraving "+name1+" totally fallen in love with "+name2+".\n"+
   "Just type 'help ring' to get more information.\n");
   
    }
  
  drop() {
      return ( 1 );
      }
      
  get() { 
     write(
      "Your engagement-ring slips on your finger.\n");     
  return 1; 
  }
   
  extra_look() {
    return capitalize(name1)+" is happily engaged to "+capitalize(name2);    
    }
    

  query_auto_load() {
    return "players/whisky/genobj/ering:"+name1+"#"+name2;
    }

   
  init_arg(str) {
    sscanf(str,"%s#%s",name1,name2);
    }
      
  set_name1(n1) { name1=n1; }
  set_name2(n2) { name2=n2; }
  
   init() {
       
     add_action("do_tell","ring");
     add_action("all_ring","aring");
     add_action("do_rdest","rdest");
     add_action("do_help","help");
     add_action("do_fiddle","fiddle");
     add_action("do_title","rtitle");
     }
    
    do_help(arg) {
      if (arg!="ring") return;
      
      write(
      "ring     lets you talk with your sweety.\n"+
      "aring    shows you all the sweeties which are logged on.\n"+
      "fiddle   to fiddle your ring.\n"+
      "rtitle   to set you your engagement title.\n"+  /* sets only if wanted */
      "rdest    to destruct your engagement-ring.\n");
     return 1;
     }
   
   do_title() {
    
      write("You get your engagement-title.\n");
      
      if (name1 && name2) {
           this_player()->set_title( capitalize(name1)+" is happily engaged to "+
                                     capitalize(name2)+"" );
                                }
      
      return ( 1 );
      }
      
         
    do_rdest() {
       write("You get rid of your engagement !\n");
       destruct(this_object());
       return 1;
       }
     
    do_fiddle() {
       say(capitalize(this_player()->query_real_name())+
       " fiddles happily with "+this_player()->query_possessive()+" engagement-ring.\n");
       write("You fiddle happily with your engagement-ring.\n");
       return 1;
       }
          
    do_tell(arg) {
       object ob;
       
       ob=find_living(name2);
       
       if (!ob) {
         write("Your sweety is currently not logged on.\n");
         return 1;
         }
         
      tell_object(ob,"["+capitalize(name1)+"]"+" "+arg+"\n");
     return 1;
     }
                
    all_ring(arg) {            
       object *u;
       int i;
       u=users();
       
     if (!arg) {
         write("Sweeties online:\n\n");
         }
              
     for(i=0;i<sizeof(u);i++) {
       
       if ((arg) && (present("engagement-ring",u[i]))) {
            tell_object(u[i],"[*"+name1+"*] "+arg+".\n");
           } 
    
     else if (present("engagement-ring",u[i])) {  
            write(u[i]->query_name()+"\n");   
       }
     }        
     tell_object(this_player(),"Ok.\n");
   return ( 1 );
   }
   
 
         
        
