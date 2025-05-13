inherit "room/room";

string player;
int moves, *target, *puz, *fix;
int *changes_array=({ ({ 0,2 }) , ({ 1,4 }) , ({ 0,2,5 }) ,
	0, ({ 2,4 }) , ({ 1,3,4 }) });

reset(arg) {
  int i;
  if(arg) return;
  set_light(1);
  short_desc="By a door with a strange lock";
  long_desc="You are in a room with no exits at all. The only thing visible is a strange\n"
	+ "panel recessed in the walls, with lots of glowing numbers on it, and some\n"
	+ "buttons below the glowing numbers on it.\n";
  no_obvious_msg="";
  target=allocate(6);
  puz=allocate(6);
  for(i=0;i<6;i++) {
    target[i]=random(6);
    puz[i]=random(6);
  }
  fix="players/moonchild/gnome/temple"->random_array(6);
  property=({ "no_teleport" });
  items=({ "panel", "@@_display@@",
	"numbers", "@@_display@@",
	"buttons", "There are six of them",
	"button 1", "It's a button in the recessed panel",
	"button 2", "It's a button in the recessed panel",
	"button 3", "It's a button in the recessed panel",
	"button 4", "It's a button in the recessed panel",
	"button 5", "It's a button in the recessed panel",
	"button 6", "It's a button in the recessed panel" });
}

init() {
  ::init();
  add_action("push", "touch");
  add_action("push", "press");
  add_action("push", "push");
  if(this_player()->query_real_name()!=player
	&& this_player()->query_level()<33)
		move_object(this_player(), "room/church");
}

query_prevent_shadow() {
  return 1;
}

set_owner(str) {
  if(file_name(previous_object())!="players/moonchild/gnome/temple") return;
  player=str;
}

push(str) {
  int l,j,val;
  if(str=="button" || str=="buttons") {
    write("Which button? Try button 1 to button 6.\n");
    return 1;
  }
  if(!sscanf(str,"button %d",val)) return;
  if(moves++>100) {
    write("You feel an electric shock shooting through your body!\n");
    this_player()->hit_player(moves*4-400);
  }
  if(this_player()->query_ghost()) {
    write("Your hand passes stright through the button!\n");
    return 1;
  }
  val--;
  if(fix[val]==3) {
    j=puz[0];
    for(l=0;l<5;l++)
      puz[l]=puz[l+1];
    puz[5]=j;
    return check_finished();
  }
  return check_finished(changes_array[fix[val]]);
}

static check_finished(arg) {
  int loop,flag;
  write("You " + query_verb() + " the button.\n");
  write("Something changes on the display.\n");
  if(arg)
    for(loop=0;loop<sizeof(arg);loop++)
      if(++puz[arg[loop]]==6) puz[arg[loop]]=0;
  flag=0;
  for(loop=0;loop<6;loop++)
    if(puz[loop]!=target[loop])
      flag=1;
  if(!flag) {
    object new;
    write("You are suddenly flung into another room!\n");
    new=clone_object("players/moonchild/gnome/doors");
    new->set_owner(this_player()->query_real_name());
    this_player()->move_player("X#" + file_name(new));
    destruct(this_object());
    return 1;
  }
  return display();
}

static _display() {
  int i;
  string shit;
  shit="The panel now shows:\n\n--->>> ";
  for(i=0;i<6;i++)
    shit+=target[i];
  shit+=" <<<--- --->>> ";
  for(i=0;i<6;i++)
    shit+=puz[i];
  shit+=" <<<--- --->>> ";
  shit+=moves;
  shit+=" <<<---";
  return shit;
}

static display() {
  write(_display());
  write("\n");
  return 1;
}
