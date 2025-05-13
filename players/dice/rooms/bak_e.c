inherit "room/room";
object cook;
object bread,ob,ob2;
int has_opened;
reset(arg){
  if(!cook){
    cook=clone_object("/players/dice/obj/cook");
    move_object(cook,this_object());
    has_opened = 0;
  }



  set_light(1);
  no_castle_flag = 1;

  short_desc = "Bakery cooking place";
  long_desc =
    "This is the cooking place of Big Mama.\n"+
      "The place is covered with flour brought here by Hobbe.\n"+
	"The oven is built in a wall in front of you.\n";

  dest_dir = ({
    "players/dice/rooms/bak","west",
  });
  items =({
    "oven","An oven usually used to make bread",
    "flour","Flour brought here by Hobbe"
    });


  smell = "Here the smell of fresh bread is the strongest.\n";

}

init(){
  ::init();
  add_action("open_oven","open"); add_action("close_oven","close");
  add_action("enter_oven","enter");
}

open_oven(str){
  if(!str){
    notify_fail("Open what ?\n");
    return 0;
  }
  if(str=="oven"){
    if(has_opened == 1){
      notify_fail("It's already open.\n");
      return 0;
    }
    write("You open the oven.\n");
    say(this_player()->query_name()+" opens the oven.\n");
    has_opened = 1;
    return 1;
  }
}

close_oven(str){
  if(!str){
    notify_fail("Close what ?\n");
    return 0;
  }
  if(str=="oven"){
    if(has_opened == 0){
      notify_fail("It's not open.\n");
      return 0;
    }
    write("You close the oven.\n");
    say(this_player()->query_name()+" closes the oven.\n");
    has_opened = 0;
    return 1;
  }
}

enter_oven(str){
  if(!str){
    notify_fail("Enter what ?\n");
    return 0;
  }
  if(str=="oven"){
    if(has_opened == 0){
      notify_fail("You can't do that, the oven is not open.\n");
      return 0; }
    write("You step into the oven.\n");
    this_player()->move_player("into the oven#players/dice/bread/oven");
    return 1;
  }
}


get_bread(str){
  if(!str){
    notify_fail("Get what ?\n");
    return 0;
  }
  if(str=="bread from oven"){
    if (has_opened == 0){
      notify_fail("The oven is not open\n");
      return 0;
    }
    ob=find_object("players/dice/bread/oven");
    if(!ob||!present("bread", ob)){ 
      write("There is no bread in the oven\n");
      return 1;
    }
    else{
      write("You take some bread from the oven\n");
      bread = clone_object ("players/dice/bread/bread");
      move_object(bread,this_player());
      return 1;
    }
  }
}
