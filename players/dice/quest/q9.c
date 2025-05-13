inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    property = "no_teleport";
    short_desc = "Surface";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
             "You have climbed out of the hole and you finally\n"+
             "stop inhaling the noxious smell of sulphur.\n"+
             "You are standing on the backside of the volcano,\n"+
             "and see a slight cloud of smoke coming from it's top.\n"+
             "You can breathe again.\n"+
             "Some bushes stand to the north.\n";
          items = ({
                    "hole","A small hole to a cave underneath the earth",
                    "smell","It's not that bad here",
                    "backside","The backside of the volcano",
                    "volcano","A small volcano",
                    "smoke","A small cloud of smoke coming from the volcano",
                     "bushes","Some small passable bushes",
                    "cloud","A small cloud of smoke coming from the volcano",
                    "top","It seems unreachable",
              });

    smell = "The air is really fresh here.";
}
init(){  
    ::init(); 
 add_action("breathe_air","breathe");
 add_action("enter_hole","enter"); add_action("do_down","down");
  add_action("pass_bushes","pass"); add_action("do_north","north");
  add_action("do_north","n");
 }
breathe_air(str){
  if(!str){
  notify_fail("Breathe what ?\n");
  return 0;
  }
if(str=="air"){
  write("You take a deep breath and fill your lungs with the fresh air.\n");
  return 1;
  }
if(str=="smoke"){
  write("UCH\n"+
       "UGH\n\n\n\n"+
       "Your lungs fill with smoke and you nearly choke to death.\n");
        this_player()->hit_player(15,3);
       return 1;
       }
    }
enter_hole(str){
  if(!str){
  notify_fail("Enter what ?\n");
  return 0;
  }
if(str=="hole"){
  this_player()->move_player("into the hole#players/dice/quest/q8a");
  return 1;
  }
 }
pass_bushes(str){
  if(!str){
  notify_fail("Pass what ?\n");
  return 0;
  }
if(str=="bushes"){
  write("You wiggle through the bushes.\n");
  this_player()->move_player("through the bushes#players/dice/quest/q10");
  return 1;
  }
 }
do_north(){
  write("You bump into the bushes, next time be more careful.\n");
  return 1;
  }
do_down(){
this_player()->move_player("down#players/dice/quest/q8");
return 1;
}
