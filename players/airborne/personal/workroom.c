inherit "room/room";
int shield;

#define TP this_player()
#define CA capitalize
#define RN this_player()->query_real_name()

reset(arg){

 write("The statues say in unison: There has been a reset.\n");
 ::reset(arg);

 if(arg) return;

 set_light(1);
 short_desc = "Airborne's workroom";
 long_desc =
 " Welcome to the workroom of Airborne, otherwise known as Willie.\n"+
 "The hall opens into a long stone walled chamber.  Various shields "+
 "line the walls displaying the coat of arms of friend's to the "+
 "court.  Two identical stone statues stand at either side of a "+
 "large throne atop a marble pedestal at the far end of the hall. "+
 "A long plush carpet runs down the center of the hall with large "+
 "cushions on either side for the comfort of the guests.\n"+
 "     There are two obvious exits: church, post \n";

 no_obvious_msg = "";

 property = ({ "no_steal", "no_tport_in", "no_tport_out", "has_fire" });

 items = ({
  "stone", "Dark grey stone walls that are warm to the touch",
  "walls", "Dark grey stone walls that are warm to the touch",
  "statue",
  "A tall life like statue of a winged man. It almost looks intelegent",
  "statues", 
  "Twin life like statues of a winged man. They almost look intelegent",
  "pedestal",
  "A light grey and white colored marble floor",
  "marble",
  "A light grey and white colored marble floor",
  "throne",
  "A large comfortable throne. Must belong to Airborne",
  "carpet",
  "A nice thick carpet",
  });
}

init(){
 ::init();

 check();
 if(this_player()->query_invis()){
   this_player()->set_vis();
   write("The statues point to your invisible presence.\n");
   say("The winged statues say: "+CA(TP->query_name()) +
        " tried to enter undected.\n");
   return 1;
 }
  add_action("set_shield", "shield");
  add_action("stop_that", "tickle");
  add_action("church", "church");
  add_action("post", "post");
}

int set_shield(string str){

 if(RN!="airborne"){
  write("Only Airborne has power over such things here.\n");
  return 1;
  }
 else if(!str){
  write("The shield is currently set to "+ shield+ " .\n");
  return 1;
  }
 else if(str=="on"){
  write("You power up the fucken shield.\n");
  say("The statues say in unison: Fucken shield is on, buttmunch.\n");
  shield=1;
  return 1;
  }
 else if(str == "off"){
  write("You turn off the fucken shield.\n");
  say("The statues say in unison: Fucken shield is off, ok asshole?\n");
  shield=0;
  return 1;
  }
 else {
  write("Asphinctersayswhat?\n");
  return 1;
  }
}

int stop_that(string str){
 if(str == "airborne"){
   write("You think you're man enough?\n");
   write("Airborne takes you over his knee and administers a well deserved spanking.\n");
  say("Airborne takes "+ CA(RN)+" over his knee and administers \ a well deserved spanking.\n");
   return 1;
  }
}

check(){
 if(shield && RN!="airborne"){
  write("Airborne's workroom prevents your sorry ass from entering.\n");
  say(CA(TP->query_name())+" was kicked out.\n");
  move_player(TP, "far far away#/room/church");
  return 1;
 }
} 

church(){
 if(shield && RN!="airborne"){
   write("You are not allowed to leave with the shield on.\n");
   return 1;
 }
}

post(){
 if(shield && RN!="airborne"){
  write("you are not allowed to leave with the shield on.\n");
  return 1;
 }
}

