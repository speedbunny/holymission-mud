inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    property = "no_teleport";
    short_desc = "House";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
              "You have wiggled through the bushes and see a\n"+
              "small house standing here in the meadow.\n";
          items = ({
                     "bushes","A rosebush, with sharp thorns",
     "house","A small house, the owner must be a small guy",
                     "small house","Maybe you can enter it",
                    "owner","He is not here right now",
                     "meadow","A beautiful green meadow",
              });

    smell = "The air is fresh here.";
}
init(){  
    ::init(); 
 add_action("enter_house","enter"); add_action("pass_bushes","pass");
 }
enter_house(str){
  if(!str){
  notfy_fail("Enter what ?\n");
  return 0;
  }
if((str=="house")||(str=="small house")){
  write("You walk up to the door, open it, and step into the house.\n");
  this_player()->move_player("into the house#players/dice/quest/q11");
  return 1;
  }
 }
pass_bushes(str){
 if(!str){
  notify_fail("Pass what ?\n");
  return 0;
  }
if(str=="bushes"){
  write("You try to wiggle through the bushes.\n"+
        "You didn't see the thorns that were on this\n"+
         "side of the bushes.\n");
  this_player()->hit_player(20,3);
  return 1;
  }
 }
