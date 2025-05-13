inherit "obj/monster";

reset(arg){
::reset(arg);
if(arg) return;
set_name("dwarf");
set_alias("hendle");
set_short("Hendle the clerk");
set_long(
"This is Hendle the clerk. He works here to inform new visitors on\n"+
"some of Rama's attractions. He wears spectacles and a scribbles on\n"+
"his scroll, ignoring you. While he works he mumbles something about\n"+
"Moria to himself.\n");
set_race("dwarf");
set_size(2);
set_level(1);
set_hp(5000000);
set_gender(1);
}

init(){
::init();
add_action("give_map", "request");
}

give_map(str){
if(!str || str!="map"){
