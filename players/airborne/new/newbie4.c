inherit "room/room";
object torch;

reset(arg){
 if(!arg){
   set_light(1);
   short_desc = "Complete newbie area";
   long_desc = 
"    The next command we will look at will be the 'get' or 'take' command. "+
"Both commands do the same thing, it is up to you to decide which you would "+
"rather use.\n"+
"    The 'get' command works to pick things up. When you enter a room and "+
"see an item, you can 'get <item>'. For instance, when you entered this room "+
"you probably noticed a torch. To get the torch you would type, 'get torch' "+
"and the torch would appear in your inventory.\n"+
"    Sometimes items appear inside of containers, like in a chest or bag. To "+
"get the item you need to say where you are getting it from. You would use "+
"the command like this: get <item> from <location>. How example, if there "+
"were a ring inside a bag that you wanted to get you would type, 'get ring "+
"from bag'.\n"+
"    If there is more than one item, and you wish to get all of them "+
"you may want to use 'get all' instead of listing each item seperately. " +
"Sometimes you want to get the second item only. The command is get item 2. " +
"Also, after you kill a monster, don't forget to 'get all from corpse' "+
"so that you can reap the spoils of combat.\n\n"+
"     After you get the torch, exit lesson 4.\n";

   no_obvious_msg = "";
   items = ({"chest", "There is no chest in this lesson",
	"bag", "There is no bag in this lesson",
	"ring", "There is no ring in this lesson", });
  property = ({"no_teleport", "no_steal", "no_sneak"});
	if(!present("torch", this_object())){
		torch=clone_object("players/airborne/obj/fake_torch");
		move_object(torch, this_object());
		return  ; }
	

	return 1; }
	}

init(){
::init();

 add_action("leave", "leave");
 add_action("next", "lesson");
 add_action("get_it", "get");
 add_action("no_drop", "drop");
 add_action("get_it", "take");
	}
next(str){

 if(!str){
	write("What lesson?\n");
	return 1; }
 if(str=="4"){
	write("You move on to lesson 4.\n");
     this_player()->move_player("lesson 4#players/airborne/new/newbie5");
	return 1; }
 else {
	write("You are not ready for that lesson yet.\n");
	return 1; }
	}
leave(){
   write("You stop the newbie lessons.\n");
   write("Please mail Airborne with any comments or suggestions.\n");
   this_player()->move_player("after stopping the lessons#players/airborne/new/station");
	return 1; }

get_it(str){
object ob;

 if(str != "torch"){ return 0; }
 else {
	if(!present("torch", this_player())){
   ob = clone_object("obj/torch");
   transfer(ob, this_player());
   write("You get a torch.\n");
   return 1; }
  else {
	write("Please leave a torch for a fellow newbie.\n");
	return 0; }
}
}
no_drop(){ return 1; }
