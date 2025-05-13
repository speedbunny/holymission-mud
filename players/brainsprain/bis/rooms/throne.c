inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

int dg(string arg){
  object money;
  object staff;
  if(!arg || arg != "staff to count"){
    write("Give what to whom.\n");
    return 1;
  }
  else if(!present("count")){
    write("The count is not here to give it to.\n");
    return 1;
  }
  else if(!present("#QSTAFF#",this_player())){
    write("You do not have the staff of light!\n");
    return 1;
  }
  else {
    staff = present("#QSTAFF#",this_player());
    destruct(staff);
    write("The count breaks down in tears and thanks you.\n"+
	  "Count Bismarck says: Here is your 10000 coins.\n");
    money = clone_object("obj/money");
    money->set_money(10000);
    move_object(money,this_player());
    this_player()->finish_quest("stlight");
    return 1;
  }
}

void reset(int arg) {
  clone_list = ({ 1, 1, "jester", bm+"/jester.c", 0,
		  1, 1, "chamberlain", bm+"/chamberlain.c", 0,
		  1, 1, "king", bm+"/king.c", 0,
  });     
  ::reset(arg);
  if(arg) return;
  
  short_desc = "Throne Room";
  long_desc =
    "A throne sits on a raised dias at the southern end of the room.  A gold "+
    "and silver carpet goes down the length of the room.  The walls of this "+
    "room are pure marble and are inscribed with the rules of the kingdom.\n";
  set_light(1);
  items = ({
    "walls",
    "They are made of pure marble",
    "throne",
    "Count Bismarck's throne",
    "count",
    "Count Bismarck",
    "bismarck",
    "The family name of the ruling family",
    "dias",
    "The throne rest us a raised dias",
    "room",
    "The throne room",
    "carpet",
    "It is intricately woven of gold and silver threads",
   });
  dest_dir = ({
    br+"/e-2.c","northeast",
    br+"/w-2.c","northwest",
  });
}


void init(){
  ::init();
  add_action("dg","give");
}
