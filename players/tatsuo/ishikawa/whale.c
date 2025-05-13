inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

object pep, ladder, man, coin;
int propped, up;

void reset(int flag)
{
    if (flag == 0) 
    {
	set_light(-1);
	man=CO("/players/tatsuo/ishikawa/monsters/man");
	move_object(man, this_object());
	coin=CO("/obj/money");
	coin->set_money(23);
	move_object(coin, this_object());
	up=1;
	short_desc="Inside a whale.";
	long_desc = break_string(
	  "ACK! This place reeks of decay. You are inside "+
	  "a particularly large whale.  The 'floor' is slimy and "+
	  "difficult to walk on.  It appears that you are not the first "+
	  "to find your way in here.  There is a large pile of "+
	  "debris here, consisting of bones, various parts of ships,"+
	  " gold coins, seaweed, and other miscellaneous junk. "+
	  "Nothing particularly interesting on the surface of "+
	  "the pile, but maybe you could dig through it."+
	  " There appears to be no exits out of here.  There is a "+
	  "small blowhole making a sort of wheezing sound now and "+
	  " then.  Any attempts to force the mouth open have met with "+
	  "failure, as testified by the desparate looking corpses "+
	  "strewn about the pile.\n",64);

	items=({"whale","You can only see the inside",
	  "pile","A large pile of debris, nothing particulary interesting\n"+
	  "on the surface of the pile",
	  "blowhole","The breathing hole of the whale.  It is much too small\n"+
	  "to hope to climb through",
	  "mouth","It is closed and very big",
	  "sun","AAARRRGGGHHH, YOU BURN YOUR RETINA!!",
	  "sand", "It is a sickly greyish black reminding you of decaying flesh",
	  "ocean","A lot of water.",
	});
	smell = "The stench here is utterly unbearable";

	property=({"no_teleport"});
    }
}

void init()
{
    ::init();
    AA("_search","search");
    AA("_prop","prop");
    AA("_prop","set");
    AA("_prop","move");
    AA("_sneeze","shake");
    AA("_sneeze","sprikle");
    AA("_sneeze","put");
    AA("_sneeze","blow");
    AA("_climb","climb");
    AA("_squeeze","squeeze");
    AA("in_it","enter");
}
/*
_search(str){
  if(!str){
   write("Search what?\n");
   return 1;
  }
  if(str=="pile" || str=="debris"){
   if(!present("/players/tatsuo/ishikawa/obj/pepper",TP)){
  pep=CO("/players/tatsuo/ishikawa/obj/pepper");
  move_object(pep, TP);
   write("You search around the debris for a while and find a pepper shaker.\n");
   say(TPN+" searchs around the debris for a while.\n");
  return 1;
  }
  else return 0;
  }
}
*/
_search(str){
    if(!str){
	write("Search what?");
	return 1;
    }
    if(str=="room" || str=="whale"){
	write("You find a big pile of debris.\n");
	return 1;
    }
    if(str="pile" || str="debris"){
	if(TP->query_int()<random(11)*3){
	    write("You dig through the pile and find nothing useful.\n");
	    say(TPN+" searches through the pile for a while.\n");
	    return 1;
	}
	else{
	    string pile;
	    pile= PILE[random(sizeof(PILE)-1)];
	    if(present(pile,TP)){
		has_it();
		return 1;
	    }
	    if(!present(pile,TP)){
		write("You search through the pile, and find a "+pile+".\n");
		say(TPN+" searches through the pile and finds something.\n");
                transfer(CO(ISHOB+pile),TP);
/* used tranfer to player, stop infinite objects */
		return 1;
	    }
	}
    }
}
/*
_prop(str){
   if(!propped){
  if(str=="ladder" || str=="ladder against wall" || str=="ladder to blowhole"){
   propped=1;
   write("You prop the ladder against the wall, near the blowhole.\n");
   return 1;
   }
   if(propped>0){
   write("The ladder is already in place.\n");
   return 1;
   }
}
   else {
   write("You want to do what?\n");
   return 1;
   }
 }
*/
_sneeze(str){
    if(up==1){
	if(present("pepper", TP)){
	    if(str=="pepper" || str=="pepper into blowhole" || str == "pepper in blowhole"){
		write("You reach out with the pepper shaker and shake some pepper into\n");
		write("the blowhole.\n");
		call_out("msg1",4);
		call_out("msg2",8);
		call_out("msg3",12);
		call_out("msg4",16);
		/*
		   up=0;
		  propped=0;
		*/
		return 1;
	    }
	}
    }
    if(up==0){
	if(present("pepper", TP)){
	    if(str=="pepper" || str=="pepper into blowhole"){
		write("You can't reach the hole from here.\n");
		return 1;
	    }
	    return 1;
	}
    }
}
/*
_climb(str){
if(str=="into blowhole") in_it();
 if(propped==0){
  write("You can't climb the ladder its lying on the floor.\n");
  return 1;
  }
  if(up==0){
   if(str=="ladder" || str=="up"){
    write("You climb up the ladder.\n");
    say(TPN+" climbs up the ladder.\n");
    up=1;
    return 1;
    }
}
  if(up==1){
     if(str=="ladder" || str==up){
     write("There is already someone on the ladder.\n");
     return 1;
     }
}
     if(str=="down" || str=="down ladder"){
     write("You climb down the ladder.\n");
     say(TPN+" climbs down the ladder.\n");
     up=0;
     return 1;
     }
else return 0;
   }
*/
msg1(){
    write("You feel a tremor under your feet!\n");
    say("You feel a tremor under your feet!\n");
    return 1;
}
msg2(){
    write("The wheezing sound from the blowhole grows louder!\n");
    say("The wheezing sound from the blowhole grows louder!\n");
    return 1;
}
msg3(){
    write("AAAAAAAAAAAAAAAACCCCCCHHHHHHOOOOOOOOOOOoooooooooo.........\n");
    say("AAAAAAAAAAAAAACCCCCCCCCCCCCCHHHHHHHHHHHHHOOOOOOOoooooooooo....\n");
    return 1;
}
msg4(){
    write("\n\n\nYou fly over the island and crash down through the canopy\n");
    write("of the jungle.  Luckily you are not hurt too badly.\n");
    say("The whale bellows forth a tremendous sneeze and "+TPN+" is \n"+
      "thrown out of the whale! Luckily you manage to hold on to something.\n");
    TP->misc_hit(20,2,0);
    MOVE("violently out with the sneeze#players/tatsuo/ishikawa/jungle/jung133");
    return;
}
has_it(){
    write("You search the huge pile for a while, nothing interesting.\n");
    say(TPN+" pokes around the pile for a while.\n");
    return 1;
}
in_it(){
    write("The blowhole is much too small.\n");
    return 1;
}
