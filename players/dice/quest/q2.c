inherit "room/room";
object e_spirit;
string tomb_desc;
int open_tomb;
 int has_killed;
reset(arg) {
 open_tomb = 0;
 has_killed = 0;
    if (arg) return;
    tomb_desc = "A place where the dead are put in.\nIt's closed";
    set_light(1);
    property = "no_teleport";
    short_desc = "Graveyard";
    no_castle_flag = 1;
    no_obvious_msg ="";
    long_desc = 
        "You have entered a graveyard. This is the place where the dead \n"+
        "are buried. Don't disturb their peace, you might regret it.\n"+
        "You see a few tombs standing here in disarray as if they \n"+
        "had been turned upside down when the spirits rose from their graves.\n";
          items = ({
              "graveyard","A place where the dead are buried",
              "graves","Places where the dead are buried",
              "gravetomb","@@query_tomb_desc@@",
 "tomb","@@query_tomb_desc@@",
  "gravetomb","@@query_tomb_desc@@",
               "gravetombs","Places where the dead are buried",
              "place","A scary place",
              "tombs","Places where the dead are buried",
              "dead","They are not walking around, they're dead",
               "spirits","They are not here now, you should not awake them",
              });

    smell = "The smell of rotting flesh is strong.";
}
init(){  
    ::init(); 
    add_action("disturb","disturb");
    add_action("disturb","awake");
    add_action("disturb","wake");
    add_action("enter_tombe","enter");
    add_action("op_tomb","open");
    add_action("cl_tomb","close");
   }
enter_tombe(str){
    if(!str){
     notify_fail("Enter what ?\n");
     return 0;
     }
if((str=="tomb")||(str=="gravetomb")||(str=="gravetombs")||(str=="graves")){
     if(open_tomb == 0){
      write("You can't enter the tomb, it's closed.\n");
     return 1;
     }
      else{
    write("You step into the tomb, and slide down into darkness.\n");
     this_player()->move_player("into the tomb#/players/dice/quest/q3");
     return 1;
     }
    }
   }
disturb(str){
    if(!str){
     notify_fail("Disturb who ??\n");
     return 0;
     }
     if ((str=="dead")||(str=="spirit")||(str=="spirits")){
  if(has_killed == 1){
 notify_fail("You make a loud noise, but nothing happens.\n");
  return 0;
    }
     if(!e_spirit){
     e_spirit =clone_object("/players/dice/obj/e_spirit");
     move_object(e_spirit,this_object());
     say(this_player()->query_name()+"makes a magical gesture.\n");
     write("You were warned not to disturb the dead !!\n"+
           "An evil spirit comes from his grave to look for the\n"+
           "one who woke him !!\n");
  has_killed = 1;
     return 1;
     }
  }
}
op_tomb(str){
  if(!str){
  notify_fail("Open what ?\n");
  return 0;
  }
if((str=="tomb")||(str=="gravetomb")||(str=="grave")){
 if(open_tomb == 1 ){
  notify_fail("It's already open.\n");
  return 0;
  }
   write("You open the tomb.\n");
 say(this_player()->query_name()+" opens a tomb.\n");
   open_tomb = 1;
   return 1;
   }
  }
cl_tomb(str){
 if(!str){
 notify_fail("Close what ?\n");
 return 0;
 }
 if(open_tomb == 0){
   write("The tomb is not open.\n");
 return 1;
 }
 else{
 write("You close the tomb.\n");
 say(this_player()->query_name()+" closes a tomb.\n");
 open_tomb = 0;
 return 1;
  }
 }
query_tomb_desc() {
 if (open_tomb == 1){
 return "A place where the dead are put in.\nIt's open";
 }
 else
 return tomb_desc;
}
