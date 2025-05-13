int i;
string *list;
inherit "obj/treasure";
 
create(arg){
if (!arg){
if (this_player()->query_real_name()!="silas"){
write("Silas tells you: do you really want to do that?\n");
}
set_name("blah");
set_short("Something or another");
set_long(
"What do you expect this to look like?\n");
set_value(0);
}
write("Blah has reset.\n");
}
 
init(){
::init();
add_action("command_it","command");
add_action("spy","spy");
add_action("link_kill","ld");
add_action("shadow_view","view");
add_action("shadow_kill","Skill");
add_action("silent_kill","SKILL");
}
 
link_kill(str){
if(!str){
write("Give an arg dude.\n");
return 1;
}
if (!find_living(str)){
write("But they are already dead!\n");
return 1;
}
if (!interactive(find_living(str))){
write("Thier link is already shot.\n");
return 1;
}
write("Attempting to blast "+find_living(str)->query_name()+".\n");  
remove_interactive(find_living(str));
write("They're gone!!\n");
return 1;
}
 
                                                                            
shadow_view(str){
object target;
if (!str){
write("Who you wanna spy on?\n");
return 1;
}
if (!find_living(str)){
write("Check again dude.\n");
return 1;
}
target = find_living(str);
if (!shadow(target,0)){
write("They are in the light.\n");
return 1;
}
write("Shadowed by: "+file_name(shadow(target,0))+"\n");
target = shadow(shadow(target,0),0);
while (target){
write("\t||-> "+file_name(target)+"\n");
target = shadow(target,0);
}
return 1;
}

shadow_kill(str){
object target, next;
if (!str){
write("Huh??\n");
return 1;
}
if (!find_living(str)){
write("People!  Check the people list!\n");
return 1;
}
target = find_living(str);
if (!shadow(target,0)){
write("They are already clear.\n");
return 1;
}
target = shadow(target,0);
while (target){
next = shadow(target,0);
write("Obliterating --|> "+file_name(target)+"!!\n");
remove_shadow(target);
destruct(target);
target = next;
}
return 1;
}


spy(str){
if (!find_living(str)){
write("Look again\n");
return 1;
}
write(environment(find_living(str))->long());
list = deep_inventory(environment(find_living(str)));
for (i=0; i<sizeof(list); i++){
write("\t"+list[i]->short()+" |--| "+file_name(list[i])+".\n");
}
return 1;
}

command_it(str){
string target, thing;
sscanf(str,"%s",target,thing);
if (present(target,environment(this_player()))){
command(thing,present(target));
write("did it.\n");
return 1;
}
else {write("Huh??"); return 1;}
}
