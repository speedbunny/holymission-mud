inherit "room/room";
object scar;

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "Scarlet's Scent-O-Rama!";
  long_desc =
"A small gnome stands near a stool located in the rear of a small shop. "
"Along the wall, rows of small bottles rest on wooden shelves. A sign hangs "
"above them.\n";
  smell = "You smell a large variety of perfumes and colognes";
  items = ({ "stool", "A small stool that looks big enough for Scarlet "+
		"to use as a ladder",
	"wall", "Shelves line the walls",
	"bottles", "Small bottles shaped and colored differently",
	"shelves", "Ordinardy wooden shelves",
	"sign", "A large sign... maybe you should read it" });
  dest_dir = ({
               "room/narr_alley", "west",
               "/players/meecham/pot_shops/ps_town","up",
             });
  property = ({ "no_fight" });

if(!present("scarlet", this_object())){
  scar = clone_object("obj/monster");
  scar-> set_name("scarlet");
  scar-> set_alt_name("gnome");
  scar-> set_level(10);
  scar-> set_hp(10000);
  scar-> set_gender(2);
  scar-> set_size(2);
  scar-> set_short("Scarlet the gnome");  
  scar-> set_long("Scarlet is a small little gnome with a bright smile and "+
		"shining eyes.\n");
  scar-> set_ac(50);
  move_object(scar, this_object());
  }

}

init() { 
  ::init();
  add_action ("order", "order"); 
  add_action ("order", "buy"); 
  add_action ("read", "read"); 
}
 
int read(string str) {
  if(str == "sign" || str == "symbols" || str == "strange sign") {
   write("*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n\n");
   write("             Scarlet's Scent-O-Rama!                 \n\n");
   write("     We have the following scents for ladies:        \n");
   write(" 'Wild Flower' 'Untamed Passion' 'Midnight Kiss'     \n");
   write("     and the following scents for gentlemen:         \n");
   write("   'Power Musk' 'Thunder Heart' 'Tender Foot'        \n");
   write("         All cost 100 coins per spray.               \n");
   write("            Just type: buy <scent>                   \n");
   write("*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n\n");
   return 1;
   }
}

int order(string str){
 string name;
 int value;
  
 value = 100;

if(!str){
  notify_fail("What scent did you wish?\n");
  return 0; 
  }

if(call_other(this_player(), "query_money", 0) < value){
  notify_fail("That would cost you "+value+" which you don't have.\n");
  return 0;     
  }

if(str == "wild" || str == "flower" || str == "wild flower") {
  if (this_player()->query_gender()== 1) { 
     notify_fail("This scent is not for you.\n");
     return 0; 
     }  
  write("Scarlet gives you a quick spray of Wild Flower perfume.\n");
  say(call_other(this_player(), "query_name", 0)+" gets a quick spray of Wild Flower perfume.\n");
  call_other(this_player(), "add_money", - value);
  this_player()->set_smell("You detect the mild scent of Wild Flower perfume.");
  return 1;
  }

else if (str == "untamed" || str == "passion" || str == "untamed passion") {
  if(this_player()->query_gender()== 1){
    notify_fail("This scent is not for you.\n");  
    return 0; 
    }
  write("Scarlet gives you a quick spray of Untamed Passion perfume.\n");
  say(call_other(this_player(), "query_name", 0)+" gets a quick spray of Untamed Passion perfume.\n");
  call_other(this_player(), "add_money", - value);
  this_player()->set_smell("You detect the mild scent of Untamed Passion perfume.");
  return 1;
  }
else if (str == "midnight" || str == "kiss" || str == "midnight kiss") {
  if(this_player()->query_gender()== 1){
    notify_fail("This scent is not for you.\n");
    return 0; 
    }
  write("Scarlet gives you a quick spray of Midnight Kiss perfume.\n");
  say(call_other(this_player(), "query_name", 0)+" gets a quick spray of Midnight Kiss perfume.\n");
  call_other(this_player(), "add_money", - value);
  this_player()->set_smell("You detect the mild scent of Midnight Kiss perfume.");
  return 1;
  }
else if (str == "power" || str == "musk" || str == "power musk") {
  if(this_player()->query_gender()== 2){
    notify_fail("This scent is not for you.\n");
    return 0; 
    }
  write("Scarlet gives you a quick spray of Power Musk cologne.\n");
  say(call_other(this_player(), "query_name", 0)+" gets a quick spray of Power Musk cologne.\n");
  call_other(this_player(), "add_money", - value);
  this_player()->set_smell("You detect the mild scent of Power Musk cologne.");
  return 1;
  }
else if (str == "thunder" || str == "heart" || str == "thunder heart") {
  if(this_player()->query_gender()== 2){
    notify_fail("This scent is not for you.\n");
    return 0; 
    }
  write("Scarlet gives you a quick spray of Thunder Heart cologne.\n");
  say(call_other(this_player(), "query_name", 0)+" gets a quick spray of Thunder Heart cologne.\n");
  call_other(this_player(), "add_money", - value);
  this_player()->set_smell("You detect the mild scent of Thunder Heart cologne.");
  return 1;
  } 
else if (str == "tender" || str == "foot" || str == "tender foot") {
  if(this_player()->query_gender()== 2){
    notify_fail("This scent is not for you.\n");
    return 0;  
    }
  write("Scarlet gives you a quick spray of Tender Foot cologne.\n");
  say(call_other(this_player(), "query_name", 0)+" gets a quick spray of Tender Foot cologne.\n");
  call_other(this_player(), "add_money", - value);
  this_player()->set_smell("You detect the mild scent of Tender Foot cologne.");
  return 1; 
  }
else{
  notify_fail("Scarlet doesn't seem to have the scent you desire.\n");
  notify_fail("Maybe a quick note to Airborne will get it for you.\n");
  return 0;
  }
 
}

