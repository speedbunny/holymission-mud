inherit "room/room";
object policeman,club,woman,ring;
status pressed;
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="Guard room";
long_desc=
"You are in the guard room of the police station.  this is where \n"+
"guards sit and watch to make sure that there are no breakouts.\n"+
"there are a couple of people sitting near a desk.  To the west\n"+
"is a door which leads out of the station.\n";
    dest_dir=({
    "players/kelly/rooms/vill/corridor3","east",
    "players/kelly/rooms/vill/backpolice","west",
   });
   items=({
   "corridor","A dimly lit corridor, you can hear the crying of some prisoners",
   "desk","A wooden desk with many buttons on it",
   "buttons","There are less than you thought, they are numbered from 1 to 6",
   "button","If you want to press one try a number",
   "door","A wooden door without a lock",
   "opening","Just an opening in the wall",
   });
   policeman=clone_object("obj/monster");
   policeman->set_name("policeman");
   policeman->set_alias("man");
   policeman->set_ac(5);
   policeman->set_size(3);
   policeman->set_level(10);
   policeman->set_al(50);
   policeman->set_male();
   policeman->set_short("A policeman");
   policeman->set_long("A policeman, you see nothing special about him.\n");
   club=clone_object("obj/weapon");
   club->set_name("club");
   club->set_class(10);
   club->set_weight(2);
   club->set_short("A club");
   club->set_long("A wooden club, with some letter on it.\n");
   club->set_read("Property of the police Red Rock Junction.\n");
   move_object(club,policeman);
   policeman->init_command("wield club");
   move_object(policeman,this_object());
   woman=clone_object("obj/monster");
   woman->set_name("policewoman");
   woman->set_alias("woman"); 
   woman->set_short("A policewoman");
   woman->set_long("Wow!  What a woman! she's a sexy looking blond.  You ask yourself why she \nbecame a policewoman and not a model.  She really loos great.\n");
   woman->set_female();
   woman->set_level(17);
   woman->set_size(3);
   woman->set_race("human");
   woman->set_wc(16);
   woman->set_spell_mess1("The policewoman places a solid blow."); 
   woman->set_spell_mess2("The policewoman places a solid blow to your chest.She knows what she does.");
   woman->set_spell_dam(50);
   woman->set_chance(20);
   ring=clone_object("obj/armour");
   ring->set_name("ring");
   ring->set_type("ring");
   ring->set_size(2);
   ring->set_short("A golden ring");
   ring->set_long("A lovely golden ring with a engraving on the inner side saying:\nFor my loving Harry.\n");
   ring->set_ac(1);
   ring->set_weight(1);
   ring->set_value(150);
   move_object(ring,woman);
   woman->init_command("wear ring");
   move_object(woman,this_object());
   pressed = allocate(6); 
}
init() {
::init();
  add_action("press","press");
}
press(str) {
  int nr;
  string what;
if(!str){
write("Press what?\n");
return 1;
}
  if(sscanf(str,"%s %d",what,nr)!=2) return;
if(what !="button" ) {
write("There is no "+ what +" to press!\n");
return 1;
}
  if(nr<1 || nr>6) {
    write("There isn't such a button.\n");
    return 1;
  }
  if(present("policeman",this_object())) {
    write("The policeman doesn't let you do that.\n");
    return 1;
  }
  pressed[nr-1]=!pressed[nr-1];
  write("You press button number "+nr+".\n");
  say(this_player()->query_name()+" presses button number "+nr+".\n");
  return 1;
}
open(i) {
  return pressed[i-1];
}
