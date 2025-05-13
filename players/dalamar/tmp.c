 /*  ###################################################################

                A Wiztool (for Wizes under level 35)  (c) Whisky          

     ################################################################### */

 
#define TP       this_player()
#define TPL      TP->query_level()
#define TPN      TP->query_name()
#define TPR      TP->query_real_name()
#define INTO     TP->query_intoxination()
#define TO       this_object()
#define E        environment
#define WIZ      (TP->query_level()>30) 
#define APPR     (TP->query_level()>29)
#define FILE     "/players/portil/obj/pointer:"
 
int count,lighted,hide;
object normal,obj,finder, mark ,stack,last;
string name;

#if 0
query_auto_load() { return FILE+hide+"#"+lighted; }
#endif 0

query_auto_load() { return FILE; }

drop() { return 1; }

get() {

    if (!TP->query_wiz() || TPR=="kitty") {
  
        write("Your dark pointer activates itself in your inventory.\n"+
        "It's a very strong magic-item, so do only use it for\n"+
        "serious patches. Bad patches can force your item to leave\n"+
        "you for ever and lower you power. (NEW FUNCTIONS NOW !) \n");
        return ( 1 );        
      }
    return ( 1 );
    
   }


id(str) { return str=="pointer" || str==name; }

short() {
  if (hide) return;
  if (lighted) return "A stack-pointer (glowing)";
  else
   return "A stack-pointer";
  }

long() {
   string name;
   name = capitalize(TP->query_real_name());
   if (APPR) {
   write("This is the pointer of "+name+".\n");
   }
    write("It is the dark powerfull tool for undeads and Wizards tool.\n"+
         "It looks like a black pentagram, with a strange magial aura.\n"+
         "Just type 'help pointer' to see its functions Muhahaaaa !!!!\n\n");
                                    
   return 1;
  }

init_arg(arg) {
    sscanf(arg,"%s#%s",hide,lighted);
    }

  set_message(n) {
    tell_object(TP,n+"\n");
   }
 
/* ############################ the init ############################### */ 

init() {        
        
  add_action("help","help");
  if (APPR) {
    add_action("pdest","pdest");   add_action("pwho","pwho");
    add_action("plight","plight"); add_action("pinto","pinto");
    add_action("pmail","pmail");   add_action("pitem","pitem");
    add_action("pinv","pinv");     add_action("pnet","pnet");  
    add_action("ploc","ploc");     add_action("set_count","count");
    add_action("plerr","plerr");   add_action("man","man");
    add_action("plerr","ple");     add_action("pto","pto");
    add_action("phide","phide");   add_action("pshow","pshow");
    add_action("pguild","pguild"); add_action("phome","phome");
    add_action("pfile","pfile");   add_action("pfile","pf");
    add_action("quests","quests"); add_action("pweight","pweight");
    add_action("pweight","pw");    add_action("clear","clear");
  } 
   if ( WIZ ) {
          
    add_action("porc","porc");              add_action("pdebug","pdebug");
    add_action("clean","clean");            add_action("pweap","pweap");
    add_action("parm","parm");              add_action("do_snooptrace","psnoop");
    add_action("pid","pid");                add_action("pdebug","pde");
    add_action("ptitle","ptitle");          add_action("ptitle","pt");
    add_action("p_dump","p_dump");          add_action("p_mark","p_mark");
    add_action("p_destruct","p_destruct");  add_action("p_call","p_call");
    add_action("p_mark","pm");              add_action("ph","ph");
    add_action("p_destruct","pd");          add_action("pi","pi");
    add_action("pr","pr");                  add_action("pl","pl");
    add_action("pdl","pdl");                add_action("pme","pme");
    add_action("p_call","pc");              add_action("p_curse","pcu");
    add_action("p_move","pmo");             add_action("p_stack","ps");
    add_action("p_show","pso");             add_action("p_clone","pcl");
    add_action("show_mark","show_mark");    add_action("show_mark","sm");
    add_action("p_trans","p_trans");        add_action("p_trans","pt");
    add_action("do_bolt","bolt");	    add_action("ptick","tick");
   }
    return 1;
}

ptick() { "/obj/tick"->qry_timer(); return 1; }

phide() { 
 write("You hide your pointer in your inventory.\n"+
       "Just type <pshow> to make it visible again.\n");
   hide=1;
  return 1;
 }
pshow() {
  write("You make your pointer visible again.\n");
  hide=0;
  return 1;
  }
 
check_player() {
    int i;
    object ob;
    
    ob=all_inventory(environment(this_player()));
    
    for(i=1;i<sizeof(ob);i++) {
       if (ob[i]->query_player()) return ( 0 ) ;
       }
     return ( 1 );
   }
   

pdest() {
  write("You destroy your stack-pointer !\n");
  destruct(TO);
  return 1;
}
 
/* ########################## the helpdir ############################## */

 
help(str) {

  if (str!="pointer" && str!="p1" && str!="p2" && str!="p3") return;
    
  if (str=="pointer") {
  write("Following commands are available:\n\n"+
        "help p1                   #HELP-DIR for Wizards >= level 30\n"+
        "help p2                   #HELP-DIR for Wizards >= level 31\n"+
        "help p3                   # EXAMPLE for WIZARDS >= level 31\n\n"+
       
        "                                          Much fun: Whisky\n\n");
        
   }
   
   else if (str=="p1") {
    write("\n\n"+ 
  
  "phome                 APPR     # brings you to your personal workroom\n"+                
  "pdest                 APPR     # destructs this object \n"+
  "plight                APPR     # shows the current light-strenght\n"+
  "                                 you gave your pointer.\n"+
  "plight <num>          APPR     # to set your light strength \n"+
  "man                   APPR     # shows you which files you should read.\n"+
  "man <file>            APPR     # to show you the files in \n"+
  "                                 the doc or open directory.\n"+
  "pinv  <name>          APPR     # shows you the items an object has\n"+
  "pinv  env             APPR     # shows you the items in your environment\n"+
  "pitem <obj> in <name> APPR     # gives you a better description\n"+
  "                                 an object in a living.\n"+
  "pmail                 APPR     # gives you an invisible mailreader.\n"+
  "pnet                  APPR     # shows you from which host the players are.\n"+
  "ploc <name>           APPR     # shows you the location of a living.\n"+
  "plerr  or ple         APPR     # shows you the last lines in the lp.mud-log.\n"+
  "pwho                  APPR     # gives you a detailed players-description.\n"+ 
  "pinto                 APPR     # to set your intoxination level.\n"+ 
  "pto                   APPR     # sea,church,guild,post.... moves you to that destination.\n"+
  "pfile                 APPR     # pfile <env>, <living-name> or <living-name> <item> \n"+
  "                                 to show you the code of an object or a living\n"+
  "quests                APPR     # to show you all available quests and their points\n"+
  "                                 quests <name> shows you the quests a player had done\n"+
  "pguild                APPR     # sets you the guild you like (1..7).\n"+
  "pweight <living> (pw) APPR     # corrects the weight in a player.\n"+
  "phide                 APPR     # hides the pointer in your inventory.\n");
  
  }
  else if (str=="p2") {
  write("This is the menue for Wizards > 30.\n\n"+
  "pdebug          (pde)   WIZ       # shows you your error-logfile.\n"+
  "porc  <level>           WIZ       # clones you a testmonster.\n"+
  "pweap <class>           WIZ       # clones you a testweapon.\n"+
  "parm  <class>           WIZ       # clones you a testarmour.\n"+
  "pid   <string>          WIZ       # sets you a second id for the pointer (door-testing..).\n"+
  "clean                   WIZ       # clears all the inventory in your room.\n"+
  "ptitle <player> <title> WIZ       # sets the title in a player.\n"+
  "psnoop                  WIZ       # shows you who is snooped by whom.\n"+  
  "p_mark_living    (pl)   WIZ       # marks a living object \n"+
  "p_here           (ph)   WIZ       # marks your environment \n"+
  "p_mark <number>  (pm)   WIZ       # marks an object if you know the number \n"+
  "show_mark        (sm)   WIZ       # shows the file (code) of a marked object\n"+
  "p_dump_list      (pdl)  WIZ       # gives you all inventory of a marked obj in numbers\n"+
  "p_call           (pc)   WIZ       # sets a function in the marked object\n"+
  "p_destruct       (pd)   WIZ       # destructs a marked object.\n"+
  "p_curse <player> (pcu)  WIZ       # gives a player a shout-curse.\n"+
  "p_stack          (ps)   WIZ       # stores a marked object as object stack or changes position.\n"+
  "p_show           (pso)  WIZ       # shows you the marked objects in your pointer.\n"+
  "p_clone          (pcl)  WIZ       # clones you a marked object.\n"+
  "p_trans <living> (pt)   WIZ       # moves a living to your environment.\n"+
  "p_move           (pmo)  WIZ       # moves a marked object into another object.\n"+
  "bolt    <living>        WIZ       # throws a big bolt of lighting at your victim.\n\n");
  }
  
  else if (str=="p3") {
   write("\n\n"+
  "Examples:\n\n"+
  "A player named Rudi has a buggy object in his inventory, we want to help him\n"+
  "and destruct this object.\n\n"+
  "Step 1:  p_mark_living Rudi  or quicker pl Rudi  ..... to mark the living.\n"+
  "Step 2:  p_dump_list   or quicker pdl ..... to get the inventory of Rudy.\n"+
  "Step 3:  p_mark <number> or pm <number> .... to mark the buggy object.\n"+
  "Step 4:  p_destruct    or quicker pd   ......to destruct the maked object.\n\n"+
  "We want to clone a torch and give it to Rudi.\n\n"+
  "Step 1:  p_clone /obj/torch       # clones and marks an obj/torch.\n"+
  "Step 2:  p_stack                  # moves the marked object into the stack.\n"+
  "Step 3:  p_mark_living Rudi       # markes Rudi (we have now in the as obj(stack)=torch\n"+
  "                                   and as obj(mark)=Rudi now we want to move the torch\n"+
  "                                   into Rudi or better the stack into the mark.\n"+
  "Step 4:  p_stack                  # now stack=Rudi mark=torch\n"+
  "Step 5:  p_move stack             # we move now the torch into the stack=Rudi.\n\n"+
  "       Just test it out, marker functions are great :*) \n");
  
   }                                   

  return ( 1 );
 }
 
 /* ############################# workroom ######################################## */
 
 phome()  { /* thank you Klorathy */
  object workroom;
  
  if (!workroom) {
     workroom=clone_object("players/klorathy/obj/workroom");
     workroom->set_owner(TP);
     }
     TP->move_player("home#"+file_name(workroom));
   return 1;
   }

/* ############################## move player ##################################### */

pguild(arg) {

  if (!arg) {
     write("Syntax: pto <number>\n\n"+
     "Thief   number=1\n"+
     "Druid   number=2\n"+
     "Fighter number=3\n"+
     "Jedi    number=4\n"+
     "Mage    number=5\n"+
     "Bard    number=6\n"+
     "Monk    number=7\n"+
     "Ninja   number=8\n");
   return 1;
   }
   if (arg=="1") {
      TP->set_guild(1);
      write("You are now Thief.\n");
      }
   else if (arg=="2") {
      write("You are now Druid.\n"); 
      TP->set_guild(2);
      }
   else if (arg=="3") {
      write("You are now Fighter.\n");
      TP->set_guild(3);
      }
   else if (arg=="4") {
      write("You are now Jedi.\n");
      TP->set_guild(4);
      }
   else if (arg=="5") {
      write("You are now Mage.\n");
      TP->set_guild(5);
      }
   else if (arg=="6") {
      write("You are now Bard.\n");
      TP->set_guild(6);
      }
   else if (arg=="7") {
     write("You are now Monk.\n");
     TP->set_guild(7);
      }

   else if (arg=="8") {
      write("You are now Ninja.\n");
      TP->set_guild(8);
   return 1;
   }
  return 1;
  }

/* ############################## bolt ########################################  */

do_bolt(arg) {
   object ob;
   
   if (!arg) {
       ob=this_player()->query_attack();
     if (ob) arg=ob->query_name();
     }
     else 
     ob=present(arg,environment(this_player()));
     if ((!ob) || (!living(ob)) || (ob->query_invis()) || (!present(ob,E(TP)))) {
     write("At whom ?\n");
     return 1;
     }
   
   if (ob->query_player()) {
          write("YOU DONT DARE !!!!!\n"); 
          return 1;       
          }
          
     tell_room(E(TP),""+TP->query_name()+
     " summons a bright bolt of lightning from the sky !\n"); 
              
    ob->hit_player(2000);  
  return ( 1 );
 }
 
 /* ############################### pweight ##################################### */
 
 pweight( arg ) {
    object ob, inv;
    int i, sum;
     
    sum = 0;
    
    if (!arg) {
       write("Syntax: pweight <name>\n");
    } else if  (!find_living(arg)) {
        write("No "+arg+" found !\n");
    } else {
       ob=find_living(arg);
       inv=all_inventory(ob);
      
       write("(crator/name/filename/weight) of "+arg+"\n\n");
                    
       for(i=1;i<sizeof(inv);i++) {
            
            write(ladjust(inv[i]->query_name(),15));          
            write(ladjust(file_name(inv[i]),40));
            write(ladjust(creator(inv[i]),20));                     
            write(ladjust(inv[i]->query_weight(),10));
            
          sum+=inv[i]->query_weight();
         }
       
       write("\n\n"+ob->query_name()+"  Current Weight: "+ob->query_weight()+
             "  Shell Weight: "+sum+"  (corrected)\n");
       
       ob->add_weight(sum - ob->query_weight());
       
       }
     
     return ( 1 );
     }
       

     
 /* ############################### ptrans ###################################### */
 
 p_trans( arg ) {
    object ob;
 
    if (!arg) {
        write("Syntax: p_trans <name>\n");
    } else if  (!find_living(arg)) {
        write("No "+arg+" found !\n");
    } else {
        ob=find_living(arg);
        
         if (ob->query_player() && ob->query_level()>=TP->query_level()) {
            write("You can't trans high level Wizards !\n");
         } else {
            write("You transfer "+ob->query_name()+" from "+file_name(E(ob))+" !\n");
            tell_object(ob,"You are magically transfered by "+TPN+".\n");
            move_object(ob,E(TP));
           }
        }
     return ( 1 );
     }
            
 /* ############################### ptitle ######################################
      (Newizes may patch player a title, but the player will notice who did)      */
 
      
  ptitle(arg) {
    string who, what;
    object ob;
    
   
       
    if (sscanf(arg,"%s %s",who,what)==2) {
        
        ob=find_living(who);
        
        if (!ob) {
           write("Your pointer didn't find "+who+".\n");
        
        } else {
           write("You set "+ob->query_name()+"'s title to:\n"+
                 what+"\n");
                 log_file("whisky.title",capitalize(TPR)+" title ("+who+"): "+what+"\n");
                 ob->set_title(what);
                 tell_object(ob,TPR+" just changed your title !\n");
               }  /* endif */
               
        } else {
          write("Syntax: ptitle <player> <title>\n");
          return ( 1 );
         }  /* endif */
         
     return ( 1 );
     
     }
                  
 /* ############################### pfile ####################################### */
 
 pfile ( arg ) {
    string arg1, arg2;
    
  if (!arg) {
     write("Syntax:\n\n"+
           "pfile env     # shows you the code of the room where you just are.\n"+
           "pfile dragon  # shows you the code of the dragon if found.\n"+
           "pfile orc axe # shows you the code of the axe in the orc if found.\n\n");
      } else if ( arg=="env" ) {
         mark=E(TP);
      } else if ( sscanf(arg,"%s %s",arg1,arg2)==2 ) {
         mark=present(arg2,find_living(arg1));
      } else if ( arg ) {
         mark=find_living(arg);
      } else {
         pfile();
      }
     
     show_mark();
     mark=0;
     
   return ( 1 );
   
   }
 
 
 
/* ##########################       quests     ###################### */

 quests ( arg ) {
    object room, quests, player, *solved, ob;
    int i, j, sum, psum;
    
    if (arg) {
    player=find_living(arg);
    }
    
    if (!find_object("room/quest_room") ) {
         write("Error in the quest_room, talk to an Arch !\n");
        return ( 1 );
    }
    
      sum=0;
      psum=0;
      room=find_object("room/quest_room");
      quests=all_inventory(room);
      
    if (!arg) {
      write("Syntax: (name/points) \n\n");
    
      for (i=1;i<sizeof(quests);i++) {
    
      write(ladjust(quests[i]->query_name(),20));
      write(ladjust(quests[i]->query_weight(),10));
	write("\n");
      sum+=quests[i]->query_weight();
      }
     write("\n\n"); 
     write("Sum (points): "+sum+"\n\n");
     
         
   } else if (player && (!player->query_quests())) {
          write(capitalize(arg)+" has NO quests solved !\n");
          
    } else if (player) {
          
          solved=explode(player->query_quests(),"#");
          
          write("Syntax: (name/points) current name: "+capitalize(arg)+"\n\n");
          
          for(i=1;i<sizeof(solved);i++) {
             
            write(ladjust(solved[i],18));
            
                
             for (j=1;j<sizeof(quests);j++) {
                 if (solved[i]==quests[j]->query_name()) {              
                 write(ladjust(quests[j]->query_weight(),10));
		write("\n");
                 psum+=quests[j]->query_weight();
               } 
            }
          }
        write("\n\n");
        write("Sum (points): "+psum+"\n\n");
        
      } 
      
      else {
        write("No such player found !\n");
       }
    return ( 1 );
    }  
          
    
         
        
      
        
 /* ###############################  pto ######################################## */
 
 pto(arg) {
 
 if (!arg) {
     write("Syntax:\n\n"+
       "pto guild   OR\n"+
       "pto sea     OR\n"+
       "pto post    OR\n"+
       "pto sex     OR\n"+
       "pto code    OR\n"+
       "pto monk    OR\n"+
       "pto thief   OR\n"+
       "pto mage    OR\n"+
       "pto jedi    OR\n"+
       "pto fighter OR\n"+
       "pto ninja   OR\n"+
       "pto church.\n\n");
    
  } else if (arg=="guild")     {
     TP->move_player("through a magic door#room/adv_guild");
     
  } else if (arg=="sea")       {
     TP->move_player("through a magic door#room/sea");
     
  } else if (arg=="church")    {
     TP->move_player("through a magic door#room/church");
     
  } else if (arg=="sex")       {
     TP->move_player("through a magic door#players/whisky/meadow/room/tent");
     
  } else if (arg=="monk")      {
     TP->move_player("through a magic door#players/whisky/guild/room/c10");
     
  } else if (arg=="thief")     {
     TP->move_player("through a magic door#players/herp/guild/hideout");
     
  } else if (arg=="mage")      {
     TP->move_player("through a magic door#players/llort/guild/tower/hallway");
         
  } else if (arg=="jedi")      {
     TP->move_player("through a magic door#players/kelly/guild/inner");
     
  } else if (arg=="fighter")   {
     TP->move_player("through a magic door#players/capablanca/guild/restroom");
     
  } else if (arg=="ninja")    {
     TP->move_player("through a magic door#players/patience/ezo/empty");
     
  } else if (arg=="post")     {
     TP->move_player("through a magic door#room/post");
  
  } else if (arg=="code")     {
     TP->move_player("through a magic door#players/whisky/genobj/coding_room");

     
  } else                      {
     write("Type just pto, to see the available destinations.\n");
     
  }
  return ( 1 );
 }
/* ############################## second id  ###################################### */

pid(str) {

   if (!str) {
      write("Syntax: pid <string> !\n");
      return 1;
      }
      
   name=str;
   write("New second id = "+name+"\n");
   return 1;
   }
   
/* ############################## snooptrace ###################################### */
 
 do_snooptrace(string str)
  { object *ob;
    string name;
    int i;
    object snooper;
    if (this_player()->query_level() < 30)
      return 0;
          
       ob = users();
        while (i < sizeof(ob))
          { name = (string)ob[i]->query_real_name();
            name = capitalize(name);
            name = name + extract("                     ",0,20-strlen(name));
            snooper = query_snoop(ob[i]);
            if (snooper) {
              write (name + " : Snooped by " +
                     capitalize(snooper->query_real_name()) + ".\n");
              }
            else write (name+" : Not snooped.\n");
            i++;
          }
      return 1;
  }
  
/* ########################## light ##################################### */
 
plight(arg) {
 int n;
 if (!arg) {
    write("Current light-strength = " + set_light(0) + "\n");
    return 1;
  }
  if (sscanf(arg , "%d" , n) == 1) {
     if (n>0) {
        say(TP->query_name()+"'s pointer glows brightly !\n");
        write("You pointer lights up the dark place !\n");
        set_light(n);
        lighted=1;
     }
     else {
     write("Suddenly everything gets darker !\n");
     lighted=0;
     set_light(n);
     return 1;
  }
 return 1;
 }
}
   set_count(n) {
   if (sscanf(n, "%d", count) == 1) write("Ok.\n"); 
   else return;
   count -=n;
   return 1;
  }

/* ################################ wintro ################################ */

   pinto(arg) {
     int i;

    if (!arg) {
       write("Syntax: pinto <num>     Current intoxication="+INTO+"\n");
     return 1;
     }
     if (sscanf(arg, "%d", i) == 1) {
        if ((INTO+i) < 0) {
           write("Your current intoxication is "+INTO+"\n"+
                 "intoxination < 0 don't work !\n");
            }
        else  
          TP->drink_alcohol((-INTO+i));
          write("Your current intoxication is now "+INTO+"\n");
         return 1;
        }
      return 1;
     }
    
/* ################################ docs ################################## */

   man(arg) {
    int i;
    string topics;
    topics = ({ "/doc", "/doc/efun", "/doc/lfun", "/doc/helpdir",
                "/doc/build", "/doc/w", "/doc/LPC", "/doc/local",
                "/open" });
     
     if (!arg) {
        write("Topics:\n");
        for (i=0;i<sizeof(topics);i++)
        write(topics[i]+ " ");
        write("\n");
      return 1;
      }
      arg= "/"+arg;
      i=0;
      while(i<sizeof(topics)) {
      if (file_size(topics[i]+arg) == -2) {
         write("Subtopics "+topics[i]+arg+":\n");
         ls(topics[i]+arg+"/.");
         return 1;
         }
      if (file_size(topics[i]+arg) > 0) {
         write(topics[i]+arg+":\n");
         cat(topics[i]+arg); 
       return 1;
      }
      i++;
     }
     write("Not found !\n");
     return 1;
    }
         
      
  
/* ######################## debugging ################################# */

  pdebug(arg) {
    if (!arg) arg = TP->query_real_name();
    tail("/log/"+arg);
    rm("/log/"+arg);
  return 1;
  } 

/* ########################### lpmud.log ################################ */
  
   plerr() {
     tail("/lpmud.log");
    return 1;
   }
 /* ############################# mail ################################ */

  pmail() {
   object ob,box;
   ob=present("mailread",TP);
   if (ob) {
      write("You have already your invisible mailreader !\n");
   return 1;
   }
   box = clone_object("obj/mail_reader");
   transfer(box,TP);
   write("Now, you can read your mail like in the post !\n");
  call_out("mdest",1000,box);
   return 1;
   }
   
   mdest(ob) {
     destruct(ob);
    write("You mail tool has been destructed.\n");
     }
     
 /* ############################# items ############################### */

  pitem(arg) {
   object obj;
    string arg1,arg2;
   if (!arg) {
      write("Usage: pitem <obj> in <player> !\n");
      return 1;
    }
    if (sscanf(arg,"%s in %s",arg1,arg2) == 2) {
       if (!find_living(arg2)) {
          write("Couldn't find "+arg2+".\n");
       return 1;
      }
     obj = findob(arg1,find_living(arg2));
     }
     else {
     obj = find_object(arg);
     if (!obj) obj=findob(arg,TP);
     if (!obj) obj=findob(arg,E(TP));
     }
     if (!obj) {
      write(arg+" cannot be found !\n");
     return 1;
     }
    write("\nItem:\t"+obj->short()+"\n\n");
     if (creator(obj)) write("Creator:\t"+capitalize(creator(obj)));
     write("\nFilename:\t"+file_name(obj));
     if (obj->query_id())       write("\nId:\t"+obj->query_id());
     if (obj->query_name())     write("\nName:\t"+obj->query_name());
                                write("\nWeight:\t"+obj->query_weight());
     if (!living(obj))          write("\nValue:\t"+obj->query_value());
     if (obj->query_armour())   write("\nArmour Class:\t"+obj->armour_class());
     if (obj->query_weapon())   write("\nWeapon Class:\t"+obj->weapon_class());
     write("\n\nLong Desc.:\n");
     obj->long();
     write("\n");
     if (WIZ) {
        copy(obj);
        }
        
    return 1;
   }
  
  
 findob(arg,where) {
  object ob;
  ob = first_inventory(where);
  while(ob) {
  if ((ob->id(arg)) || (ob->short()==arg) || (ob->query_name()==arg)) return ob;
    ob = next_inventory(ob);
  }
 }

  copy(obj) {
    string i,j;
    write("Copying "+obj->short()+"\n");
    sscanf(file_name(obj),"%s#%s",i,j);
    move_object(clone_object(i),TP);
   return 1;
   }


 /* ########################### inventory ############################### */

  pinv(arg) {
   object ob, where;
   int n;
   if (!arg) {
      write("Usage pinv <living> !\n");
   return 1;
   }
   if (arg)  where = find_ob(arg);
   else where = TP->query_name();
   if (!where) {
      write("Didn't find "+arg+"\n");
   return 1;
   }
   write_inv_ob(where);
   return 1;
  }

    write_inv_ob(obj) {
    object ob;
    int n;
    ob= first_inventory(obj);
    write("Inventory of: "); write_ob_and_desc(obj);
    while(ob) {
     write(" "+n+": "); write_ob_and_desc(ob); 
     n++;
     ob = next_inventory(ob);
   }
   write("That's all !\n");
   return 1;
 }
  
  write_ob_and_desc(obj) {
   string str;
   if (!obj) return;
   write(obj); write("-->");
   str=obj->short();
   if (!str) str = obj->query_name();
   if (!str) str = "Invisible Object !";
   write(str+"\n");
   return 1;
  }

  find_ob(str) {
    object ob;
    string s1, s2, tmp;
    int nr;
    if (!str) {
    write("ERROR: No argument given to find object.\n");
    return 1;
    }
    if (sscanf(str, "%s,%s", s1, s2) !=2) {
       if (sscanf(str, "%d", nr) ==1) {
       return nr_in_ob(nr, E(TP));
     }
     else {
     search_all(str);
     }
   }
   ob=search_all(str);
   while (s2 && ob) {
   tmp = 0;
   if (sscanf(s2, "%s,%s", s1, tmp) !=2) s1=s2;
   ob = search_next(s1, ob);
   s2 = tmp;
   }
   return ob;
  }

  search_all(str) {
   object ob;
   if (!str) {
   write("ERROR: No argument to search_all() !\n");
   return 1;
   }
   if (str=="env") ob=E(TP);
   if (!ob) ob=present(str, TP);
   if (!ob) ob=present(str, E(TP));
   if (!ob) ob=find_object(str);
   if (!ob) ob=find_living(str);
   if (!ob) ob=find_living("ghost of "+str);
  return ob;
  }
  
  nr_in_ob(n, obj) {
   object ob;
   int nr;
   nr=n;
   if (nr < 0) return;
   if (!obj) return;
   ob=first_inventory(obj);
   while(ob && nr) {
    ob=next_inventory(ob);
    nr-=1;
   }
   return ob;
  }
   
   

  /* ############################### net ############################### */   

  pnet() {
   string who;
   int i;
   string desc,name;
   who=users();
   write("Name               Host\n");
   for(i=0;i<sizeof(who);i++) {
   desc = who[i]->short();
   name = capitalize(who[i]->query_real_name());
   if (desc!=0)  write(ladjust(name,16)+" ");
   else write(ladjust("("+name+")",16)+" ");
   if (desc = who[i]->query_remotehost())
   write(desc);
   else write(ladjust(query_ip_name(who[i]),50));
   write("\n");
   }
  return 1;
 }
 /* ######################## testmonster ################################ */

  porc(arg) {
    int i;
    object ob;

 if (!arg) {
   write("Usage: porc <num> !\n"); 
    return 1;
  }
  if (sscanf(arg , "%d" , i) == 1) {
     if (i>60) {
        write("The level of the testmonster was too high !\n"+
              "Try again !\n");
        }
     else if (i<=0) {
        write("You shell give an argument > 0 !\n");
     }
     else {
     ob=clone_object("obj/monster");
     ob->set_name("orc");
     ob->set_short("An Orc (Tester)");
     ob->set_long("The Testmonster of "+capitalize(TP->query_real_name())+"\n");
     ob->set_spell_mess2("Orc does a vicious fart, you are burned awfully !");

     ob->set_chance(10);
     ob->set_spell_dam(random(2*i));
     ob->set_level(i);
     move_object(ob,E(TP));
     write("Ok.\n");
    }
     return 1;
  }
  return 1;
}

/* ######################### testweapon ############################  */

  pweap(arg) {
    int i;
    object ob;
 if (!arg) {
    write("Usage: pweap <num> !\n");
    return 1;
  }
  if (sscanf(arg , "%d" , i) == 1) {
     if (i>20) {
        write("The class of the weapon was too high !\n"+
              "Try again !\n");
     }
     else if (i<=0) {
        write("You shell give an argument > 0 !\n");
     }
     else {
     write("Ok.\n");
     ob=clone_object("obj/weapon");
     ob->set_name("sword");
     ob->set_alias("testsword");
     ob->set_short("A testsword");
     ob->set_long("The Testweapon of "+capitalize(TP->query_real_name())+"\n");
     ob->set_class(i);
     ob->set_weight(1+i/5);
     if (transfer(ob,TP)) {
    write("You can't carry that much\n");
    destruct(this_object());
   return 1;
    }
    }
     return 1;
  }
  return 1;
 }
/* ######################## testarmour ################################ */
  parm(arg) {
    int i;
    object ob;
 if (!arg) {
    write("Usage: parm <num> !\n");
    return 1;
  }
  if (sscanf(arg, "%d " ,i) == 1) {
     if (i>4) {
        write("The class of the armour was too high !\n"+
              "Try again !\n");
     }
     else if (i<=0) {
        write("You shell give an argument > 0 !\n");
     }
     else {
     write("Ok.\n");
     ob=clone_object("obj/armour");
     ob->set_name("mail");
     ob->set_alias("testmail");
     ob->set_short("A testmail");
     ob->set_long("The Testmail of "+capitalize(TP->query_real_name())+"\n");
     ob->set_ac(i);
     ob->set_weight(1+i);
     if (transfer(ob,TP)) {
    write("You can't carry that much\n");
    destruct(this_object());
   return 1;
   }
     }
     return 1;
  }
  return 1;
 }
/* ######################### who is here ############################## */

 pwho() {
  string who;
  int i;
  who=users();
  write(
  "Name:            level gender str dex int con wis chr wc ac money\n");
  for(i=0;i<sizeof(who);i++) {
  if (who[i]->short())
  write(ladjust(who[i]->query_real_name(),16)+" ");
  else write(ladjust("("+who[i]->query_real_name()+")",16)+" ");
  write(ladjust(who[i]->query_level(),6)+" "+
        ladjust(who[i]->query_gender_string(),6)+" "+
        ladjust(who[i]->query_str(),3)+" "+
        ladjust(who[i]->query_dex(),3)+" "+
        ladjust(who[i]->query_int(),3)+" "+
        ladjust(who[i]->query_con(),3)+" "+
        ladjust(who[i]->query_wis(),3)+" "+
        ladjust(who[i]->query_chr(),3)+" "+
        ladjust(who[i]->query_wc(),3)+" "+
        ladjust(who[i]->query_ac(),3)+" "+
        ladjust(who[i]->query_money(),11)+"\n");
   }
 return 1;
 }
 ladjust(str,n) { return extract(str+"                              ",0,n-1);}

 /* ###################### find something #############################  */

  ploc(arg) {
  
   object ob,env,what;
   int k;
   ob=find_living(arg);
   
   if (!arg) {
   write("Usage: ploc <name> !\n");
   return 1;
   }
   if (!ob) {   
   write("No "+arg+" found !\n");
   return 1;
   }
   
   env=E(ob);   
   what=all_inventory(E(ob));
   write("Filename: "+file_name(env)+"\n");
   write(env->long());
   
   for (k=0;k<sizeof(what);k++) {
   
     
       write(k+": "+what[k]->short()+": "+file_name(what[k])+"\n");
     
  }   
       
   return 1;
  } 

   
  /* #################### marker functions for wizards ##################### */


ph() { return p_mark("here"); }
pr(str) { if (!str) return p_call("reset"); else return p_call("reset 1"); }
pi() { return p_call("init"); }
pl(str) { return p_mark("living "+str); }
pme() { return p_mark("living "+this_player()->query_real_name()); }
pdl() { return p_dump("list"); }

p_dump(str) {
    int tmp;
    if (!WIZ) return; 
    if (mark == 0) {
   write("Nothing marked.\n");
   return 1;
    }
    if (str == "list") {
   object ob;
   int i;
   ob = first_inventory(mark);
   while(ob) {
       i += 1;
       write(i + ":\t");
       write(ob);
       write("\t" + call_other(ob, "short") + "\n");
       ob = next_inventory(ob);
   }
   return 1;
    }
    write(call_other(mark, "short"));
    if (living(mark))
   write("(living)\n");
    if (call_other(mark, "query_npc"))
   write("(NPC)");
    write("\n");
    tmp = call_other(mark, "query_value");
    if (tmp)
   write("Value:\t" + tmp + "\n");
    tmp = call_other(mark, "query_weight");
    if (tmp)
   write("Weight:\t" + tmp + "\n");
    return 1;
}

p_mark(str) {
    string tmp;

    if (!WIZ) return;
    if (str == 0)
   return 0;
    if (sscanf(str, "living %s", tmp) == 1) {
   mark = find_living(tmp);
   if (!mark) {
       write("No such living object.\n");
       return 1;
   }
   write(mark); write("\n");
   return 1;
    }
    if (str=="last") {
        if (!last) {
            write("No last available.\n");
            return 1;
        }
        if (!objectp(last)) {
            write("Last is not an object,\n"); 
            return 1;
        }
        mark=last;
        write(mark); write("\n");
        return 1;
    }
    if (sscanf(str, "ob %s", tmp) == 1) {
   mark = find_object(tmp);
   if (!mark) {
       write("No such object.\n");
       return 1;
   }
   write(mark); write("\n");
   return 1;
    }
    if (str == "up") {
   if (mark == 0)
       return 0;
   if (environment(mark) == 0)
       return 0;
   mark = environment(mark);
   write(mark); write("\n");
   return 1;
    }
    if (str == "here") {
   mark = environment(this_player());
   write(mark); write("\n");
   return 1;
    }
    if (sscanf(str, "%d", tmp) == 1) {
   object ob;
   if (mark == 0)
       return 0;
   ob = first_inventory(mark);
   while(tmp > 1) {
       tmp -= 1;
       if (ob == 0)
      return 0;
       ob = next_inventory(ob);
   }
   if (ob == 0)
       return 0;
   mark = ob;
   write(mark); write("\n");
   return 1;
    }
    return 0;
}


p_destruct() {
    object ob;
    if (!WIZ) return; 
    if (!mark)
   return 0;
    ob = environment(mark);
    destruct(mark);
    write("Ok. New: "); write(ob); write("\n");
    mark = ob;
    return 1;
}

p_call(str) {
    string with, what;
    int iwhat;

    if (!WIZ) return; 
    if (!str)
        return 0;
    if (!mark) {
   write("No object marked.\n");
   return 1;
    }
    if (sscanf(str, "%s %d", with, what) == 2)
        iwhat = 1;
    else if (sscanf(str, "%s %s", with, what) != 2) {
   if (sscanf(str, "%s", with) == 1)
       iwhat = 0;
   else
       return 0;
    }
    write("Got: "); write(call_other(mark, with, what)); write("\n");
    return 1;
}

  clean() {
    string s;
    object ob;
    int i;
  
  if ((!WIZ) && (sscanf(file_name(E(TP)),"players/"+TP->query_real_name()+"/%s",s)<1)) {
      write("You are only allowed to clean up own rooms as Newwiz.\n");
      return 1;
    }
   else {
      
   ob=all_inventory(environment(this_player()));
   for (i=0;i<sizeof(ob);i++) {
       if (!ob[i]->query_player() && !ob[i]->id("castle") && !ob[i]->id("door")) {
          write(ob[i]->short()+" "+file_name(ob[i])+" destructed.\n");
          destruct(ob[i]);
        }
    }
  return 1;
  }
  
  return 1;
  }
  
 p_curse(arg) {    
      object ob,curse;
      ob=find_living(arg);
      if (!ob) {
         write("No "+arg+" found !\n");
         }
       else if (ob && ob->query_level()>TP->query_level()) {
         tell_object(ob,TPN+" tried to give you a shout_curse.\n");
         write("OHH, you don't dare !\n");
         }
       else if (ob) {
        curse = clone_object("obj/shout_curse");
        move_object(curse,ob);
        write("Ok.\n");
        return 1;
      }
    return 1;
  }
  
   show_mark( arg ) {
    string file,arg1,arg2;

     if (!mark) {
         write("Nothing marked !\n");
       
    } else {
    
      file=file_name(mark);
      write("Current marked object: "+file+"\n\n");
  
     if(sscanf(file,"%s#%s",arg1,arg2)==2) {
       file=arg1;
      }               
      
       file="/"+file+".c";
       TP->more(file);
     
     }
     
    return ( 1 );
 }
    
      
  p_clone(str)
  { if (str)
      { if (!(str = this_player()->valid_read(str,1)))
          write("Invalid file name.\n");
        else if (!(mark = clone_object(str)))
          write("Could not clone object.\n");
        else { move_object(mark,this_player());
               write(mark);
               write("\n");
             }
        return 1;
      }
  }

 p_show()
  { if (mark)
      { write("Mark:  "); write(mark); write("\n");}
    if (stack)
      { write("Stack: "); write(stack); write("\n");}
    if (last)
      { write("Last:  "); write(last); write("\n"); }
    return 1;
  }
  
 p_stack()
  { object hobj;
    hobj = mark;
    mark = stack;
    stack = hobj;
    p_show();
    return 1;
  }
  
  p_move(str) {
    string tmp;
    object toobj;

    if (str == 0)
        return 0;
    if (mark == 0) {
        write("Nothing marked.\n");
        return 1;
    }
    if (str=="stack") {
            if (stack == 0) {
            write("Stack not set.\n");
            return 1;
        }
        move_object(mark,stack); write("OK.\n");
        return 1;
    }
    if (sscanf(str, "living %s", tmp) == 1) {
        toobj = find_living(tmp);
        if (!toobj) {
            write("No such living object.\n");
            return 1;
        }
        move_object(mark,toobj); write("OK.\n");
        return 1;
    }
    move_object(mark,str); write("OK.\n");
    return 1;
}


 
