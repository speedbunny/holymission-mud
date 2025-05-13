inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Complete newbie area";
   long_desc = 
"    Now you are almost ready to face battle. Before you do however, "+
"you will need to have a weapon and some armour. No good adventurer would "+
"be caught without them!\n"+
"    Here you will be able to conjure a weapon and armour in case you did "+
"not bring any with you. Just type 'conjure weapon' or 'conjure armour'. "+
"And once you have it, you must be able to use it. All armours must "+
"be worn and all weapons must be wielded to be of any use. "+
"The commands are wear <armour> and wield <weapon> individually, and "+
"'powerup' will wield the weapon and wear all armours.\n\n"+
"      When you are ready, exit lesson 9.\n";

  property = ({"no_tport_in","no_tport_out","no_steal"});
  no_obvious_msg = "";
	}
}
init(){
::init();

  add_action("conjure", "conjure");   add_action("leave", "leave");
  add_action("next", "lesson");
	}
leave(){
  write("You stop the newbie lessons.\n");
  write("Send mail to Airborne with any comments or suggestions.\n");
	this_player()->move_player("after stopping the lessons#players/airborne/new/station");
 	  return 1; }

next(str){
  if(!str){
	write("What lesson?\n");
	return 1; }
  if(str=="9"){
	write("You leave to the next lesson.\n");
	this_player()->move_player("lesson 9#players/airborne/new/bar");
	return 1; }
  else {
	write("You are not ready for that lesson yet.\n");
	return 1; }
	}
conjure(str){
  if(str=="weapon"){
   object wep;
	if(present("sword", this_player())){
		write("You already have that!\n");
		return 1; }
		wep=clone_object("obj/weapon");
		wep->set_name("sword");
		wep->set_short("a sword");
		wep->set_long("A newbie sword.\n");
		wep->set_class(4);
		wep->set_value(5);
		wep->set_weight(1);
           transfer(wep, this_player());
 	   write("A sword suddenly appears!\n");
		return 1; }
  if(str=="armour"){
    object arm;
	if(present("armour", this_player())){
		write("You already have that!\n");
		return 1; }
		arm=clone_object("obj/armour");
		arm->set_type("armour");
		arm->set_name("Padded armour");
		arm->set_weight(1);
		arm->set_ac(1);
		arm->set_alt_name("padded armour");
		arm->set_value(5);
		arm->set_short("Padded armour");
		arm->set_long("Newbie padded armour.\n");
	transfer(arm, this_player());
	   write("Padded armour suddenly appears!\n");	
		return 1; }
   else {
	write("Conjure what?\n");
	return 1; }
}
