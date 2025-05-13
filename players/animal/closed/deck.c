# define NAME "animal"
# define MASTER find_player(NAME)
# define tell_me(x) tell_object(MASTER, x)
# define CAP_NAME(y) capitalize(y->query_real_name())
 
int safe_mode, next_channel,amount_of_channels,inform_reset;
int watch_mode,comm_mode,interact;
object list_ob;
string list_stat,tv_centre;
 
query_auto_load () {return "players/animal/closed/deck:";}
 
init_arg () {
       write("Installing Deck...");
       write("|n");
     }
 
get () {if (this_player()==MASTER) write("---Activating deck...");
 
 
 
 
        else destruct(this_object());
       return 1;
      }
 
short() { return "Cyberdeck 100XJ"; }
 
scroll_list (arg) {
      int i;
 
      i=arg;
      if (i==amount_of_channels-1){
         list_ob[i]=0;
         list_stat[i]=0;
        }
      else {
         while(list_ob[i]) {
           list_ob[i]=list_ob[i+1];
           list_stat[i]=list_stat[i+1];
           i+=1;
          }
         list_ob[i-1]=0;
         list_stat[i-1]=0;
        }
   }
 
make_channel (ob) {
       int i;
 
       if(next_channel==amount_of_channels) {
             error ("No channels"); return 0;
            }
       while(list_ob[i] && list_stat[i])
            i+=1;
       list_ob[i]=ob; list_stat[i]="<<-->>";
       next_channel=i+1;
     return 1;
    }
 
check_channel (arg) {
       int channel;
 
       if (!arg) { error("Channel needed as an argument"); return -1; }
       sscanf(arg,"%d",channel);
       if (channel < 0 || channel > amount_of_channels) {
                error("Illegal channel"); return -1;
               }
     return channel;
    }
 
find_ob_inventory(str) {
       object ob;
 
       ob=first_inventory(MASTER);
       while (ob) {
           if(ob->id(str)) return ob;
           ob=next_inventory(ob);
          }
       return 0;
     }
 
find_ob_environment (str) {
       object ob;
 
       ob=first_inventory(environment(MASTER));
       while (ob) {
            if(ob->id(str)) return ob;
            ob=next_inventory(ob);
           }
     return 0;
   }
 
presence_ob (ob) {
          int i;
 
          while (list_ob[i]) {
                 if(ob==list_ob[i]) {error("Double remote not possible");
                    return 0;}
                 i+=1;
               }
           return 1;
      }
 
drop () {if (safe_mode) {
             if (this_player()!=MASTER) {
                write(CAP_NAME(MASTER)+" is not playing.\n");
                face_the_truth_punk ();
               }
             }
          tell_me("You need the Cyber-Deck.\n");
 
          return 1;
        }
static comm_open (arg) {
       int channel;
 
       channel=check_channel(arg);
       if(channel<0) return 1;
          if(list_ob [channel]) {
                   write ("Channel "+channel+" active.\n");
                   list_stat [channel]= "<<ON>>";
                   if(!safe_mode) write(file_name(list_ob[channel])+
                        ": Channel opened.\n");
                  }
          else error("Nothing on that channel");
     return 1;
   }
 
static comm_remote (str) {
       object ob;
 
       ob=find_ob_inventory (str);
       if(!ob)
           ob=find_ob_environment (str);
       if (!ob) error("Object not found");
       else {
          if(!presence_ob(ob)) return 1;
          make_channel (ob);
          move_object(ob,tv_centre);
          if(!safe_mode) write(file_name(ob)+": Remote.\n");
          ok();
         }
    return 1;
   }
 
static comm_close (arg) {
       int channel;
 
       channel=check_channel(arg);
       if (channel<0) return 1;
       if (list_ob [channel]) {
            list_stat [channel] = "<<-->>";
            write ("Channel "+channel+" closed.\n");
            if(!safe_mode) write(file_name(list_ob[channel])+
                 ": Channel closed.\n");
            move_object(list_ob [channel], tv_centre);
           }
       else error("Nothing on that channel");
     return 1;
    }
 
static comm_forget (arg) {
      int channel;
 
      channel=check_channel(arg);
      if(channel<0) return 1;
      move_object(list_ob[channel], MASTER);
      if(!safe_mode) write(file_name(list_ob[channel])+
          ": Forgot.\n");
      ok();
      scroll_list(channel);
      next_channel-=1;
    return 1;
 }
 
static comm_waste (arg) {
       int channel;
 
       channel=check_channel(arg);
       if (channel<0) return 1;
       destruct (list_ob [channel]);
       if (!safe_mode) write(file_name(list_ob[channel])+
            ": Destruct.\n");
       ok();
       scroll_list (channel);
       next_channel-=1;
     return 1;
   }
 
static comm_tv () {
       int i;
 
       if(!list_ob[0]) {write("No channels made.\n"); return 1;}
       write("Channels:\n");
       while (list_ob[i]) {
            write (i+". "+list_stat[i]+
               ": "+file_name(list_ob[i])+"\n");
            i+=1;
           }
       return 1;
     }
static comm_rtoggle (str) {
        if(!str) comm_mode=0;
        else {comm_mode=1; write("Comm-Mode\n");}
        watch_mode=1;
        write("Stop cmd: @\n");
        return 1;
       }
 
static comm_Reset () {
          object ob, obj;
 
              write ("Reseting...\n");
              ob=first_inventory(tv_centre);
              while (ob) {
                obj=next_inventory(ob);
                move_object(ob,MASTER);
                if(!safe_mode) write(file_name(ob)+": Ok.\n");
                ob=obj;
               }
       write("Done.\n");
       return 1;
   }
static comm_centre (str) {
             if (!str){ write("Keeping the old centre.\n"); return 1;}
             tv_centre=str;
             ok();
             return 1;
            }
 
static comm_safe (str) {
         if(!str) { error("Argument needed"); return 1;}
         if(str=="on") safe_mode=1;
         else if(str=="off") safe_mode=0;
         ok();
       return 1;
     }
 
ok () {write("Ok.\n");}
 
error (str) {
        if(!str) write("Error.\n");
        else write("Error: "+str+".\n");
       }
 
reset (arg) {
 
  if(inform_reset) tell_me("Reset.\n");
 
  if (arg) return;
 
  amount_of_channels=20;
  list_ob=allocate(amount_of_channels);
  list_stat=allocate(amount_of_channels);
  tv_centre="players/animal/shops/condos/0";
 }
 
id (str) {if(this_player()==MASTER) return str=="deck";
          return 0;
         }
 
init () {
 
    if (MASTER && this_player()!=MASTER && present(this_object(),MASTER)){
        tell_me("Intruder: "+CAP_NAME(this_player())+
             ".\n");
    tell_object(this_player(),CAP_NAME(MASTER)+"'s inner life isn't your "+
              "business!\n");
    call_out("kick_out",1, this_player());
   }
   add_action("command_handler"); add_xverb("");
}
 
command_handler (arg) {
     string comnd;
     comnd=query_verb();
     if (watch_mode){ execute_remote (comnd,arg); return 1;}
     else
     if(call_other(this_object(),"comm_"+comnd,arg)) return 1;
     return;
}
 
execute_remote (cmd,arg) {
          if (cmd=="@") {write("Stopped remote.\n"); watch_mode=0;
                return 1;}
          move_objects (MASTER);
          watch_mode=0;
          if(!arg) arg="";
          if (comm_mode) command(cmd+" "+arg, MASTER);
          else MASTER->force_us(cmd+" "+arg);
          watch_mode=1;
          move_objects (tv_centre);
        return 1;
       }
 
move_objects (dest) {
      int i;
 
      while(list_ob[i]) {
           if(list_stat[i]=="<<ON>>") move_object (list_ob[i],dest);
           i+=1;
          }
}
 
kick_out(ob) {move_object(ob,"room/church");}

