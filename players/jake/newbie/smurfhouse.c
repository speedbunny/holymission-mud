inherit "room/room";
object grump;
string chats;
  get_chats(){
   if(!chats){
 chats=allocate(3);
 chats[0]="Grouchy smurf says: What the hell do you want?\n";
 chats[1]="Grouchy smurf says: F*@! OFF!\n";
 chats[2]="Grouchy smurf says: Smurfette is a slut!\n";
}
return chats;
}
reset (arg) {
if(!grump) {
grump=clone_object("obj/monster");
grump->set_name("grouchy smurf");
grump->set_short("grouchy smurf"); 
grump->set_alias("smurf");
grump->set_long("This is Grouchy Smurf.\nHe hates everything.\n");
grump->set_level(5);
grump->set_align(-10);
grump->chat_head("Grouchy smurf says: What the hell do you want?","Grouchy smurf says: Smurfette is a slut!");
grump->chat_chance(50);
grump->set_aggressive(1);
grump->add_money(100); 
move_object(grump,this_object());
}
if (arg) return;
set_light(3); 
short_desc = "smurfhouse";
long_desc = "You have entered a rather gloomy looking house.\n"
+  "This is Grouchy Smurf's house.  He likes it gloomy.\n"
+  "The house is pretty much empty because he hates everything.\n"
+  "There is a cot in the eastern corner of the house.\n";
items =
({"cot","A wooden cot"});
dest_dir =
({"players/jake/newbie/smurf2","south",
"players/jake/newbie/base","down"});
}
