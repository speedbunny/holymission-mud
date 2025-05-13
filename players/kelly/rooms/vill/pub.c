#define TP	this_player()
inherit "room/bars";
reset(arg) {
  stock = ({ 0, 0, 0, 0, 0, 0, 0, });
  ::reset(arg);
  if(arg) return;
  set_light(1);
short_desc="Village Pub.";
long_desc=
"You are in the local village pub.  There are a number of tables\n"+
"and chairs here.  The floor is scuffed and worn which makes it \n"+
"seem like there are usually many people in here although it\n"+
"looks pretty empty right now.  There is a sign on the wall\n";
  dest_dir=({
    "players/kelly/rooms/vill/road2","east",
  });
  items=({
    "sign","It's written in the common language, try to read it",
    "tables","Many tables are scattered about the room",
    "chairs","Wooden chairs line the tables",
  });
  menu_title="The menu of the pub:\n"+
             "--------------------\n";
  menu_desc=({
   ({ "beer","A bottle of beer",2,5,1,
             "Well, not bad.\n" }),
   ({ "scotch","A glass of Scotch",15,50,1,
             "Gosh ! Cool 'ey.\n" }),
   ({ "vino","Vino santo",50,300,1,
             "Really a holy wine.\n" }),
   ({ "juice","Orange juice",10,75,2,
	     "The juice refreshes you and clears your mind.\n" }),
   ({ "soda","A soda water",1,3,2,
	     "Tastes like nothing.\n" }),
   ({ "toast","A toast",10,80,0,
	    "Real good toast, maybe one more?\n" }),
   ({ "steak","A beaf-steak",20,180,0,
	      "Hey, real beef.\n" }),
             });
}
init() {
  ::init();
  add_action("read","read");
}
read(str) {
  if(str=="sign") {
    menu();
    return 1;
  }
}
