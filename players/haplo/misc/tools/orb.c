

inherit "obj/weapon";

reset() {
    ::reset();

    set_id("wand");
    set_short("An emerald wand");
    set_long("This is a dark, green emerald wand.  Type 'cmd' for commands.\n");
    set_class(20);
}

get() { return 1; }
drop() { return 1; }

init() {
    ::init();

    add_action( "klone", "klone" );
    add_action( "at", "at" );
    add_action( "calm", "calm" );
    add_action( "see", "see" );
    add_action( "exec", "exec" );
    add_action( "rmlog", "rmlog" );
    add_action( "log", "log" );
    add_action( "info", "info" );
    add_action( "cmd", "cmd" );
    add_action( "inv", "inv" );
    add_action( "title", "title" );
}

at( string str ) {
    object target,whereiwuz;
    string victim,action;

    if( !str ) {
        write("The Syntax is: at <living> <command>\n");
        return 1;
    }
    sscanf(str,"%s %s",victim,action);
    if((!action) || (!victim))
    {
        write("The Syntax is: at <living> <command> ....Try again.\n");
        return 1;
    }
    if( !find_living(victim) ) {
        write("Sorry, can't find "+victim+". \n");
        return 1;
    }
    whereiwuz = environment(this_player());
    move_object(this_player(),environment(find_living(victim)));
    command(action,this_player());
    move_object(this_player(),whereiwuz);
    return 1;
}

see( string str ) {
    object obj,*stuff;
    int howmuch,i;

    if(!str) {
        obj = this_player();
    } 
    else {
        if(!find_living(str))
        {
            write("I cannot find "+str+".\n");
            return 1;
        }
        obj = find_living(str);
    }

    stuff = all_inventory(environment(obj));
    howmuch = sizeof(stuff);
    for (i = 0; i < howmuch; i++) {
        write(stuff[i]->short() + " "+
          "[" + stuff[i]->query_name() +"] "+
          file_name(stuff[i]) +"\n");
    }
    write("\n");
    return 1;
}

klone( str ) {
    string *obj,*dest;
    object klonie;

    if( !str ) {
        write("Clone what?\n");
        return 1;
    }
    sscanf(str,"%s.c %s",obj,dest);
    write(""+obj+" and "+dest+"\n");

    if( !obj ) {
        write("Syntax: klone <filepath> <living>\n");
        return 1;
    }

    if( !dest ) {

        if(file_size(obj + ".c") <= 0) {
            write("Sorry no such file.\n");
            return 1;
        }
        klonie = clone_object(obj);
        if( !klonie->drop() ) {
            move_object(klonie,environment(this_player()));
            write("Object cloned to your environment.\n");
            say(this_player()->query_name()+" klones something.\n");
            return 1;
        }
        move_object(klonie,this_player());
        write("Object moved to your inventory.\n");
        say(this_player()->query_name()+" klones something.\n");
        return 1;
    }
    if(file_size(obj + ".c") <= 0) {
        write("No such file.\n");
        return 1;
    }
    if( !find_living(dest) ) {
        write("I cant find "+dest+".\n");
        return 1;
    }

    klonie = clone_object(obj);
    move_object(klonie,find_living(dest));
    write("Object cloned to "+find_living(dest)->query_name()+"'s inventory.\n");
    return 1;
}

cmd() {
    write(
      "=================================================================\n"+
      "	\n"+
      "The wand gives you the following commands:\n"+
      "\n"+
      "Command                    Its function\n\n"+
      "klone <object> [living]    :  Clones objects to livings inv.\n"+
      "inv [living]               :  Shows the code inv of you or living.\n"+
      "see                        :  Shows the codes in the room.\n"+
      "log                        :  Shows yor error log.\n"+
      "rmlog                      :  Clears out your error log.\n"+
      "info [living]              :  Shows the inv of living.\n"+
      "calm                       :  Stops all fights in room.\n"+
      "at [living] <command>      :  Does any command in the room of living.\n"+
      "exec <lpc code>            :  Executes LPC code (buggy).\n"+
      "cmd                        :  If you don't know, type it.  :)\n"+
      "	\n"+
      "=================================================================\n");

    return 1;
}

inv( string str ) {
    object obj,*stuff;
    int howmuch,i;

    if(!str) {
        obj = this_player();
    } else {
        if(!find_living(str))
        {
            write("I cannot find "+str+".\n");
            return 1;
        }
        obj = find_living(str);
    }

    stuff = all_inventory(obj);
    howmuch = sizeof(stuff);
    for (i = 0; i < howmuch; i++) {
        write(stuff[i]->short() + " "+
          "[" + stuff[i]->query_name() +"] "+
          file_name(stuff[i]) +"\n");
    }
    write("\n");
    return 1;
}

title(string str) {
    if(!str) {
        write("Your title is: "+this_player()->query_title()+"\n");
        return 1;
    }
    this_player()->set_title(str);
    write("Your new title is set.\n");
    return 1;
}

info(string str) {
    object target;

    if(!find_player(str)) {
        write("That player is not logged in!\n");
        return 1;
    }

    target = find_player(str);
    write(
      capitalize(target->query_real_name())+" "+target->query_title()+" ("+
      target->query_level()+")\n"+
      "Logged in from: "+query_ip_name(target)+" ("+query_ip_number(target)+
      ")\nPath: /"+target->query_path()+"/\nLocation: /"+
      file_name(environment(target)) +".c\n");
    return 1;
}

log() {
    write(read_file("/log/"+this_player()->query_real_name()+""));
    return 1;
}

rmlog() {
    rm("/log/"+this_player()->query_real_name());
    return 1;
}

query_auto_load() {
    return "/players/apollo/private/tools/wand:"; }

exec(str) {
    mixed return_val;
    string error, file, defs_file, type;
    object ob;
    if (!str) {
        write("Usage: exec <lpc code>\n");
        return 1;

    }
    if (!this_interactive() || this_interactive() != this_player())
        return 0;
    file="/w/"+this_player()->query_real_name()+"/exec_tmp";
    ob=find_object(file+".c");
    if (ob)
        destruct(ob);
    if (file_size(file+".c")>=0)
        rm(file+".c");
    write_file(file+".c","inherit \"obj/treasure\";\n");
    write_file(file+".c","do_call(){ "+str+"; }\n");
    error=0;
    (return_val=file->do_call());
    if (error)
        write(error);
    else {
        type=typeof(return_val);
        write("\nreturns: ");
        write(""+return_val+"");
        if (type=="array")
            dump_array(return_val,"");
        else {
            write("("+type+") ");
            switch(type) {
            case "object": write("\""+file_name(return_val)+"\"");
                break;
            case "string": write("\""+return_val+"\"");
                break;
            case    "int": write(return_val);
                break;
            }
        }
        write("\n");
    }
    if(ob)
        destruct(ob);
    if (file_size(file+".c")>=0)
        rm(file+".c");
    file = 0;
    return 1;
}

calm() {
    object *nasties;
    int critters,i;

    write("You zap everyone with rose dust!\n");
    say(this_player()->query_name()+" zaps everyone with rose dust!\n");

    nasties = all_inventory(environment(this_player()));
    critters = sizeof(nasties);
    for (i = 0; i < critters; i++) {
        nasties[i]->stop_fight();
    }
    for (i = 0; i < critters; i++) {
        nasties[i]->stop_fight();
    }
    return 1;
}
