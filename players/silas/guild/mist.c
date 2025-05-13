string color="pink";
 

id(str) { return str == "mist";  }
 
short() { return "A "+color+" mist"; }
 
long() {
   write("This is a "+color+ " mist of safety.\n");
}
reset() {
  set_light(1);
}
 
init() {
   add_action("move","north");
   add_action("move","south");
   add_action("move","west");
   add_action("move","east");
   add_action("move","northeast");
   add_action("move","northwest");
   add_action("move","southeast");
   add_action("move","southwest");
   add_action("move","up");
   add_action("move","down");
   add_action("look_out","look");
   add_action("my_say","say");
   add_action("help_mist","help");
   add_action("my_say","say");
   enable_commands();
}
 
move(str) {
   int i;
   string dest_dir;
 
   dest_dir=environment()->query_room("dest_dir");
 
   if (environment(this_player()) == this_object())
   {
     if (!str) str =query_verb();
 
     i = 1;
     while ( i < sizeof (dest_dir)) {
        if (str== dest_dir[i]) {
           tell_room(environment(),this_object()->short()+" leaves "+dest_dir[i]+"\n");
           move_object(this_object(),dest_dir[i-1]);
           tell_room(environment(),this_object()->short()+" arrives.\n");
           look_out("out");
           return 1;
        }
        i+=2;
     }
     write("You can't go that way.\n");
  }
  return 1;
}
 
look_out(str) {
 
   object ob;
 
   if (str == "out") {
     if (environment(this_player()) == this_object()) {
        environment()->long();
        ob = first_inventory(environment());
        while (ob)
        {
          if (ob != this_object())
            if (ob->short())
              write(capitalize(ob->short())+"\n");
          ob = next_inventory(ob);
        }
        return 1;
     }
   }
   return this_player()->look(str);
}
 
my_say(str) {
   if (environment(this_player()) == this_object()) {
     tell_room(environment(),"A voice says:"+str+"\n");
     return 1;
   }
   return;
}
 
help_mist(str)
{
    if (str == "mist")
        cat("/players/wolfi/guild/mist.tex");
    return str;
}
 
catch_tell(str)
{
   string   name,text1,text2;
 
   sscanf(str,"%s %s %s",name,text1,text2);
   if ((name != capitalize(this_player()->query_real_name())) && (name != "A" && text1 !="voice") && (name != "A" && text2 != "mist"))
     tell_object(this_player(),str);
}
 
set_color(str) {
   return color = str;
}
 
query_mist()
{
   return 1;
}

