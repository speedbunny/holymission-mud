#define MAX_CONJURE 30
inherit "room/room";

int nconj;

reset(arg){
  nconj=1;
 if(!arg){

  set_light(1);
  short_desc = "Complete newbie area";
  long_desc =
"   Now you are all ready to fight, all that is missing is an opponent. "+
"Lucky for you, you are in the right place. If there are no monsters here "+
"just type 'conjure' and one will appear. You can conjure up to 7 different "+
"opponents just the right size for you to fight. \n"+
"   Then you just have to start the fight. You do that by typing 'kill "+
"<monster>'. Each monster has a different name so you have to say which "+
"monster you are killing. For example, if there were two monsters, a goat "+
"and a rabbit and you wanted to kill the rabbit, you would type 'kill "+
"rabbit'. \n"+
"    Now conjure a few monsters and enjoy. You will be able to move on to "+
"the next lesson after you have killed two monsters. But feel free to stay "+
"and kill a few more.\n\n"+"      There are two exits: lesson 11 and north\n";

  no_obvious_msg = "";

  property = ({ "no_tport_in", "no_tport_out", "no_steal" });

	}
}

init(){
 ::init();
  add_action("leave", "leave");  add_action("conjure", "conjure");
  add_action("next", "lesson");  add_action("wimpy", "n");
  add_action("wimpy", "north");  add_action("bar", "bar");
}

int leave(){
  write("You have stopped the lessons.\n");
  write("Please mail Airborne with any complaints or suggestions.\n");
  this_player()->move_player("after stopping the lessons#players/airborne/new/station");
  return 1; 
}

int bar(){
  this_player()->move_player("to the bar#players/airborne/new/bar");
  return 1; 
}

int wimpy(){
  this_player()->move_player("north#players/airborne/new/bar");
  return 1; 
}

next(str){
object x, y;

  if(!str){
    notify_fail("What lesson? \n");
    return 0; 
    }
  if(str=="11"){
   if((present("dead_a", this_player())) && (present("dead_b", this_player()))){
     write("You move on to the next lesson.\n");
     this_player()->move_player("lesson 11#players/airborne/new/newbie12");
	while(x=present("dead_a", this_player())){
		destruct(x); }
   	while(y=present("dead_b", this_player())){
		destruct(y); }
     return 1; 
     }
   else {
     notify_fail("You are not ready for that lesson yet.\n");
     return 0; 
     }
    }
  else {
    notify_fail("You are not ready for that lesson.\n");
    return 0; 
    }
}
conjure(){
 string type;
 object file;

 type = "none";

  if(!present("kitten", this_object())) type="kitten";
  if(!present("puppy", this_object())) type="puppy";
  if(!present("gopher", this_object())) type="gopher";
  if(!present("fox", this_object())) type="fox";
  if(!present("raccoon", this_object())) type="raccoon";
  if(!present("ferret", this_object())) type="ferret";
  if(!present("chipmunk", this_object())) type="chipmunk";
    if(type=="none"){
      notify_fail("Why not kill a few of the animals already here?\n");
      return 0; 
      }
    if(nconj > MAX_CONJURE){
      notify_fail("There are no more animals available.\n");
      return 0;
      }
     
  nconj++;

 file="players/airborne/new/monsters/"+type+".c";
 move_object(clone_object(file), this_object());
   write("You have conjured an animal -- it is a "+type+".\n");
   say("A "+type+" appears from out of nowhere!\n");
   return 1; 

}
