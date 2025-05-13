inherit "obj/monster";

string murderer, murder_weap, murder_room;
void free_all();

void init(){
    add_action("give", "give");
}

void reset(int arg){
    object sword;
    ::reset(arg);
    if(arg) return;
    set_name("Thain of the Shire");
    set_alias("thain");
    set_gender(1);
    set_alt_name("thain");
    set_race("hobbit");
    set_level(20);
    set_al(200);
    set_short("Thain");
    set_long(
      "While being short, this hobbit is amazingly sturdy. He has a very\n"+
      "stern look on his face and you can tell that he is in no mood to\n"+
      "be trifled with. He wears a girth around his waist and wears a\n"+
      "shortsword.\n");
    set_wc(17);
    set_ac(5);
    add_money(300+random(200));
    sword = clone_object("obj/weapon");
    sword->set_name("sword");
    sword->set_alias("shortsword");
    sword->set_short("Sharp shortsword");
    sword->set_class(14);
    sword->set_weight(3);
    sword->set_value(450);
    move_object(sword, this_object());
    command("wield sword");
}

void set_murderer(string str){ murderer = str; }
void set_murder_weap(string str){ murder_weap = str; }
void set_murder_room(string str){ murder_room = str; }

void set_free(object witness){
    if(!witness) return;
    call_out("free_me", 3, witness);
}

void free_me(object witness){
    int i;
    if(!environment(witness))
	return;
    tell_room(environment(witness),
      witness->query_name()+" is set free after the questioning.\n");
    for(i=1;i<4;i++)
	environment(witness)->unset_done(i);
    destruct(witness);
    return;
}

int check_item(object ob){
    if(ob->query_name()=="murderweapon") return 1;
    else
	return 0;
}

int give(string arg){
    object obj,p,warrant;
    string what, who, war_desc, runner;
    int val;
    if(!arg) return 0;
    if(sscanf(arg, "%s to %s", what, who)!=2) return 0;
    if(!id(who)) return 0;
    p=this_player();
    obj=present(what, p);
    if(!obj) return 0;
    if(transfer(obj, this_object())){
	write("You cannot do that!\n");
	return 1;
    }
    write("You give the "+obj->query_name()+" to the Thain.\n");
    say(p->query_name()+" gives a "+obj->query_name()+
      " to the Thain.\n", p);
    val=check_item(obj);
    if(!val){
	tell_room(environment(),
	  "Thain says: What would I do with that?\n");
	write("The Thain gives the item back to you.\n");
	say("He gives it back to "+p->query_name()+".\n");
	transfer(obj, p);
	return 1;
    }
    else {
	tell_room(environment(),
	  "Thain exlaims: Aha! You have found the evidence!\n");
	tell_room(environment(),
	  "Thain says: Here is an arrest warrant, bring him in!\n");
	write("The Thain hands the warrant to you.\n");
	say("The Thain hands the warrant to "+
	  p->query_name()+".\n", p);
	destruct(obj);
	warrant=clone_object("/players/colossus/mearth/shire/quest/warrant");
	war_desc=
	"The court of the Shire has ordered for the immediate arrest "+
	"of "+capitalize(environment()->query_murderer())+".\n"+
	"The carrier of this warrant, with power authorized by the court.\n"+
	"has been appointed to the fulfillment of the above task.\n\n"+
	"					Signed,\n"+
	"					Thain of the Shire\n\n";

	warrant->set_long(war_desc);
	transfer(warrant, p);
	call_out("wrap_up", 4, p);
	return 1;
    }
    return 0;
}

void wrap_up(object TP){
    object fug;
    string name;
    name=environment()->query_murderer();
    tell_room(environment(this_object()),
      "Thain says: Oh, one more last thing before you set out.\n");
    tell_room(environment(this_object()),
      "Thain says: The suspect was last seen in the forest.\n");
    environment()->set_in_progress(3);
    fug=find_living(name+" the fugitive");
    if(fug) destruct(fug);
    fug=clone_object("/players/colossus/mearth/shire/quest/fugitive");
    fug->set_name(name+" the fugitive");
    fug->set_alias(name);
    fug->set_alt_name("fugitive");
    fug->set_short(capitalize(name)+" the fugitive");
    fug->set_long(capitalize(name)+" has a very worried look.\n");
    fug->set_master(TP);
    move_object(fug, "/players/colossus/mearth/shire/forest3");
    return;
}

void lock_up(object ob, object player){
    object warrant;
    if(!player || !ob) return;
    tell_room(environment(),
      "The guards come in and drag the suspect away.\n");
    ob->set_name("Glum prisoner");
    ob->set_alias("prisoner");
    ob->set_long(
      "This prisoner is another fugitive that has been apprehended\n"+
      "by the local authorities with the help of an intelligent\n"+
      "adventurer.\n");
    warrant=present("arrest warrant", player);
    destruct(warrant);
    ob->locked_up();
    move_object(ob, "/players/colossus/mearth/shire/quest/cell"+random(2));
    call_out("lock_up2", 3, player);
}

void lock_up2(object player){

    if (!player) return;
    tell_room(environment(),
      "Thain says: Thanks for your help, "+
      capitalize(player->query_real_name())+"!\n");
    free_all();
    environment()->restart_game();
    this_player()->set_quest("Clue");
    return;
}

void free_all() {
    object wit1,wit2,wit3;
    wit1 = find_living("old gaffer");
    if (wit1) set_free(wit1);
    wit2 = find_living("little hobbit girl");
    if (wit2) set_free(wit2);
    wit3 = find_living("hobbit traveller");
    if (wit3) set_free(wit3);
} 
