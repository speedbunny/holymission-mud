

do_force(action){
    string name,nothing;
int SP_COST;
  SP_COST = 150 - (this_player()->query_level());
  sscanf(action,"%s %s",name,what) == 2 ||
  sscanf(action,"%s to %s",name,what) == 2;
    if(!name){
  write("Control who???\n");
        return 1;
    }
    victem = find_player(name);
    if(!victem){
        write(capitalize(name)+" was not found,\n");
    }
    else{
        if(victem==this_player()){
    write("You can do the task without forcing yourself!\n");
            return 1;
        }
 }
        if(victem->query_level()<30)
          write(capitalize(name)+" is under your control!\n");
        else{
            write(capitalize(name)+" is a wizard, and may not be "+
                  "controlled!\n");
            victem = 0;
  return 1;
        }
    name = capitalize(victem->query_real_name());
    if(what=="quit"
       ||sscanf(what,"drop %s",nothing)==1
       ||sscanf(what,"give %s",nothing)==1){
   write("Not even you can master anothers mind that way!\n");
        return 1;
    }
    if(this_player()->query_spell_points()>=SP_COST){
     say(name+ "is being controlled!\n");
    command(what,victem);
    write("You commanded "+name+" to "+what+"\n");
   this_player()->add_spell_points(-SP_COST);
    }
    else
      write("You are too drained to accomplish the deed.\n");
    return 1;
}

