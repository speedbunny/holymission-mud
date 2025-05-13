inherit "obj/thing";
void reset(int arg){
::reset(arg);
if(arg) return;
set_name("Dark Crystal");
set_alias("crystal");
set_long("This is a peice of the Great Crystal of Power, that gave the "+
         "the summoners there power. When the summoner war was ended the "+
         "crystal was shattered and never seen again. Legends said that "+
         "the crystal gave off its own light, and power flowed from it. "+
         "When the guild was destroyed, the crystal grew cold. You can "+
         "almost feel it draining your energy.\n");
set_weight(1);
set_value(5000);
}
init(){
::init();
add_action("block","cast");
}
block(arg){
if(query_verb()=="cast"){
this_player()->restore_spell_points(-(this_player()->query_sp()/2));
write("The crystal steals the energy form your spell. You feel drained.\n");
say(this_player()->query_name()+"'s crystal steals the energy from the spell.\n");
return 1;
}
}
