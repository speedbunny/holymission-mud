string arg,name,objname,split,filtered;
int itemno,counter;
object player,dummy;
	cleanup(arg) {
	name="";
	objname="";
	if(!arg) { 
		write("Cleanup what?\n");
		return 1;
		}
	split=explode(arg," ");
	filtered=split[sizeof(split)-1];
	itemno=to_int(filtered);
	if(itemno) split[sizeof(split)-1]=" ";
	name=split[0];
	split[0]=" ";
	
	filtered=filter_array(split,"filter",this_object());
	if(!itemno) itemno=1;
	objname=implode(filtered," ");	
	player=find_player(lower_case(name));

	if(!player) {
		write("That person isn`t logged on at the moment.\n");
		return 1;
	}
	if(!objname) {
		write("You need to input an object name!\n");
		return 1;
	}
	objname=lower_case(objname);
	counter=0;
	dummy=first_inventory(player);
	if(!dummy) {
		write("That doesnt have that object.\n");
		return 1;
		} 
	do {
		if(dummy->id(objname)) {
			counter++;
			if(itemno==counter) break;
		}	

	}
	while(dummy=next_inventory(dummy));
	if(counter==itemno) {
		destruct(dummy);
		write(capitalize(objname)+" has been destructed!\n");
		say("Electricity swirls around the fingers of "+capitalize(this_player()->query_short_name())+".\n");
		tell_object(player,"You suddenly feel as if you are carrying less than before.\n");
	} else {
		write(capitalize(objname)+" "+itemno+" does not exist!\n");
	}
	return 1;
}	
		
filter(arg) {
	if(arg==" ") return 0;
	return 1;
	}
