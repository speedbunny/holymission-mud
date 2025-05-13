
/* Test-object, used to get ideas for new emote&social commands, and 
   to make easier some things that otherwise would need a lot of typing.
   Not intended to be in players possession. */

inherit "/obj/treasure";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("xsoul");
    set_short("xsoul-device");
    set_value(2000);
    set_weight(0);
    set_long("Em <text> to emote <text>\n"+
             "Emm <text> to emote <yourname> <text>\n"+
             "Sscan <name> to scan someone\n"+
             "Cguild <guild-name> to change your guild.\n");
}

void init() {
    ::init();
    add_action("em","em");
    add_action("emm","emm");
    add_action("sscan","sscan");
    add_action("cguild","cguild");
}

int chk() {
    if(this_player()->query_immortal()) {
        return 1;
    }
    write("You are not allowed to use this item!\n");
    write("Normally, you it shouldn't be in your possession!\n");
    destruct(this_object());
    return 0;
}

int em(string str) {
    if(chk()) {
        say(str+"\n");
        write("You emote: "+str+"\n");
    }
    return 1;
}

int emm(string str) {
    if(chk()) {
        string str2;
        str2=capitalize(this_player()->query_name())+" "+str;
        say(str2+".\n");
        write("You emote: "+str2+".\n");
    }
    return 1;
}

sscan(string str) {
object ob,loc1,loc2;
    if(chk()) {
        ob=find_player(lower_case(str));
        loc1=environment(this_player());
        loc2=environment(ob);
        if((loc1!=loc2) || (!ob)) {
            not_found(str);
            return 1;
        }
        write("You scan "+str+" and see the next:\n");
        write(ob->query_gender_string()+" "+ob->query_race()+"\n");
        write("Hp : "+ob->query_hp()+" of "+ob->query_max_hp()+"\n");
        tell_object(ob,"Beware, "+this_player()->query_real_name()+
                   " is scanning you!\n");
        say(this_player()->query_real_name()+" gives a double-analitic "+
            "look to "+ob->query_name()+".\n");
    }
    return 1;
}

void not_found(string str) {
    write("Nobody is here with the name "+str+".\n");
    say(this_player()->query_name()+" looks confused.\n");
}

drop() {
    write("As the xsoul leaves your hands, it disintegrates.\n");
    destruct(this_object());
    return 1;
}
  
put() {
    write("As the xsoul leaves your hands, it disintegrates.\n");
    destruct(this_object());
    return 1;
}

give() {
    write("As the xsoul leaves your hands, it disintegrates.\n");
    destruct(this_object());
    return 1;
}

int cguild(string arg) {
  if(chk()) {
  this_player()->set_guild("/guild/master"->query_number(arg));
  }
  return 1;
}

int query_no_store() {return 1;}
